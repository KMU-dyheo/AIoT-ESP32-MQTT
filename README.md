# Step 06 — 버튼 디바운싱

**실습 시작 코드**입니다. `src/main.cpp`의 TODO를 직접 작성하세요.

## 진행 방법
1. 시작 코드 확인: `git switch step-06-button-nonblocking`
2. [실습 설명](docs/step-06.md)에서 구현 목표와 연결 방법 확인
3. 소스 작성 후 `pio run -e esp32usb`로 컴파일 및 업로드
4. 시리얼 모니터(`115200`)와 LED·버튼 동작 확인
5. 코드 비교: `git diff step-06-button-nonblocking..step-06-button-nonblocking-done -- src/main.cpp`

## 연결
- LED: GPIO25, 직렬 저항 220~330Ω
- 버튼: GPIO23 ↔ GND, `INPUT_PULLUP`; 누르면 LOW

## 참고
- 사용 보드: DOIT ESP32 DevKit V1, Arduino Framework
- [전체 Step 목록](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/blob/main/README.md)
