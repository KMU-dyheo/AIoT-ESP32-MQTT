# Step 02 — GPIO25 외부 LED

- 시작 브랜치: `step-02-external-led`
- 완료 브랜치: `step-02-external-led-done`

## 실습 순서
1. [외부 LED 점멸](step-02-01.md) — `step-02-01-led-blink` → `step-02-01-led-blink-done`
2. [1초 점등 후 5회 점멸](step-02-02.md) — `step-02-02-five-blinks` → `step-02-02-five-blinks-done`

각 서브스텝을 순서대로 진행한 뒤 마지막 완료 코드와 비교하세요.

```bash
git diff step-02-external-led..step-02-external-led-done -- src/main.cpp platformio.ini
```
