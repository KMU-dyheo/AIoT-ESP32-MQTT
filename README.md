# Step 06 — 버튼 디바운싱

**완료 예제**입니다.

## 실습 목표
- 접점 채터링을 제거하고 눌림·해제 이벤트를 확인
- 기존 GPIO25 LED 및 GPIO23 버튼 기능을 확인합니다.

## 진행
1. `git switch step-06-button-nonblocking`로 코드를 확인합니다.
2. [실습 방법](docs/step-06.md)을 보고 연결과 함수를 구현합니다.
3. `pio run -e esp32usb` 실행 후 업로드합니다.
4. `pio device monitor -b 115200`로 출력과 동작을 확인합니다.
5. `git diff step-06-button-nonblocking..step-06-button-nonblocking-done -- src/main.cpp`로 구현을 비교합니다.

## 주의
- GPIO23의 `INPUT_PULLUP` 입력은 눌림이 LOW입니다.

[전체 단계 목록](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/blob/main/README.md)
