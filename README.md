# Step 11 — 로컬 MQTT 원격 LED 제어 (수업 시작)

## 제공되는 코드
- 이전 Step의 완성 코드 제공
- 이번 단계 기능은 아직 구현되지 않음

## 수업 중 구현할 항목
- [ ] led/set 토픽 구독하여 ON/OFF 명령 받기
- [ ] 수신 명령을 LED 상태에 반영하고 led/state로 결과 발행
- [ ] 네트워크 실패 시 로컬 LED/버튼 동작 확인

## 실행과 비교
- `pio run -e esp32usb` 실행
- [완성 코드 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-11-mqtt-control-complete)와 코드 비교
- 실습 문서: `docs/step-11.md`

## PlatformIO
- `[env]`에 DOIT ESP32 DevKit V1 보드·240MHz·MQTT/JSON 라이브러리 설정
- `esp32usb` / `esp32ota` 공통 설정 자동 상속
