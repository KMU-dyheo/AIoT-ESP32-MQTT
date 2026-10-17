#include <Arduino.h>
#define PIN_LED 25
int brightness = 0;
int fadeAmount = 5;
unsigned long previousTime = 0;
const unsigned long interval = 20000;
void setup() { pinMode(PIN_LED, OUTPUT); }
void loop() {
  unsigned long currentTime = micros();
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    analogWrite(PIN_LED, brightness);
    brightness += fadeAmount;
    if (brightness >= 255 || brightness <= 0) fadeAmount = -fadeAmount;
  }
}
