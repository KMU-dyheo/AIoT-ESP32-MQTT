# Step 08-04 — Wi-Fi 연결

이전 단계의 코드를 사용해 이번 실습을 시작합니다.

## 실습
1. `git switch step-08-04-wifi-connect`로 시작합니다.
2. [실습 안내](docs/step-08-04.md)의 절차를 따릅니다.
3. `setupApplication()`과 `loopApplication()`에서 GPIO23 버튼·GPIO25 LED 기능을 유지합니다.
4. `pio run -e esp32usb`로 빌드하고 USB로 업로드합니다.
5. Wi-Fi 연결 및 실패 시 로컬 동작을 확인합니다.
6. `git diff step-08-04-wifi-connect..step-08-04-wifi-connect-done -- src/main.cpp platformio.ini include/`로 비교합니다.

네트워크 비밀번호는 `include/wifi_config.h`에 작성하고 Git에 업로드하지 않습니다.
