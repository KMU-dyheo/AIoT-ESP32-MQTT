#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include "wifi_config.h"
#include <esp_eap_client.h>
#include <esp_wifi.h>
#include <cstring>
#include <PubSubClient.h>
#include "mqtt_config.h"

#define LED_PIN 18
#define BUTTON_PIN 19
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define DIM_INTERVAL 30
#define DEBOUNCE_MS 40
#define WIFI_RETRY_MS 10000

int brightness = 0;
int changeAmount = 5;
bool ledEnabled = true;
unsigned long previousMillis = 0;
unsigned long lastChangeMillis = 0;
int lastReading = HIGH;
int stableButtonState = HIGH;
unsigned long lastWifiAttempt = 0;
bool otaStarted = false;
WiFiClient mqttNetwork;
PubSubClient mqtt(mqttNetwork);
unsigned long lastMqttAttempt = 0;

void setupApplication();
void handleMqttMessage(char* topic, byte* payload, unsigned int length) {
  // Step 11에서 LED 원격 제어 구현
}
void serviceMqtt() {
  if (WiFi.status() != WL_CONNECTED) return;
  if (!mqtt.connected() && millis() - lastMqttAttempt >= 5000) {
    lastMqttAttempt = millis();
    mqtt.connect(MQTT_CLIENT_ID);
  }
  if (mqtt.connected()) mqtt.loop();
}

void loopApplication();

void connectWifi() {
  if (WiFi.status() == WL_CONNECTED) return;
  WiFi.disconnect();
#if WIFI_ENTERPRISE
  // WPA2-Enterprise (PEAP) configuration is board/core-specific.
  // ESP32 Arduino Core 3.x: esp_eap_client API.
  // Configure credentials before WiFi.begin().
  esp_eap_client_set_identity((const unsigned char*)EAP_IDENTITY, strlen(EAP_IDENTITY));
  esp_eap_client_set_username((const unsigned char*)EAP_USERNAME, strlen(EAP_USERNAME));
  esp_eap_client_set_password((const unsigned char*)EAP_PASSWORD, strlen(EAP_PASSWORD));
  esp_eap_client_enable();
  WiFi.begin(WIFI_SSID);
#else
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
#endif
  lastWifiAttempt = millis();
}
void setup() {
  Serial.begin(115200);
  setupApplication();
  mqtt.setServer(MQTT_HOST, MQTT_PORT);
  mqtt.setCallback(handleMqttMessage);
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
void setupApplication() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ledcAttach(LED_PIN, PWM_FREQUENCY, PWM_RESOLUTION);
}
void loopApplication() {
  unsigned long now = millis();
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastReading) lastChangeMillis = now;
  if (now - lastChangeMillis >= DEBOUNCE_MS && reading != stableButtonState) {
    stableButtonState = reading;
    if (stableButtonState == LOW) {
      ledEnabled = !ledEnabled;
      Serial.println(ledEnabled ? "LED ENABLED" : "LED DISABLED");
    }
  }
  lastReading = reading;
  if (now - previousMillis >= DIM_INTERVAL) {
    previousMillis = now;
    brightness += changeAmount;
    if (brightness >= 255) { brightness = 255; changeAmount = -5; }
    if (brightness <= 0) { brightness = 0; changeAmount = 5; }
    ledcWrite(LED_PIN, ledEnabled ? brightness : 0);
  }
}
