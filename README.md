# Step 12 — AWS IoT Core X.509 TLS 연결 (수업 시작)

## 이번 실습의 코드 변화
- 시작: `step-12-aws-iot-connect`
- 완료: `step-12-aws-iot-connect-done`
- 비교: `git diff step-12-aws-iot-connect..step-12-aws-iot-connect-done -- src/main.cpp platformio.ini include/`
- 로컬 MQTT Broker에서 AWS IoT Core 8883 TLS로 전환; 인증서·시각 동기화 추가
- 이전 단계의 `updateButton()`, `updateBrightness()`, pressed/released 발행, LED on/off 발행 유지
- GPIO23 버튼 + GPIO25 LED, Wi-Fi/MQTT 장애 시 로컬 제어 지속

## 접속 설정
- `include/wifi_config.h`: 학생별 비공개 Wi-Fi 설정
- `include/mqtt_config.h`: MQTT Client ID 및 `aiot/esp32-01/...` 토픽 지정
- `include/aws_certificates.h`: AWS IoT 장치별 X.509·CA·개인키 (Git 제외)

## 검증
- `pio run -e esp32usb`로 USB 빌드
- AWS IoT 클라이언트에서 버튼 이벤트, LED 상태, 원격 on/off 제어까지 유지 확인
- [단계 실습 문서](docs/step-12.md) · [원본 강의 흐름](docs/lecture-alignment.md)
