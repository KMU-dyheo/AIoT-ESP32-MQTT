#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include "wifi_config.h"
#include <esp_wpa2.h>
#include <esp_wifi.h>
#include <cstring>
#include <ESP32MQTTClient.h>
#include <ArduinoJson.h>

#include <time.h>
#include "aws_certificates.h"
#include "mqtt_config.h"

#define LED_PIN 18
#define BUTTON_PIN 19
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0
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
bool buttonEventPending = false;
bool ledStatePending = true;
ESP32MQTTClient mqttClient;
bool mqttStarted = false;
volatile int mqttLedCommand = -1;

void setupApplication();
void loopApplication();

// ESP32MQTTClient의 이벤트 태스크에서는 명령만 기록
void onLedCommand(const std::string &payload) {
  if (payload == "ON") { mqttLedCommand = 1; return; }
  if (payload == "OFF") { mqttLedCommand = 0; return; }

  JsonDocument command;
  DeserializationError error = deserializeJson(command, payload.c_str());
  if (error) return;
  const char *state = command["state"];
  if (state == nullptr) return;

  if (strcmp(state, "ON") == 0) mqttLedCommand = 1;
  if (strcmp(state, "OFF") == 0) mqttLedCommand = 0;
}

void onMqttConnect(esp_mqtt_client_handle_t client) {
  if (!mqttClient.isMyTurn(client)) return;
  Serial.println("MQTT connected");
  mqttClient.subscribe(MQTT_LED_SET_TOPIC, onLedCommand, 0);
}

esp_err_t handleMQTT(esp_mqtt_event_handle_t event) {
  mqttClient.onEventCallback(event);
  return ESP_OK;
}

void serviceMqtt() {
  if (WiFi.status() != WL_CONNECTED) return;
  if (time(nullptr) < 1700000000) return;
  if (!mqttStarted) {
    mqttStarted = mqttClient.loopStart();
  }
  if (mqttLedCommand != -1) {
    ledEnabled = mqttLedCommand == 1;
    mqttLedCommand = -1;
    ledStatePending = true;
  }
  if (mqttClient.isConnected()) {
    if (buttonEventPending && mqttClient.publish(MQTT_BUTTON_TOPIC, "PRESSED", 0, false)) buttonEventPending = false;
    if (ledStatePending) {
      JsonDocument state;
      state["device"] = MQTT_CLIENT_ID;
      state["led"] = ledEnabled ? "ON" : "OFF";
      state["brightness"] = ledEnabled ? brightness : 0;
      state["uptime_ms"] = millis();
      String json;
      serializeJson(state, json);
      if (mqttClient.publish(MQTT_LED_STATE_TOPIC, json.c_str(), 0, true)) {
        ledStatePending = false;
      }
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
  mqttClient.setURL(AWS_IOT_ENDPOINT, 8883);
  mqttClient.setMqttClientName(MQTT_CLIENT_ID);
  mqttClient.setCaCert(AWS_ROOT_CA);
  mqttClient.setClientCert(AWS_DEVICE_CERT);
  mqttClient.setKey(AWS_PRIVATE_KEY);
  configTime(0, 0, "pool.ntp.org", "time.google.com");
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
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);
}
void loopApplication() {
  unsigned long now = millis();
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastReading) lastChangeMillis = now;
  if (now - lastChangeMillis >= DEBOUNCE_MS && reading != stableButtonState) {
    stableButtonState = reading;
    if (stableButtonState == LOW) {
      ledEnabled = !ledEnabled;
      buttonEventPending = true;
      ledStatePending = true;
      Serial.println(ledEnabled ? "LED ENABLED" : "LED DISABLED");
    }
  }
  lastReading = reading;
  if (now - previousMillis >= DIM_INTERVAL) {
    previousMillis = now;
    brightness += changeAmount;
    if (brightness >= 255) { brightness = 255; changeAmount = -5; }
    if (brightness <= 0) { brightness = 0; changeAmount = 5; }
    ledcWrite(PWM_CHANNEL, ledEnabled ? brightness : 0);
  }
}
