# Step 03 — LED PWM Dimming

## 실습 목적
- PWM과 듀티비 개념 이해
- 이전 단계의 LED/버튼 실습과 새로운 기능 연결

## 준비물
- ESP32 DevKit, USB 데이터 케이블, VS Code + PlatformIO
- 외부 LED, 220~330Ω 저항, 버튼, 브레드보드, 점퍼선

## 핵심 개념
- 새 단계에서 추가되는 함수와 조건문을 `src/main.cpp`에서 확인
- `#define`은 핀 번호와 변경하지 않는 설정값에 사용
- Step 01~07은 Arduino 기본 `setup()`과 `loop()` 직접 사용

## 학생 수행 과제
- [ ] `git switch step-03-led-pwm` 실행
- [ ] PWM 듀티비를 0~255로 변경하며 밝기 관찰
- [ ] `src/main.cpp`의 `#define` 설정 확인
- [ ] Build 및 USB Upload 실행
- [ ] 이전 단계와 달라진 동작을 관찰하고 설명

## PlatformIO 설정 (`platformio.ini`)
- `[env:default]`에 `platform`, `board`, `framework`, `monitor_speed`, 공통 `lib_deps` 설정
- `[env:esp32usb]`: `extends = env:default`, `upload_protocol = esptool`
- `[env:esp32ota]`: `extends = env:default`, `upload_protocol = espota`
- 현재 단계에서는 `default_envs = esp32usb` 사용
- `board = esp32dev`는 실제 보드 모델에 맞게 변경
- OTA 업로드는 Step 08에서 ArduinoOTA를 구현한 뒤 사용

## 검증 기준
- 오류 없이 USB 업로드 완료
- PWM 듀티비를 0~255로 변경하며 밝기 관찰
- 동작 결과를 실습 기록에 정리

## 주의사항
- ESP32 Arduino Core 3.x의 ledcAttach/ledcWrite API 사용
- LED에는 반드시 전류 제한 저항 사용
- 버튼은 INPUT_PULLUP 기준 GPIO와 GND 사이에 연결
- 보드와 실제 GPIO 핀 번호 확인
- 기초 단계에서는 고급 C++ 문법 대신 Arduino 기본 문법 사용

## 생각해 볼 문제
- 이번 단계에서 이전 단계와 비교해 추가된 동작은?
- `delay()` 사용 여부가 버튼 입력 응답에 미치는 영향은?
