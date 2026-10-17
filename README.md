# Step 04 — 비차단 LED Dimming (수업 시작)

## 제공되는 코드
- 이전 Step 완성 코드 제공
- 이번 단계 기능은 미구현

## 수업 중 구현할 항목
- [ ] PWM 밝기 조절에서 delay 제거
- [ ] millis()와 이전 시간 비교로 주기 처리

## 실행과 비교
- `pio run -e esp32usb`로 시작 코드 빌드
- `src/main.cpp` 수정 후 업로드
- [수업 종료 완성 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-04-led-nonblocking-done)와 차이 비교

## 공통 설정
- `[env]`에 `esp32doit-devkit-v1` 및 240MHz 설정
- USB/OTA 환경은 공통 `[env]` 설정 사용
- 참고: `docs/step-04.md`

## 강의 진행 브랜치
- **수업 시작**: [`step-04-led-nonblocking`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-04-led-nonblocking)
- **수업 완료**: [`step-04-led-nonblocking-done`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-04-led-nonblocking-done)
- 현재 브랜치: **수업 시작 코드**
- 현재 실습 문서: `docs/step-04.md`; 강의노트와의 연결은 `docs/lecture-alignment.md` 참고
