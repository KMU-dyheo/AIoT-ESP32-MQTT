# AIoT ESP32 Lab

PlatformIO + Arduino Framework 기반 단계별 ESP32 실습 저장소입니다.

## 실습 브랜치

1. `step-01-onboard-led` — ESP32 내장 LED 제어
2. `step-02-external-led` — 외부 LED 제어
3. `step-03-led-pwm` — PWM LED Dimming
4. `step-04-led-nonblocking` — 비차단 Dimming
5. `step-05-button` — 버튼 읽기
6. `step-06-button-nonblocking` — 비차단 버튼 읽기
7. `step-07-button-led` — 버튼으로 LED 제어
8. `step-08-wifi` — 개인/기업 Wi-Fi 연결
9. `step-09-mqtt-connect` — 로컬 MQTT 연결
10. `step-10-mqtt-publish` — MQTT 데이터 발행
11. `step-11-mqtt-control` — MQTT 원격 제어
12. `step-12-aws-iot-connect` — AWS IoT Core TLS 인증서 연결
13. `step-13-aws-iot-control` — AWS IoT Core 제어

각 브랜치는 이전 단계의 기능을 기반으로 누적 확장합니다. Step 01~07은 `setup()`과 `loop()`를 직접 사용하며, Step 08부터 `setupApplication()`과 `loopApplication()`으로 로컬 기능을 분리합니다.

각 단계의 `README.md`는 해당 브랜치 실습을 설명하고, `docs/step-XX.md`는 단계별 실습 안내서입니다. `platformio.ini`는 `[env]` 공통 설정을 `esp32usb`/`esp32ota`가 상속합니다. Step 08 이전에는 USB 업로드를 사용합니다.

### 시작하기

```bash
git clone https://github.com/KMU-dyheo/AIoT-ESP32-MQTT.git
cd AIoT-ESP32-MQTT
git switch step-01-onboard-led-start
```

> ESP32 DevKit의 내장 LED GPIO는 모델에 따라 다르며 내장 LED가 없는 보드도 있습니다. 각 단계의 설정값을 확인하세요.

## 저장소 구성 원칙

- `main`: 전체 커리큘럼, 공통 `docs/step-01.md` ~ `docs/step-13.md`, 26개 수업 브랜치 빌드 검증 워크플로
- `step-XX-...-start`: 수업 시작 코드(이전 단계 완성 기능과 이번 단계 TODO)
- `step-XX-...-complete`: 수업 종료 완성 코드
- 접미사가 없는 기존 브랜치는 이전 자료 링크 호환을 위해 보존
- 각 Step 브랜치의 `docs/`에는 전체 13개 안내서를 동일하게 제공
- Step 01~07: `setup()` / `loop()` 직접 구현
- Step 08~13: `setupApplication()` / `loopApplication()`에 로컬 기능을 분리
- Step 01~08: 추가 MQTT 라이브러리 없음, Step 09부터 `ESP32MQTTClient` 및 `ArduinoJson` 추가
- `platformio.ini`: `[env]`의 공통값을 `esp32usb`, `esp32ota` 환경이 자동 공유
- ESP32 플랫폼: `espressif32 @ 6.12.0` (Arduino Core 2.0.17), PWM/WPA2-Enterprise 예제도 해당 버전 기준
- Wi-Fi 비밀번호, MQTT 설정, AWS 인증서/개인키의 실사용 파일은 Git에서 제외

## 자동 빌드 검증

- `.github/workflows/platformio-build.yml`에서 Step 01~13의 시작/완성 브랜치 26개를 각각 체크아웃해 USB 프로필 빌드
- 공개된 예시 설정 헤더를 복사해 컴파일하므로 실제 Wi-Fi 비밀번호나 AWS 개인키를 CI에 업로드하지 않음
- GitHub Actions에서 `ESP32 Step Build Check`를 선택해 수동 실행 가능
- 자동 빌드는 컴파일을 확인하는 절차이며 ESP32 보드 실물, Wi-Fi, OTA, Mosquitto, AWS IoT 동작을 보장하지 않음

## 학생 시작 코드와 수업 완성 코드

- 각 Step은 `-start`와 `-complete` 브랜치로 구분
- `step-XX-...-start`: 이전 단계 완성 코드 + 현재 단계 학생 TODO (컴파일 가능)
- `step-XX-...-complete`: 해당 단계 실습 완성 결과
- 기존 `step-XX-...` 브랜치는 이전 자료 링크 호환을 위해 보존
- 실제 보드 설정: `board = esp32doit-devkit-v1`, `board_build.mcu = esp32`, `board_build.f_cpu = 240000000L`
- `[env]` 공통 설정은 USB/OTA 환경으로 자동 전파
- Step 09부터 `cyijun/ESP32MQTTClient@^1.1.3` 및 `bblanchon/ArduinoJson` 추가
