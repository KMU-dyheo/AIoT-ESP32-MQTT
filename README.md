# Step 10-01 — 버튼 pressed/released 상태 발행 (수업 완료)

## 단계별 실습
- 수업 시작: `step-10-01-button-event`
- 수업 완료: `step-10-01-button-event-done`
- 코드 비교: `git diff step-10-01-button-event..step-10-01-button-event-done -- src/main.cpp`
- 직전 완료: Step 09 MQTT 연결
- 이 단계는 버튼만 MQTT로 전송하고 LED 상태 발행은 다음 단계에서 도입

## MQTT
- `mqtt_config.h`: 브로커 PC 실제 IP, 학생별 Client ID
- `aiot/esp32-01/button/state`: `pressed`/`released`
- `aiot/esp32-01/led/state`: `on`/`off` (Step 10-02부터 retained)
- GPIO23 버튼 및 GPIO25 LED의 `updateButton()`, `updateBrightness()` 계속 실행

## 검증
- `pio run -e esp32usb`
- PC MQTT 구독기로 눌림/해제 두 메시지가 이벤트 시점에만 발생하는지 확인
- [서브스텝 실습 문서](docs/step-10-01.md), [전체 Step 10](docs/step-10.md)
