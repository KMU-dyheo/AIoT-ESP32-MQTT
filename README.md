# Step 10 — 버튼 이벤트 및 LED 상태 Publish (수업 시작 코드)

## 강의의 진행 순서
- 시작 브랜치: `step-10-mqtt-publish` (기존 로컬 버튼/PWM/Wi-Fi 유지)
- 완료 브랜치: `step-10-mqtt-publish-done`
- 버튼 pressed/released 이벤트 전송 뒤 LED on/off 상태 전송으로 점진적으로 확장
- 서브스텝: step-10-01-button-event → step-10-02-led-state → step-10-mqtt-publish-done

## 변경하는 기능
- GPIO23 버튼, GPIO25 LED PWM, `updateButton()`, `updateBrightness()`는 수정 없이 동작 유지
- `[env]`의 `lib_deps`에 `cyijun/ESP32MQTTClient@^1.1.3`, `bblanchon/ArduinoJson` (Step 09 완료부터)
- `mqtt_config.example.h`를 `mqtt_config.h`로 복사하고 Broker PC IP 및 고유 Client ID 입력
- 토픽: `aiot/esp32-01/button/state`(`pressed`/`released`), `aiot/esp32-01/led/state`(`on`/`off`)
- Wi-Fi/MQTT 장애 중에도 LED Fade와 버튼 토글 유지

## 검증
- `pio run -e esp32usb` 빌드
- mosquitto_sub로 눌림/해제, LED on/off 전송 확인
- [단계 실습 안내](docs/step-10.md) · [강의 흐름](docs/lecture-alignment.md)
