# Step 01 — 내장 LED 점멸 (수업 시작)

## 현재 코드
- 기본 Arduino 프로그램 골격만 제공
- 이번 단계 구현은 아직 포함하지 않음

## 수업 목표
- setup()에서 LED 핀을 OUTPUT으로 설정
- loop()에서 HIGH/LOW와 delay()로 1초 점멸 구현

## 학생 구현 과제
- [ ] setup()에서 LED 핀을 OUTPUT으로 설정
- [ ] loop()에서 HIGH/LOW와 delay()로 1초 점멸 구현
- [ ] `pio run -e esp32usb`로 빌드
- [ ] LED 동작 확인
- [ ] [완성 코드 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-01-onboard-led-done)와 차이 비교

## PlatformIO
- `platformio.ini`의 `[env]`에 공통 보드·MCU·CPU·프레임워크 설정
- `esp32usb`는 USB 업로드, `esp32ota`는 OTA 업로드 프로필
- 보드 `esp32doit-devkit-v1`, CPU 240MHz
- Step 01~07에서는 USB 업로드 사용

## 참고 자료
- `docs/step-01.md`

## 강의 진행 브랜치
- **수업 시작**: [`step-01-onboard-led`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-01-onboard-led)
- **수업 완료**: [`step-01-onboard-led-done`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-01-onboard-led-done)
- 현재 브랜치: **수업 시작 코드**
- 현재 실습 문서: `docs/step-01.md`; 강의노트와의 연결은 `docs/lecture-alignment.md` 참고
