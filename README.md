# Step 07 — 버튼으로 PWM Fade 토글 (수업 종료)

## 브랜치 및 누적 코드
- 시작: `step-07-button-led` (이전 단계 완료 코드 + 새 TODO)
- 완료: `step-07-button-led-done` (새 기능 추가)
- `git diff step-07-button-led..step-07-button-led-done -- src/main.cpp platformio.ini include/`

## 이 수업의 목표
- 디바운싱된 pressed일 때 ledEnabled를 토글하고 LED Fade 실행/정지
- GPIO25 LED PWM, GPIO23 INPUT_PULLUP 버튼 유지
- `updateButton()`과 `updateBrightness()`의 동작을 삭제하거나 이름을 바꾸지 않음
- 버튼 해제 시 Fade 상태를 토글하지 않음
- MQTT 라이브러리는 아직 추가하지 않음. MQTT 연결은 Step 09부터 실습

## 검증
- `pio run -e esp32usb`로 빌드·업로드
- 버튼 누를 때 Fade 실행과 정지가 번갈아 발생
- 실제 강의: [docs/step-07.md](docs/step-07.md)
- [강의노트 연계](docs/lecture-alignment.md)
