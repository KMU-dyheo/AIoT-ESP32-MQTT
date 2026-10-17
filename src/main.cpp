/* Step 12 수업 시작: 로컬 Broker MQTT -> AWS IoT Core TLS
 TODO: 인증서, AWS endpoint, NTP 기반 시간 검증 후 TLS 8883 연결
 기존 button/state, led/state, led/set 및 로컬 버튼/LED 기능은 유지
*/
#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include "wifi_config.h"
#include <esp_wpa2.h>
#include <esp_wifi.h>
#include <cstring>
#include <ESP32MQTTClient.h>
#include "mqtt_config.h"

#define PIN_LED 25
#define PIN_BUTTON 23

int brightness = 0;
int fadeAmount = 5;
unsigned long previousTime = 0;
const unsigned long interval = 20000;
int buttonState = HIGH;
int lastReading = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long DEBOUNCE_DELAY = 30;
bool fadeEnabled = true;

unsigned long lastWifiAttempt = 0;
bool otaStarted = false;
ESP32MQTTClient mqttClient;
bool mqttStarted = false;
bool buttonStatePending = false;
const char *pendingButtonPayload = "released";
bool ledStatePending = true;
volatile int pendingLedCommand = -1;

void setupApplication();
void loopApplication();

void onLedSetMessage(const std::string &payload) {
  if (payload == "on") pendingLedCommand = 1;
  else if (payload == "off") pendingLedCommand = 0;
}

void onMqttConnect(esp_mqtt_client_handle_t client) {
  if (!mqttClient.isMyTurn(client)) return;
  Serial.println("MQTT connected");
  ledStatePending = true;
  mqttClient.subscribe(MQTT_LED_SET_TOPIC, onLedSetMessage, 0);
}

esp_err_t handleMQTT(esp_mqtt_event_handle_t event) {
  mqttClient.onEventCallback(event);
  return ESP_OK;
}

void serviceMqtt() {
  if (WiFi.status() != WL_CONNECTED) return;
  if (!mqttStarted) mqttStarted = mqttClient.loopStart();
  if (pendingLedCommand != -1) {
    int command = pendingLedCommand;
    pendingLedCommand = -1;
    fadeEnabled = command == 1;
    if (!fadeEnabled) analogWrite(PIN_LED, 0);
    ledStatePending = true;
  }
  if (!mqttClient.isConnected()) return;
  if (buttonStatePending) {
    if (mqttClient.publish(MQTT_BUTTON_TOPIC, pendingButtonPayload, 0, false)) {
      buttonStatePending = false;
    }
  }
  if (ledStatePending) {
    if (mqttClient.publish(MQTT_LED_STATE_TOPIC, fadeEnabled ? "on" : "off", 0, true)) {
      ledStatePending = false;
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
void updateBrightness() {
  brightness += fadeAmount;
  if (brightness >= 255) {
    brightness = 255;
    fadeAmount = -5;
  } else if (brightness <= 0) {
    brightness = 0;
    fadeAmount = 5;
  }
  analogWrite(PIN_LED, brightness);
}

void updateButton() {
  int reading = digitalRead(PIN_BUTTON);
  if (reading != lastReading) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime >= DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;
      Serial.println(buttonState);
      pendingButtonPayload = buttonState == LOW ? "pressed" : "released";
      buttonStatePending = true;
      if (buttonState == LOW) {
        fadeEnabled = !fadeEnabled;
        ledStatePending = true;
        if (!fadeEnabled) {
          analogWrite(PIN_LED, 0);
        }
      }
    }
  }
  lastReading = reading;
}

void setupApplication() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  Serial.begin(115200);
  analogWrite(PIN_LED, brightness);
}

void loopApplication() {
  unsigned long currentTime = micros();
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    if (fadeEnabled) {
      updateBrightness();
    }
  }
  updateButton();
}
