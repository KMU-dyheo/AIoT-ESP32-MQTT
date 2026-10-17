# Step 09 — 로컬 MQTT 연결 (수업 시작)

## 제공되는 코드
- 이전 Step의 완성 코드 제공
- 이번 단계 기능은 아직 포함되지 않음

## 수업 중 구현할 항목
- [ ] 공통 lib_deps에 ESP32MQTTClient 1.1.3과 ArduinoJson 추가
- [ ] PC Mosquitto 브로커에 백그라운드 MQTT 연결 구현
- [ ] 네트워크 연결에 실패해도 LED/버튼 동작 확인

## 실행 및 비교
- MQTT 서버: 학생 PC의 Mosquitto, ESP32에서 접근 가능한 실제 PC IP 사용
- `pio run -e esp32usb` 실행
- [완성 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-09-mqtt-connect-complete)에서 새로 추가된 코드를 확인
- 실습 문서: `docs/step-09.md`

## PlatformIO
- 공통 설정 `[env]`에서 `lib_deps` 관리
- MQTT 연결은 `ESP32MQTTClient` 1.1.3 비차단 백그라운드 방식
- ESP32 보드: `esp32doit-devkit-v1`
