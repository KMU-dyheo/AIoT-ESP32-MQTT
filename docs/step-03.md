# Step 03 — PWM 제어와 마이크로초 지연

- 시작 브랜치: `step-03-led-pwm`
- 완료 브랜치: `step-03-led-pwm-done`

## 실습 순서
1. [analogWrite Fade](step-03-01.md) — `step-03-01-pwm-fade` → `step-03-01-pwm-fade-done`
2. [밝기 변경 속도](step-03-02.md) — `step-03-02-fade-speed` → `step-03-02-fade-speed-done`
3. [fadeInterval 변수](step-03-03.md) — `step-03-03-fade-interval` → `step-03-03-fade-interval-done`
4. [마이크로초 Fade](step-03-04.md) — `step-03-04-microseconds` → `step-03-04-microseconds-done`

각 서브스텝을 순서대로 진행한 뒤 마지막 완료 코드와 비교하세요.

```bash
git diff step-03-led-pwm..step-03-led-pwm-done -- src/main.cpp platformio.ini
```
