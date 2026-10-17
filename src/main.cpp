#include <Arduino.h>
#define LED_PIN 25
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0

void setup() {
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);
}
void loop() {
  for (int brightness = 0; brightness <= 255; brightness += 5) {
    ledcWrite(PWM_CHANNEL, brightness);
    delay(30);
  }
  for (int brightness = 255; brightness >= 0; brightness -= 5) {
    ledcWrite(PWM_CHANNEL, brightness);
    delay(30);
  }
}
