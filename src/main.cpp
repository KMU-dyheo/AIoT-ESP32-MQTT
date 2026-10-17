/* Step 03 시작 코드
 TODO 1: digitalWrite 점멸을 PWM 출력으로 바꾸기
 TODO 2: 밝기 0~255 상승/하강을 delay로 구현
 아래는 이전 Step의 완성 코드. 이번 단계 기능을 직접 구현한다.
*/
#include <Arduino.h>
#define LED_PIN 18

void setup() {
  pinMode(LED_PIN, OUTPUT);
}
void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
