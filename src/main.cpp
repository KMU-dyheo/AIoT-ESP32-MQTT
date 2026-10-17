#include <Arduino.h>
#define PIN_LED 25
int t = 0;
int count = 0;
unsigned long sum = 0;
void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  int now = micros();
  sum += now - t;
  t = now;
  count += 1;
  if (count > 100) {
    Serial.print("Time Diff:");
    Serial.println(sum / (float)count);
    count = 0;
    sum = 0;
  }
}
