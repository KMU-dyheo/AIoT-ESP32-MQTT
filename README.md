# Step 07 — 버튼으로 LED 제어

**시작 코드**입니다. TODO를 채워 실습을 완료하세요.

## 실습 목표
- 버튼을 누를 때마다 LED Fade 실행 상태가 전환되는지 확인
- 기존 GPIO25 LED 및 GPIO23 버튼 기능을 확인합니다.

## 진행
1. `git switch step-07-button-led`로 코드를 확인합니다.
2. [실습 방법](docs/step-07.md)을 보고 연결과 함수를 구현합니다.
3. `pio run -e esp32usb` 실행 후 업로드합니다.
4. `pio device monitor -b 115200`로 출력과 동작을 확인합니다.
5. `git diff step-07-button-led..step-07-button-led-done -- src/main.cpp`로 구현을 비교합니다.

## 주의
- GPIO23의 `INPUT_PULLUP` 입력은 눌림이 LOW입니다.

[전체 단계 목록](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/blob/main/README.md)
