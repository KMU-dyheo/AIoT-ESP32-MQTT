# Step 11 — Subscribe로 원격 LED 제어 (수업 완료)

## 이번 실습의 코드 변화
- 시작: `step-11-mqtt-control`
- 완료: `step-11-mqtt-control-done`
- 비교: `git diff step-11-mqtt-control..step-11-mqtt-control-done -- src/main.cpp platformio.ini include/`
- led/set ON/OFF 대신 자료에서 정의한 소문자 on/off 명령을 구독하여 기존 Fade 상태를 제어
- 이전 단계의 `updateButton()`, `updateBrightness()`, pressed/released 발행, LED on/off 발행 유지
- GPIO23 버튼 + GPIO25 LED, Wi-Fi/MQTT 장애 시 로컬 제어 지속

## 접속 설정
- `include/wifi_config.h`: 학생별 비공개 Wi-Fi 설정
- `include/mqtt_config.h`: MQTT Client ID 및 `aiot/esp32-01/...` 토픽 지정
- `MQTT_HOST`: Broker PC의 실제 IP. localhost는 ESP32에서 PC를 뜻하지 않음

## 검증
- `pio run -e esp32usb`로 USB 빌드
- mosquitto_pub로 aiot/esp32-01/led/set 토픽에 on/off를 보내 Fade 제어
- [단계 실습 문서](docs/step-11.md) · [원본 강의 흐름](docs/lecture-alignment.md)
