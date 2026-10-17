# Step 05 — 버튼 상태 (수업 완료)

## 실습 목적
- digitalRead와 풀업 입력 이해
- 이전 단계의 LED/버튼 실습과 새로운 기능 연결

## 준비물
- ESP32 DevKit, USB 데이터 케이블, VS Code + PlatformIO
- 외부 LED, 220~330Ω 저항, 버튼, 브레드보드, 점퍼선

## 핵심 개념
- 새 단계에서 추가되는 함수와 조건문을 `src/main.cpp`에서 확인
- `#define`은 핀 번호와 변경하지 않는 설정값에 사용
- Step 01~07은 Arduino 기본 `setup()`과 `loop()` 직접 사용

## 학생 수행 과제
- [ ] `git switch step-05-button-done` 실행
- [ ] GPIO19 버튼을 GND로 연결, INPUT_PULLUP에서 LOW가 눌림임을 확인
- [ ] `src/main.cpp`의 `#define` 설정 확인
- [ ] Build 및 USB Upload 실행
- [ ] 이전 단계와 달라진 동작을 관찰하고 설명

## PlatformIO 설정 (`platformio.ini`)
- `[env]`에 `platform`, `board`, `framework`, `monitor_speed`, 공통 `lib_deps` 설정
- `[env:esp32usb]`: 공통 `[env]` 자동 상속, `upload_protocol = esptool`
- `[env:esp32ota]`: 공통 `[env]` 자동 상속, `upload_protocol = espota`
- 현재 단계에서는 `default_envs = esp32usb` 사용
- `board = esp32doit-devkit-v1`는 실제 보드 모델에 맞게 변경
- OTA 업로드는 Step 08에서 ArduinoOTA를 구현한 뒤 사용

## 검증 기준
- 오류 없이 USB 업로드 완료
- GPIO19 버튼을 GND로 연결, INPUT_PULLUP에서 LOW가 눌림임을 확인
- 동작 결과를 실습 기록에 정리

## 주의사항
- delay(100)은 버튼 관찰용이며 다음 단계에서 제거
- LED에는 반드시 전류 제한 저항 사용
- 버튼은 INPUT_PULLUP 기준 GPIO와 GND 사이에 연결
- 보드와 실제 GPIO 핀 번호 확인

## 생각해 볼 문제
- 이번 단계에서 이전 단계와 비교해 추가된 동작은?
- `delay()` 사용 여부가 버튼 입력 응답에 미치는 영향은?

## 브랜치 활용
- [수업 시작 코드](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-05-button): 직전 단계의 완성 코드와 이번 단계 TODO
- 현재 브랜치: Step 05 실습 완료 상태
- 실습 문서: `docs/step-05.md`
- 플랫폼 설정: `[env]` 공통, `esp32usb` / `esp32ota` 프로필
- 실제 보드: `esp32doit-devkit-v1`, CPU 240MHz, ESP32 Core 2.0.17
- `lib_deps`는 MQTT 도입 전까지 추가하지 않음

## 강의 진행 브랜치
- **수업 시작**: [`step-05-button`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-05-button)
- **수업 완료**: [`step-05-button-done`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-05-button-done)
- 현재 브랜치: **수업 완료 코드**
- 현재 실습 문서: `docs/step-05.md`; 강의노트와의 연결은 `docs/lecture-alignment.md` 참고
