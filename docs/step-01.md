# Step 01 — 시리얼 모니터와 내장 LED

2주차 강의노트의 시리얼 모니터 실습(20~22쪽)과 내장 LED 예제(70쪽)를 순서대로 진행합니다.

| 순서 | 실습 | 시작 브랜치 | 완료 브랜치 |
|---|---|---|---|
| 01-01 | 시리얼 출력 | `step-01-01-serial` | `step-01-01-serial-done` |
| 01-02 | LED 출력 핀 설정 | `step-01-02-led-output` | `step-01-02-led-output-done` |
| 01-03 | 내장 LED 500ms 점멸 | `step-01-03-led-blink` | `step-01-03-led-blink-done` |

시리얼 출력과 내장 LED는 강의노트의 서로 다른 예제입니다. LED 실습에서는 LED 코드로 전환하며, 앞서 배운 시리얼 예제의 반복 출력 코드를 억지로 합치지 않습니다.

## 실습 전 준비
- ESP32 DOIT DevKit V1을 USB로 연결합니다.
- `platformio.ini`에서 `board = esp32doit-devkit-v1`, `default_envs = esp32dev_usb`을 확인합니다.
- 빌드: `pio run -e esp32dev_usb`; 모니터: `pio device monitor -b 115200`.

## 완료 코드
- `step-01-onboard-led`: LED 실습 시작 코드
- `step-01-onboard-led-done`: 70쪽의 내장 LED 예제 완료 코드
- LED GPIO 번호는 `#define LED 2`입니다.
- `setup()`, `loop()`만 사용합니다. Wi-Fi/OTA와 애플리케이션 분리 함수는 사용하지 않습니다.
