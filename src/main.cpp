/* Step 05 시작 코드
 TODO 1: GPIO19에 버튼을 연결하고 INPUT_PULLUP 설정
 TODO 2: digitalRead 값을 시리얼 모니터에 출력
 아래는 이전 Step의 완성 코드. 이번 단계 기능을 직접 구현한다.
*/
#include <Arduino.h>
#define LED_PIN 18
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
