#include <Arduino.h>

// Step 01: ESP32 내장 LED 켜고 끄기
// 보드에 따라 내장 LED 핀이 다르거나 LED가 없을 수 있음
#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED 켜기
  delay(1000);                 // 1초 기다리기

  digitalWrite(LED_PIN, LOW);   // LED 끄기
  delay(1000);                 // 1초 기다리기
}
