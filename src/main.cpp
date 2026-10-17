/* Step 06 시작 코드
 TODO 1: 버튼 읽기에서 delay 제거
 TODO 2: millis()로 버튼 디바운싱 구현
 아래는 이전 Step의 완성 코드. 이번 단계 기능을 직접 구현한다.
*/
#include <Arduino.h>
#define LED_PIN 18
#define BUTTON_PIN 19
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0
#define DIM_INTERVAL 30

int brightness = 0;
int changeAmount = 5;
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);
}
void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState == LOW ? "PRESSED" : "RELEASED");
  delay(100);
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= DIM_INTERVAL) {
    previousMillis = currentMillis;
    brightness += changeAmount;
    if (brightness >= 255) { brightness = 255; changeAmount = -5; }
    if (brightness <= 0) { brightness = 0; changeAmount = 5; }
    ledcWrite(PWM_CHANNEL, brightness);
  }
}
