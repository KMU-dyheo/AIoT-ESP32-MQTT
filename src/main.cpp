/* Step 05 수업 시작
TODO: GPIO23 입력을 INPUT_PULLUP으로 읽고 버튼 변화를 시리얼 출력
기존 LED Fade 기능을 유지하며 updateButton()과 updateBrightness()를 분리해 구현합니다.
*/
#include <Arduino.h>
#define LED_PIN 25
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0
#define DIM_INTERVAL 30

int brightness = 0;
int changeAmount = 5;
unsigned long previousMillis = 0;

void setup() {
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);
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
    ledcWrite(PWM_CHANNEL, brightness);
  }
}
