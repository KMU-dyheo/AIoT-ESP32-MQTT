/* Step 08 시작 코드
 TODO 1: setupApplication() / loopApplication()으로 LED/버튼 분리
 TODO 2: 개인용·기업용 Wi-Fi 연결, 재연결 및 ArduinoOTA 처리
 아래는 이전 Step의 완성 코드. 이번 단계 기능을 직접 구현한다.
*/
#include <Arduino.h>
#define LED_PIN 18
#define BUTTON_PIN 19
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0
#define DIM_INTERVAL 30
#define DEBOUNCE_MS 40

int brightness = 0;
int changeAmount = 5;
bool ledEnabled = true;
unsigned long previousMillis = 0;
unsigned long lastChangeMillis = 0;
int lastReading = HIGH;
int stableButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);
}
void loop() {
  unsigned long now = millis();
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastReading) lastChangeMillis = now;
  if (now - lastChangeMillis >= DEBOUNCE_MS && reading != stableButtonState) {
    stableButtonState = reading;
    if (stableButtonState == LOW) {
      ledEnabled = !ledEnabled;
      Serial.println(ledEnabled ? "LED ENABLED" : "LED DISABLED");
    }
  }
  lastReading = reading;
  if (now - previousMillis >= DIM_INTERVAL) {
    previousMillis = now;
    brightness += changeAmount;
    if (brightness >= 255) { brightness = 255; changeAmount = -5; }
    if (brightness <= 0) { brightness = 0; changeAmount = 5; }
    ledcWrite(PWM_CHANNEL, ledEnabled ? brightness : 0);
  }
}
