# Step 01 — 내장 LED 점멸 (수업 완료)

## 브랜치
- 수업 시작: `step-01-onboard-led`
- 수업 완료: `step-01-onboard-led-done`
- 현재 상태: **이번 단계 실습 구현 결과**
- 변경 비교: `git diff step-01-onboard-led..step-01-onboard-led-done -- src/main.cpp platformio.ini include/`

## 학습 목표 및 검증
- 상세 과제·배선·검증 기준: [docs/step-01.md](docs/step-01.md)
- ESP32 내장 GPIO2 LED 확인
- ESP32 DOIT DevKit V1, 240MHz, USB 업로드: `pio run -e esp32usb`
- MQTT 통신은 Step09부터만 추가. 로컬 버튼/Fade는 네트워크 장애와 무관하게 실행.
- GPIO를 설정할 때 `#define` 예제를 사용하며 학생의 C++ 문법 선택은 제한하지 않음.

## 강의 자료
- `docs/step-01.md` ~ `docs/step-13.md`, 서브스텝 `docs/step-10-01.md`·`step-10-02.md`
- `docs/lecture-alignment.md` — 기존 버튼 입력 수업 자료와 MQTT 강의 흐름 대조
