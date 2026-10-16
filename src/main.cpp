#include <Arduino.h>
#define LED_PIN 18
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define DIM_INTERVAL 30

int brightness = 0;
int changeAmount = 5;
unsigned long previousMillis = 0;

void setup() {
  ledcAttach(LED_PIN, PWM_FREQUENCY, PWM_RESOLUTION);
}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= DIM_INTERVAL) {
    previousMillis = currentMillis;
    brightness += changeAmount;
    if (brightness >= 255) {
      brightness = 255;
      changeAmount = -5;
    }
    if (brightness <= 0) {
      brightness = 0;
      changeAmount = 5;
    }
    ledcWrite(LED_PIN, brightness);
  }
}
