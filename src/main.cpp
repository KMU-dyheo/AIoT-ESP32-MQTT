#include <Arduino.h>
#include <WiFi.h>
#define PIN_LED 25
#define PIN_BUTTON 23

int brightness = 0;
int fadeAmount = 5;
unsigned long previousTime = 0;
const unsigned long interval = 20000;
int buttonState = HIGH;
int lastReading = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long DEBOUNCE_DELAY = 30;
bool fadeEnabled = true;

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

void updateButton() {
  int reading = digitalRead(PIN_BUTTON);
  if (reading != lastReading) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime >= DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;
      Serial.println(buttonState);
      if (buttonState == LOW) {
        fadeEnabled = !fadeEnabled;
        if (!fadeEnabled) {
          analogWrite(PIN_LED, 0);
        }
      }
    }
  }
  lastReading = reading;
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
    if (fadeEnabled) {
      updateBrightness();
    }
  }
  updateButton();
}
