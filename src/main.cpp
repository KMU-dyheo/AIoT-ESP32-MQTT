#include <Arduino.h>

#define PIN_LED 25

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(PIN_LED, HIGH);
  delay(500);
  digitalWrite(PIN_LED, LOW);
}
