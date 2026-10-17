// TODO: 강의노트 순서대로 이번 시간 간격 처리 방식만 변경합니다.
#include <Arduino.h>
#define PIN_LED 25
int brightness = 0;
int fadeAmount = 1;
int fadeInterval = 1;
void setup() { pinMode(PIN_LED, OUTPUT); }
void loop() {
  analogWrite(PIN_LED, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 250) fadeAmount = -fadeAmount;
  delay(fadeInterval);
}
