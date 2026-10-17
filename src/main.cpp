// 이번 실습: analogWrite 밝기 변경과 간격을 직접 구현합니다.
// TODO: 강의노트의 brightness, fadeAmount, delay 코드를 적용합니다.
#include <Arduino.h>
#define PIN_LED 25
int brightness = 0;
int fadeAmount = 5;
void setup() { pinMode(PIN_LED, OUTPUT); }
void loop() {
  analogWrite(PIN_LED, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) fadeAmount = -fadeAmount;
  delay(30);
}
