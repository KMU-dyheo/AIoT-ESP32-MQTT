#include <Arduino.h>

#define PIN_LED 25

int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  analogWrite(PIN_LED, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}
