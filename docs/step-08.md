# Step 08 — Wi-Fi 프로그램 구조 준비

- 시작 브랜치: `step-08-wifi`
- 완료 브랜치: `step-08-wifi-done`

## 실습 순서
1. [Wi-Fi 라이브러리 설정](step-08-01.md) — `step-08-01-wifi-library` → `step-08-01-wifi-library-done`
2. [애플리케이션 코드 분리](step-08-02.md) — `step-08-02-application-split` → `step-08-02-application-split-done`
3. [setup/loop Wi-Fi 호출 위치 준비](step-08-03.md) — `step-08-03-wifi-structure` → `step-08-03-wifi-structure-done`
4. [Wi-Fi 연결](step-08-04.md) — `step-08-04-wifi-connect` → `step-08-04-wifi-connect-done`
5. [OTA 업로드 준비](step-08-05.md) — `step-08-05-ota` → `step-08-05-ota-done`

각 서브스텝을 순서대로 진행한 뒤 마지막 완료 코드와 비교하세요.

```bash
git diff step-08-wifi..step-08-wifi-done -- src/main.cpp platformio.ini
```
