#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include "wifi_config.h"
#include <esp_wpa2.h>
#include <esp_wifi.h>
#include <cstring>
#include <ESP32MQTTClient.h>
#include "mqtt_config.h"

#define LED_PIN 25
#define BUTTON_PIN 23
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0
#define DIM_INTERVAL 30
#define DEBOUNCE_MS 40
#define WIFI_RETRY_MS 10000

int brightness = 0;
int fadeAmount = 5;
unsigned long lastBrightnessMs = 0;
int lastReading = HIGH;
int stableButtonState = HIGH;
bool ledEnabled = true;
unsigned long lastButtonChangeMs = 0;

unsigned long lastWifiAttempt = 0;
bool otaStarted = false;
ESP32MQTTClient mqttClient;
bool mqttStarted = false;
bool buttonStatePending = false;
const char *pendingButtonPayload = "released";

void setupApplication();
void loopApplication();

void onMqttConnect(esp_mqtt_client_handle_t client) {
  if (!mqttClient.isMyTurn(client)) return;
  Serial.println("MQTT connected");
}

esp_err_t handleMQTT(esp_mqtt_event_handle_t event) {
  mqttClient.onEventCallback(event);
  return ESP_OK;
}

void serviceMqtt() {
  if (WiFi.status() != WL_CONNECTED) return;
  if (!mqttStarted) mqttStarted = mqttClient.loopStart();
  if (!mqttClient.isConnected()) return;
  if (buttonStatePending) {
    if (mqttClient.publish(MQTT_BUTTON_TOPIC, pendingButtonPayload, 0, false)) {
      buttonStatePending = false;
    }
  }
}

void connectWifi() {
  if (WiFi.status() == WL_CONNECTED) return;
  WiFi.disconnect();
#if WIFI_ENTERPRISE
  // WPA2-Enterprise (PEAP) configuration is board/core-specific.
  // ESP32 Arduino Core 2.x: WPA2-Enterprise (PEAP) API.
  // Configure credentials before WiFi.begin().
  esp_wifi_sta_wpa2_ent_set_identity((const unsigned char*)EAP_IDENTITY, strlen(EAP_IDENTITY));
  esp_wifi_sta_wpa2_ent_set_username((const unsigned char*)EAP_USERNAME, strlen(EAP_USERNAME));
  esp_wifi_sta_wpa2_ent_set_password((const unsigned char*)EAP_PASSWORD, strlen(EAP_PASSWORD));
  esp_wifi_sta_wpa2_ent_enable();
  WiFi.begin(WIFI_SSID);
#else
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
#endif
  lastWifiAttempt = millis();
}
void setup() {
  Serial.begin(115200);
  setupApplication();
  mqttClient.setURL(MQTT_HOST, MQTT_PORT);
  mqttClient.setMqttClientName(MQTT_CLIENT_ID);
  WiFi.mode(WIFI_STA);
  connectWifi();
}
void loop() {
  loopApplication();
  serviceMqtt();
  if (WiFi.status() == WL_CONNECTED) {
    if (!otaStarted) {
      ArduinoOTA.setHostname(OTA_HOSTNAME);
      ArduinoOTA.setPassword(OTA_PASSWORD);
      ArduinoOTA.begin();
      otaStarted = true;
      Serial.println(WiFi.localIP());
    }
    ArduinoOTA.handle();
  } else {
    otaStarted = false;
    if (millis() - lastWifiAttempt >= WIFI_RETRY_MS) connectWifi();
  }
}
void updateButton() {
  unsigned long now = millis();
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastReading) lastButtonChangeMs = now;
  if (now - lastButtonChangeMs >= DEBOUNCE_MS && reading != stableButtonState) {
    stableButtonState = reading;
    Serial.println(stableButtonState == LOW ? "pressed" : "released");
    pendingButtonPayload = stableButtonState == LOW ? "pressed" : "released";
    buttonStatePending = true;
    if (stableButtonState == LOW) {
      ledEnabled = !ledEnabled;
      Serial.println(ledEnabled ? "LED on" : "LED off");
    }
  }
  lastReading = reading;
}

void updateBrightness() {
  unsigned long now = millis();
  if (now - lastBrightnessMs < DIM_INTERVAL) return;
  lastBrightnessMs = now;
  brightness += fadeAmount;
  if (brightness >= 255) { brightness = 255; fadeAmount = -5; }
  if (brightness <= 0) { brightness = 0; fadeAmount = 5; }
  ledcWrite(PWM_CHANNEL, ledEnabled ? brightness : 0);
}

void setupApplication() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);
}

void loopApplication() {
  updateButton();
  updateBrightness();
}
