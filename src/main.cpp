#include <Arduino.h>

// Step 01: ESP32 보드의 내장 LED를 점멸한다.
// 보드에 따라 내장 LED가 없거나 핀 번호가 다를 수 있다.
namespace Config {
constexpr uint8_t LED_PIN = 2;
constexpr unsigned long BLINK_INTERVAL_MS = 500;
}

void setup() {
  Serial.begin(115200);
  pinMode(Config::LED_PIN, OUTPUT);
  digitalWrite(Config::LED_PIN, LOW);
}

void loop() {
  static unsigned long previousMs = 0;
  static bool ledOn = false;
  const unsigned long now = millis();

  if (now - previousMs >= Config::BLINK_INTERVAL_MS) {
    previousMs = now;
    ledOn = !ledOn;
    digitalWrite(Config::LED_PIN, ledOn ? HIGH : LOW);
    Serial.printf("Onboard LED: %s\n", ledOn ? "ON" : "OFF");
  }
}
