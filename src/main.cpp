#include <Arduino.h>

// Step 01: ESP32 내장 LED 켜고 끄기
// 보드에 따라 내장 LED 핀이 다르거나 LED가 없을 수 있음
int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);  // LED 켜기
  delay(1000);                 // 1초 기다리기

  digitalWrite(ledPin, LOW);   // LED 끄기
  delay(1000);                 // 1초 기다리기
}
