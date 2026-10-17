#include <Arduino.h>

#define PIN_LED 25
#define PIN_BUTTON 23
unsigned long previousButtonMillis = 0;
const unsigned long BUTTON_INTERVAL = 200;
int brightness = 0;
int fadeAmount = 5;
unsigned long previousTime = 0;
const unsigned long interval = 20000;

void updateBrightness() {
  brightness += fadeAmount;
  if (brightness >= 255) {
    brightness = 255;
    fadeAmount = -5;
  } else if (brightness <= 0) {
    brightness = 0;
    fadeAmount = 5;
  }
  analogWrite(PIN_LED, brightness);
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  Serial.begin(115200);
  analogWrite(PIN_LED, brightness);
}

void loop() {
  unsigned long currentTime = micros();
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    updateBrightness();
  }
  unsigned long currentMillis = millis();
  if (currentMillis - previousButtonMillis >= BUTTON_INTERVAL) {
    previousButtonMillis = currentMillis;
    int buttonState = digitalRead(PIN_BUTTON);
    Serial.println(buttonState);
  }
}
