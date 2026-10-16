# Step 01 — ESP32 내장 LED 제어

## 목표
내장 LED를 GPIO 출력으로 제어하고 0.5초마다 상태를 전환합니다.

## 준비
- ESP32 DevKit, USB 케이블
- VS Code + PlatformIO

## 실습
1. `platformio.ini`에서 보드 종류를 확인합니다.
2. `src/main.cpp`의 `Config::LED_PIN`을 실제 보드의 내장 LED GPIO로 수정합니다.
3. PlatformIO Upload 후 Serial Monitor(115200)를 엽니다.
4. LED가 0.5초 간격으로 ON/OFF되고 상태 로그가 출력되는지 확인합니다.

> ESP32 보드에 따라 내장 사용자 LED가 없거나 GPIO 2가 아닐 수 있습니다.

## 질문
- `pinMode()`와 `digitalWrite()`는 각각 어떤 역할을 하나요?
- `millis()`를 사용하면 `delay()`와 무엇이 다른가요?
