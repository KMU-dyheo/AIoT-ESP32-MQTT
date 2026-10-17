#include <Arduino.h>
#define PIN_LED 25

int brightness = 0;
int fadeAmount = 5;
int fadeInterval = 5000;
unsigned long previousTime = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  unsigned long now = micros();
  analogWrite(PIN_LED, brightness);
  if (now - previousTime > fadeInterval) {
    previousTime = now;
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 250) {
      fadeAmount = -fadeAmount;
    }
  }
}
