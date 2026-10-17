#include <Arduino.h>

#define LED_PIN 25
#define BUTTON_PIN 23
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0
#define DIM_INTERVAL 30
#define DEBOUNCE_MS 40

int brightness = 0;
int fadeAmount = 5;
unsigned long lastBrightnessMs = 0;
int lastReading = HIGH;
int stableButtonState = HIGH;
unsigned long lastButtonChangeMs = 0;

void updateButton() {
  unsigned long now = millis();
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastReading) lastButtonChangeMs = now;
  if (now - lastButtonChangeMs >= DEBOUNCE_MS && reading != stableButtonState) {
    stableButtonState = reading;
    Serial.println(stableButtonState == LOW ? "pressed" : "released");
  }
  lastReading = reading;
}

void updateBrightness() {
  unsigned long now = millis();
  if (now - lastBrightnessMs < DIM_INTERVAL) return;
  lastBrightnessMs = now;
  brightness += fadeAmount;
  if (brightness >= 255) { brightness = 255; fadeAmount = -5; }
  if (brightness <= 0) { brightness = 0; fadeAmount = 5; }
  ledcWrite(PWM_CHANNEL, brightness);
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(LED_PIN, PWM_CHANNEL);
}

void loop() {
  updateButton();
  updateBrightness();
}
