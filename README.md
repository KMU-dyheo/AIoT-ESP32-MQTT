# Step 13 — AWS IoT 원격 LED 제어 (수업 시작)

## 시작 코드
- Step 12의 AWS IoT Core TLS 연결 코드
- MQTT 원격 LED 제어 기능은 이번 단계에서 구현

## 학생 과제
- [ ] AWS IoT MQTT led/set 토픽 ON/OFF 명령 구독
- [ ] ESP32에서 수신 명령을 LED 활성 상태에 반영
- [ ] LED 상태를 led/state로 발행
- [ ] AWS IoT MQTT 테스트 클라이언트에서 동작 검증
- [ ] 네트워크 실패 시 로컬 LED/버튼 동작 유지

## 실행
- `pio run -e esp32usb`
- 실제 계정 및 인증서는 `include/aws_certificates.h`에만 입력하고 Git에 올리지 않음
- [Step 13 완성 코드](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-13-aws-iot-control-complete)와 비교
- `docs/step-13.md` 참고

## PlatformIO
- `[env]`에 보드(`esp32doit-devkit-v1`), 240MHz CPU, MQTT·JSON 라이브러리 관리
- USB/OTA 프로필은 각각 업로드 방법만 달리함
