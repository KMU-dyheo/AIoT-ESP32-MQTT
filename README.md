# AIoT ESP32 단계별 실습

ESP32 DOIT DevKit V1 · PlatformIO · Arduino.

강의 순서에 따라 `setup()`과 `loop()`에서 시작하여, LED 출력·PWM·버튼 입력을 차례로 실습합니다.

## 브랜치
- `step-...`: 수업 시작 코드
- `step-...-done`: 해당 실습 완료 코드
- 이전 실습의 완료 코드를 다음 실습의 시작 코드로 사용합니다.

## 실습 순서

| 단계 | 실습 | 시작 브랜치 | 완료 브랜치 |
|---|---|---|---|
| 01-01 | [시리얼 모니터](docs/step-01-01.md) | `step-01-01-serial` | `step-01-01-serial-done` |
| 02-01 | [외부 LED 점멸](docs/step-02-01.md) | `step-02-01-led-blink` | `step-02-01-led-blink-done` |
| 02-02 | [1초 점등 후 5회 점멸](docs/step-02-02.md) | `step-02-02-five-blinks` | `step-02-02-five-blinks-done` |
| 03-01 | [analogWrite Fade](docs/step-03-01.md) | `step-03-01-pwm-fade` | `step-03-01-pwm-fade-done` |
| 03-02 | [밝기 변경 속도](docs/step-03-02.md) | `step-03-02-fade-speed` | `step-03-02-fade-speed-done` |
| 03-03 | [fadeInterval 변수](docs/step-03-03.md) | `step-03-03-fade-interval` | `step-03-03-fade-interval-done` |
| 03-04 | [마이크로초 Fade](docs/step-03-04.md) | `step-03-04-microseconds` | `step-03-04-microseconds-done` |
| 04-01 | [loop 재진입 시간 측정](docs/step-04-01.md) | `step-04-01-loop-timing` | `step-04-01-loop-timing-done` |
| 04-02 | [micros 기반 비차단 Fade](docs/step-04-02.md) | `step-04-02-micros-fade` | `step-04-02-micros-fade-done` |
| 04-03 | [updateBrightness() 추출](docs/step-04-03.md) | `step-04-03-brightness-function` | `step-04-03-brightness-function-done` |
| 05-01 | [GPIO23 버튼 읽기](docs/step-05-01.md) | `step-05-01-button-raw` | `step-05-01-button-raw-done` |
| 05-02 | [200ms 버튼 상태 출력](docs/step-05-02.md) | `step-05-02-button-interval` | `step-05-02-button-interval-done` |
| 05-03 | [버튼 상태 변화 감지](docs/step-05-03.md) | `step-05-03-button-change` | `step-05-03-button-change-done` |
| 06-01 | [30ms 버튼 디바운싱](docs/step-06-01.md) | `step-06-01-debounce-30ms` | `step-06-01-debounce-30ms-done` |
| 07-01 | [버튼으로 LED Fade 토글](docs/step-07-01.md) | `step-07-01-fade-toggle` | `step-07-01-fade-toggle-done` |
| 07-02 | [외부 Pull-down](docs/step-07-02.md) | `step-07-02-external-pulldown` | `step-07-02-external-pulldown-done` |
| 07-03 | [내부 Pull-down](docs/step-07-03.md) | `step-07-03-internal-pulldown` | `step-07-03-internal-pulldown-done` |
| 07-04 | [내부 Pull-up](docs/step-07-04.md) | `step-07-04-internal-pullup` | `step-07-04-internal-pullup-done` |
| 07-05 | [updateButton() 함수 분리](docs/step-07-05.md) | `step-07-05-button-function` | `step-07-05-button-function-done` |
| 08-01 | [Wi-Fi 라이브러리 설정](docs/step-08-01.md) | `step-08-01-wifi-library` | `step-08-01-wifi-library-done` |
| 08-02 | [애플리케이션 코드 분리](docs/step-08-02.md) | `step-08-02-application-split` | `step-08-02-application-split-done` |
| 08-03 | [setup/loop Wi-Fi 호출 위치 준비](docs/step-08-03.md) | `step-08-03-wifi-structure` | `step-08-03-wifi-structure-done` |
| 08-04 | [Wi-Fi 연결](docs/step-08-04.md) | `step-08-04-wifi-connect` | `step-08-04-wifi-connect-done` |
| 08-05 | [OTA 업로드 준비](docs/step-08-05.md) | `step-08-05-ota` | `step-08-05-ota-done` |

## 환경
- 보드: `esp32doit-devkit-v1`
- CPU: 240MHz
- 기본 업로드: `pio run -e esp32usb`
- 2·3·5주차 로컬 실습에서는 `setup()`, `loop()`를 사용합니다.
- Wi-Fi 실습 Step 08-02에서 처음 `setupApplication()`, `loopApplication()`을 도입합니다.
- LED: GPIO25와 220~330Ω 저항, 버튼: GPIO23
- 버튼 회로는 외부 Pull-up → 외부 Pull-down → 내부 Pull-down → 내부 Pull-up 순서로 실습합니다.

## Wi-Fi 및 MQTT
Wi-Fi 실습은 라이브러리 설정 → 애플리케이션 함수 분리 → Wi-Fi 처리 코드 준비 → Wi-Fi 연결 → OTA 순서로 진행합니다. MQTT 메시지 전송과 수신은 그 이후 실습입니다. 강의에서 배우지 않은 네트워크 처리 기능을 앞 단계의 소스코드에 미리 넣지 않습니다.

[실습 문서](docs/step-01.md)
