# Step 02 — 외부 LED 제어

**완성 코드:** 이번 단계의 실습 결과입니다.

## 실습
1. `git switch step-02-external-led`로 시작합니다.
2. [Step 02 실습 안내](docs/step-02.md)를 참고해 회로와 코드를 작성합니다.
3. `pio run -e esp32usb`로 빌드한 뒤 보드에 업로드합니다.
4. GPIO25 외부 LED가 점멸하는지 확인합니다.
5. 결과를 `git diff step-02-external-led..step-02-external-led-done -- src/main.cpp`로 비교합니다.

## 준비물
- ESP32 DOIT DevKit V1, USB 케이블
- GPIO25 LED, 220~330Ω 저항, 브레드보드
- Step 05부터는 GPIO23 버튼을 추가합니다.

[전체 실습 목록](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/blob/main/README.md)
