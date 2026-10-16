#include <Arduino.h>
#define LED_PIN 18
#define BUTTON_PIN 19
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define DIM_INTERVAL 30
#define DEBOUNCE_MS 40

int brightness = 0;
int changeAmount = 5;
unsigned long previousMillis = 0;
unsigned long lastChangeMillis = 0;
int lastReading = HIGH;
int stableButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ledcAttach(LED_PIN, PWM_FREQUENCY, PWM_RESOLUTION);
}
void loop() {
  unsigned long now = millis();
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastReading) lastChangeMillis = now;
  if (now - lastChangeMillis >= DEBOUNCE_MS && reading != stableButtonState) {
    stableButtonState = reading;
    Serial.println(stableButtonState == LOW ? "PRESSED" : "RELEASED");
  }
  lastReading = reading;
  if (now - previousMillis >= DIM_INTERVAL) {
    previousMillis = now;
    brightness += changeAmount;
    if (brightness >= 255) { brightness = 255; changeAmount = -5; }
    if (brightness <= 0) { brightness = 0; changeAmount = 5; }
    ledcWrite(LED_PIN, brightness);
  }
}
