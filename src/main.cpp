#include <Arduino.h>
#define PIN_LED 25
int brightness = 0;
int fadeAmount = 1;
int fadeInterval = 500;
void setup() { pinMode(PIN_LED, OUTPUT); }
void loop() {
  analogWrite(PIN_LED, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 250) fadeAmount = -fadeAmount;
  delayMicroseconds(fadeInterval);
}
