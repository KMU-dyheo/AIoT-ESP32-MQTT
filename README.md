# Step 07 — 버튼으로 LED 제어 (수업 시작)

## 제공되는 코드
- 이전 Step에서 완성한 LED/버튼 기능 제공
- 이번 단계 버튼 LED 제어는 미구현

## 학생 수행 과제
- [ ] 디바운싱된 버튼 눌림 이벤트 검출
- [ ] 버튼 한 번 누를 때마다 LED Dimming 켜기/끄기 전환

## 실행과 비교
- `pio run -e esp32usb` 실행
- 과제 코드 구현 후 [완성 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-07-button-led-complete)와 비교
- 실습 자료: `docs/step-07.md`

## PlatformIO
- 공통 `[env]` 설정: DOIT ESP32 DevKit V1 / 240MHz / Arduino
- `esp32usb` 기본 사용, Step 08에서 OTA 업로드 도입
