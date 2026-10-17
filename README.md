# Step 12 — AWS IoT Core TLS 연결 (수업 시작)

## 제공되는 코드
- 이전 Step의 완성 코드 제공
- 이번 단계 기능은 아직 구현되지 않음

## 수업 중 구현할 항목
- [ ] AWS IoT Root CA·장치 인증서·개인키를 활용하여 TLS 설정
- [ ] Mosquitto에서 AWS IoT Core MQTT 서버로 연결 전환
- [ ] 네트워크 실패 시 로컬 LED/버튼 동작 확인

## 실행과 비교
- `pio run -e esp32usb` 실행
- [완성 코드 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-12-aws-iot-connect-done)와 코드 비교
- 실습 문서: `docs/step-12.md`

## PlatformIO
- `[env]`에 DOIT ESP32 DevKit V1 보드·240MHz·MQTT/JSON 라이브러리 설정
- `esp32usb` / `esp32ota` 공통 설정 자동 상속

## 강의 진행 브랜치
- **수업 시작**: [`step-12-aws-iot-connect`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-12-aws-iot-connect)
- **수업 완료**: [`step-12-aws-iot-connect-done`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-12-aws-iot-connect-done)
- 현재 브랜치: **수업 시작 코드**
- 현재 실습 문서: `docs/step-12.md`; 강의노트와의 연결은 `docs/lecture-alignment.md` 참고
