# Step 08 — Wi-Fi 및 OTA

**시작 코드**입니다. TODO를 채워 실습을 완료하세요.

## 실습 목표
- 네트워크 연결 상태와 관계없이 LED·버튼을 제어
- 기존 GPIO25 LED 및 GPIO23 버튼 기능을 확인합니다.

## 진행
1. `git switch step-08-wifi`로 코드를 확인합니다.
2. [실습 방법](docs/step-08.md)을 보고 연결과 함수를 구현합니다.
3. `pio run -e esp32usb` 실행 후 업로드합니다.
4. `pio device monitor -b 115200`로 출력과 동작을 확인합니다.
5. `git diff step-08-wifi..step-08-wifi-done -- src/main.cpp`로 구현을 비교합니다.

## 주의
- GPIO23의 `INPUT_PULLUP` 입력은 눌림이 LOW입니다.
- Wi-Fi 비밀번호와 OTA 비밀번호는 `include/wifi_config.h`에 입력하고 Git에 올리지 않습니다.

[전체 단계 목록](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/blob/main/README.md)
