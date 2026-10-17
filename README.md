# Step 05 — GPIO23 버튼 상태 입력 (수업 시작)

## 브랜치 사용
- 시작: `git switch step-05-button`
- 완료: `git switch step-05-button-done`
- `git diff step-05-button..step-05-button-done -- src/main.cpp`

## 이번 강의에서 추가하는 기능
- updateButton()을 도입하고 원시 눌림/해제 변화를 시리얼로 확인
- 버튼: GPIO23 ↔ GND, INPUT_PULLUP. 눌림=LOW / 놓임=HIGH
- LED: GPIO25 (220~330Ω 저항 직렬), PWM Fade 유지
- `updateButton()`과 `updateBrightness()`를 유지하면서 각각 변경
- 수업 시작 브랜치에는 이번 기능이 아직 구현되지 않음

## 확인 방법
- `pio run -e esp32usb`, USB Upload, Serial Monitor 115200
- 누름/해제 시 pressed/released 출력 확인(채터링 가능)
- MQTT 관련 라이브러리 및 통신 코드는 아직 사용하지 않음

[Step 05 실습 문서](docs/step-05.md) · [강의 흐름 대응표](docs/lecture-alignment.md)
