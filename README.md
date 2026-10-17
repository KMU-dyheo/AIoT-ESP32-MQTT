# Step 08-05 — OTA 업로드

**완성 코드**

## 실습
1. [OTA 업로드 실습](docs/step-08-05.md)을 확인합니다.
2. Wi-Fi 연결 후 OTA 서비스를 실행하도록 구성합니다.
3. `loopApplication()`에서 버튼과 LED 기능이 계속 실행되는지 확인합니다.
4. `pio run -e esp32usb`로 첫 업로드를 진행합니다.
5. `esp32ota` 환경의 실제 장치 IP와 인증 정보를 설정한 뒤 OTA를 확인합니다.
6. `git diff step-08-05-ota..step-08-05-ota-done -- src/main.cpp`로 비교합니다.

`include/wifi_config.h`는 Git에 업로드하지 않습니다.
