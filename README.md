# Step 06 — 비차단 버튼 (완성 코드)

## 실습 목적
- millis() 기반 디바운싱
- 이전 단계에서 작성한 LED Dimming과 버튼 입력 기능을 유지하며 확장

## 준비물
- ESP32 DevKit, USB 데이터 케이블, VS Code + PlatformIO
- LED, 220~330Ω 저항, 버튼, 브레드보드, 점퍼선

## 핵심 개념
- `millis()`: 현재 시간 확인
- `INPUT_PULLUP`: 버튼을 누르면 LOW 입력
- `DEBOUNCE_MS`: 버튼 접점의 흔들림을 걸러내는 시간
- `#define`: GPIO 및 고정 설정값 정의
- `setup()` / `loop()`: Arduino 기본 실행 구조

## 학생 수행 과제
- [ ] `git switch step-06-button-nonblocking` 실행
- [ ] GPIO18 LED 및 GPIO19 버튼 회로 구성
- [ ] 버튼을 눌렀을 때 상태 변경 로그가 한 번만 출력되는지 확인
- [ ] `DEBOUNCE_MS` 값을 변경해 결과 비교
- [ ] USB 업로드 및 시리얼 모니터(115200) 확인

## PlatformIO 설정 (`platformio.ini`)
- `[env]`: `platform = espressif32`, `board = esp32doit-devkit-v1`, `framework = arduino`, `monitor_speed = 115200`
- `[env:esp32usb]`: 공통 `[env]` 자동 상속, `upload_protocol = esptool`
- `[env:esp32ota]`: 공통 `[env]` 자동 상속, `upload_protocol = espota`, `upload_port`는 실제 IP로 변경
- 현재는 `default_envs = esp32usb` 사용
- 외부 라이브러리 필요 시 `env:default`의 `lib_deps`에 추가
- OTA는 Step 08 이후 사용

## 검증 기준
- USB 업로드 성공
- 버튼을 눌렀을 때 상태 변경 로그가 한 번만 출력되는지 확인
- LED Dimming 기능 유지

## 주의사항
- 버튼 채터링과 중복 이벤트 주의
- LED에 전류 제한 저항 연결
- 버튼은 GPIO19와 GND 사이 연결
- ESP32 보드의 GPIO 배치 확인

## 생각해 볼 문제
- 디바운싱이 없을 때 어떤 문제가 생기는가?
- `delay()`를 사용하지 않는 이유는 무엇인가?

## 브랜치 활용
- [수업 시작 코드](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-06-button-nonblocking-start): 직전 단계의 완성 코드와 이번 단계 TODO
- 현재 브랜치: Step 06 실습 완료 상태
- 실습 문서: `docs/step-06.md`
- 플랫폼 설정: `[env]` 공통, `esp32usb` / `esp32ota` 프로필
- 실제 보드: `esp32doit-devkit-v1`, CPU 240MHz, ESP32 Core 2.0.17
- `lib_deps`는 MQTT 도입 전까지 추가하지 않음
