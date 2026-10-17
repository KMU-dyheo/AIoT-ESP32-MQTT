# Step 10-02 — LED Fade on/off 상태 발행 (수업 완료)

## 단계별 실습
- 수업 시작: `step-10-02-led-state`
- 수업 완료: `step-10-02-led-state-done`
- 코드 비교: `git diff step-10-02-led-state..step-10-02-led-state-done -- src/main.cpp`
- 직전 완료: Step 10-01 버튼 pressed/released 발행
- 이 단계는 버튼 Publish를 유지한 채 LED 상태 Publish를 추가

## MQTT
- `mqtt_config.h`: 브로커 PC 실제 IP, 학생별 Client ID
- `aiot/esp32-01/button/state`: `pressed`/`released`
- `aiot/esp32-01/led/state`: `on`/`off` (Step 10-02부터 retained)
- GPIO23 버튼 및 GPIO25 LED의 `updateButton()`, `updateBrightness()` 계속 실행

## 검증
- `pio run -e esp32usb`
- PC MQTT 구독기로 LED 활성 상태가 바뀔 때 on/off가 전달되고 연결 시 상태가 발행하는지 확인
- [서브스텝 실습 문서](docs/step-10-02.md), [전체 Step 10](docs/step-10.md)
