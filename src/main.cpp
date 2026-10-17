/* Step 10-01 시작: 버튼 디바운싱 변화 pressed/released MQTT Publish 구현
 TODO: MQTT_BUTTON_TOPIC에 이벤트만 발행, LED 상태 MQTT 발행은 다음 단계에서 구현
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
#define WIFI_RETRY_MS 10000

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
      if (buttonState == LOW) {
        fadeEnabled = !fadeEnabled;
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
