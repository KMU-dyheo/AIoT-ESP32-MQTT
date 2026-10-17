/* Step 04 시작 코드
 TODO 1: PWM 밝기 조절에서 delay 제거
 TODO 2: millis()와 이전 시간 비교로 주기 처리
 아래는 이전 Step의 완성 코드. 이번 단계 기능을 직접 구현한다.
*/
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
