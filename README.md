# Step 01 — ESP32 내장 LED 점멸 (완성 코드)

2주차 실습의 LED 점멸 예제입니다.

- [전체 Step 01 안내](docs/step-01.md)
- [LED 출력 설정](docs/step-01-01.md)
- [LED 점멸 구현](docs/step-01-02.md)
- 빌드: `pio run -e esp32dev_usb`
- 내장 LED가 500ms 간격으로 켜지고 꺼지는지 확인하세요.
- 시작 브랜치: `step-01-onboard-led`

```bash
git diff step-01-onboard-led..step-01-onboard-led-done -- src/main.cpp
```
