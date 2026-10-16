#include <Arduino.h>
#define LED_PIN 18
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8

void setup() {
  ledcAttach(LED_PIN, PWM_FREQUENCY, PWM_RESOLUTION);
}
void loop() {
  for (int brightness = 0; brightness <= 255; brightness += 5) {
    ledcWrite(LED_PIN, brightness);
    delay(30);
  }
  for (int brightness = 255; brightness >= 0; brightness -= 5) {
    ledcWrite(LED_PIN, brightness);
    delay(30);
  }
}
