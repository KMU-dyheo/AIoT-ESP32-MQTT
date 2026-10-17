# Step 02 — 외부 LED 제어

**실습 시작 코드**입니다. `src/main.cpp`의 TODO를 구현하세요.

## 실습 방법
1. `git switch step-02-external-led`로 시작 코드를 확인합니다.
2. [Step 02 실습 안내](docs/step-02.md)의 배선과 구현 항목을 따라 진행합니다.
3. `pio run -e esp32usb`로 컴파일하고 ESP32에 업로드합니다.
4. 시리얼 모니터(`115200`)에서 결과를 확인합니다.
5. GPIO25에 연결된 LED가 점멸하는지 확인.
6. 완료 코드가 필요하면 `git switch step-02-external-led-done`으로 이동합니다.

## 코드 비교
```bash
git diff step-02-external-led..step-02-external-led-done -- src/main.cpp platformio.ini include/
```

## 연결
- Step 01: 내장 LED GPIO2
- Step 02부터: GPIO25 외부 LED + 220~330Ω 저항
- Step 05부터: GPIO23 버튼 ↔ GND, `INPUT_PULLUP`
- MQTT 연결은 Step 09부터, AWS IoT Core는 Step 12부터 사용합니다.

[전체 단계 목록](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/blob/main/README.md)
