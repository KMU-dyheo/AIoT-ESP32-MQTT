# Step 04 — micros 비차단 PWM

- 시작 브랜치: `step-04-led-nonblocking`
- 완료 브랜치: `step-04-led-nonblocking-done`

## 실습 순서
1. [loop 재진입 시간 측정](step-04-01.md) — `step-04-01-loop-timing` → `step-04-01-loop-timing-done`
2. [micros 기반 비차단 Fade](step-04-02.md) — `step-04-02-micros-fade` → `step-04-02-micros-fade-done`
3. [updateBrightness() 추출](step-04-03.md) — `step-04-03-brightness-function` → `step-04-03-brightness-function-done`

각 서브스텝을 순서대로 진행한 뒤 마지막 완료 코드와 비교하세요.

```bash
git diff step-04-led-nonblocking..step-04-led-nonblocking-done -- src/main.cpp platformio.ini
```
