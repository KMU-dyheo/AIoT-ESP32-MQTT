# Step 05 — 버튼 입력과 상태 변화

- 시작 브랜치: `step-05-button`
- 완료 브랜치: `step-05-button-done`

## 실습 순서
1. [GPIO23 버튼 읽기](step-05-01.md) — `step-05-01-button-raw` → `step-05-01-button-raw-done`
2. [200ms 버튼 상태 출력](step-05-02.md) — `step-05-02-button-interval` → `step-05-02-button-interval-done`
3. [버튼 상태 변화 감지](step-05-03.md) — `step-05-03-button-change` → `step-05-03-button-change-done`

각 서브스텝을 순서대로 진행한 뒤 마지막 완료 코드와 비교하세요.

```bash
git diff step-05-button..step-05-button-done -- src/main.cpp platformio.ini
```
