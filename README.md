# Step 13 — MQTT 반정형(JSON) 데이터 확장 (수업 완료)

## 이번 단계
- 시작: `step-13-aws-iot-control` — AWS MQTT·인증서·원격 LED 제어까지 구현된 코드
- 완료: `step-13-aws-iot-control-done` — JSON `{"state":"on"}`/`{"state":"off"}` 명령과 LED 상태 JSON 추가
- 이번 단계의 변경점만 비교: `git diff step-13-aws-iot-control..step-13-aws-iot-control-done -- src/main.cpp`
- 기존 일반 문자열 명령 `on`/`off`, 버튼 이벤트 `pressed`/`released` 유지
- JSON LED 상태에는 `device`, `led`, `brightness`, `uptime_ms` 포함

## 검증
- GPIO23 버튼 / GPIO25 LED / `updateButton()` / `updateBrightness()` 유지
- ESP32 Wi-Fi 및 AWS IoT Core TLS 연결 후 문자열·JSON 명령 비교
- `pio run -e esp32usb`
- [Step 13 안내](docs/step-13.md) · [전체 강의 흐름](docs/lecture-alignment.md)
- JSON은 첨부한 원본 100분 MQTT 실습의 필수 범위가 아니라 후속 심화 범위
