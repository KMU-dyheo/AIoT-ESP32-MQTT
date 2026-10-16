#include <Arduino.h>

// Step 01: ESP32 onboard LED control.
// Set this pin to the LED GPIO of your actual board.
// Some ESP32 DevKit boards have no onboard user LED.
namespace Config {
constexpr uint8_t LED_PIN = 2;
constexpr unsigned long BLINK_INTERVAL_MS = 500;
}

void setupApplication();
void loopApplication();

void setup() {
  Serial.begin(115200);
  setupApplication();
}

void loop() {
  loopApplication();
}

void setupApplication() {
  pinMode(Config::LED_PIN, OUTPUT);
  digitalWrite(Config::LED_PIN, LOW);
}

void loopApplication() {
  static unsigned long previousMs = 0;
  static bool ledOn = false;
  const unsigned long now = millis();
  if (now - previousMs >= Config::BLINK_INTERVAL_MS) {
    previousMs = now;
    ledOn = !ledOn;
    digitalWrite(Config::LED_PIN, ledOn ? HIGH : LOW);
    Serial.printf("Onboard LED: %s\n", ledOn ? "ON" : "OFF");
  }
}
