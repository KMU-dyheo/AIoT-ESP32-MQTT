# Step 01 — ESP32 내장 LED 점멸

## 학습 목표
- ESP32 내장 LED에 연결된 GPIO 2를 출력으로 사용합니다.
- `setup()`에서 LED 출력 핀을 초기화합니다.
- `loop()`에서 500ms 간격으로 LED를 켜고 끕니다.

## 단계별 실습
| 순서 | 시작 브랜치 | 완성 브랜치 | 구현할 내용 |
|---|---|---|---|
| 01-01 | `step-01-01-led-output` | `step-01-01-led-output-done` | `#define LED 2`, `pinMode(LED, OUTPUT)` |
| 01-02 | `step-01-02-led-blink` | `step-01-02-led-blink-done` | `delay(500)`, `digitalWrite(LED, HIGH/LOW)` |

전체 단계의 시작 브랜치는 `step-01-onboard-led`, 완성 브랜치는 `step-01-onboard-led-done`입니다.

## 실습 순서
1. ESP32 DevKit V1을 USB 케이블로 연결합니다.
2. `platformio.ini`에서 `board = esp32doit-devkit-v1`을 확인합니다.
3. 첫 서브스텝에서 출력 핀을 설정합니다.
4. 다음 서브스텝에서 `loop()`의 LED 점멸 코드를 작성합니다.
5. `pio run -e esp32dev_usb`로 빌드하고 업로드합니다.
6. 내장 LED가 약 0.5초마다 켜졌다 꺼지는지 확인합니다.

## 학습한 코드
```cpp
#include <Arduino.h>
#define LED 2

void setup() {
    pinMode(LED, OUTPUT);
}

void loop() {
    delay(500);
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
}
```

> 보드에 따라 내장 LED의 위치나 연결 여부가 다를 수 있습니다.
