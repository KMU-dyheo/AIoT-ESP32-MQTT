# Step 03 — PWM LED 밝기 조절 (수업 시작)

## 제공되는 코드
- 이전 Step 완성 코드 제공
- 이번 단계 기능은 미구현

## 수업 중 구현할 항목
- [ ] digitalWrite 점멸을 PWM 출력으로 바꾸기
- [ ] 밝기 0~255 상승/하강을 delay로 구현

## 실행과 비교
- `pio run -e esp32usb`로 시작 코드 빌드
- `src/main.cpp` 수정 후 업로드
- [수업 종료 완성 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-03-led-pwm-done)와 차이 비교

## 공통 설정
- `[env]`에 `esp32doit-devkit-v1` 및 240MHz 설정
- USB/OTA 환경은 공통 `[env]` 설정 사용
- 참고: `docs/step-03.md`

## 강의 진행 브랜치
- **수업 시작**: [`step-03-led-pwm`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-03-led-pwm)
- **수업 완료**: [`step-03-led-pwm-done`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-03-led-pwm-done)
- 현재 브랜치: **수업 시작 코드**
- 현재 실습 문서: `docs/step-03.md`; 강의노트와의 연결은 `docs/lecture-alignment.md` 참고
