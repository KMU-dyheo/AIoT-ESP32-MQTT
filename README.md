# Step 01 — ESP32 내장 LED 점멸

**시작 코드:** GPIO2 LED 출력 설정과 점멸을 구현하세요.

## 순서
1. [시리얼 모니터](docs/step-01-01.md): `step-01-01-serial`
2. [LED 출력 설정](docs/step-01-02.md): `step-01-02-led-output`
3. [내장 LED 500ms 점멸](docs/step-01-03.md): `step-01-03-led-blink`

- [Step 01 안내](docs/step-01.md)
- 빌드: `pio run -e esp32dev_usb`
- 시작 브랜치: `step-01-onboard-led`
- 완성 브랜치: `step-01-onboard-led-done`

```bash
git diff step-01-onboard-led..step-01-onboard-led-done -- src/main.cpp
```
