# Step 06 — 40ms 비차단 버튼 디바운싱 (수업 종료)

## 브랜치 사용
- 시작: `git switch step-06-button-nonblocking`
- 완료: `git switch step-06-button-nonblocking-done`
- `git diff step-06-button-nonblocking..step-06-button-nonblocking-done -- src/main.cpp`

## 이번 강의에서 추가하는 기능
- lastReading·stableButtonState·lastButtonChangeMs·DEBOUNCE_MS로 안정 이벤트 식별
- 버튼: GPIO23 ↔ GND, INPUT_PULLUP. 눌림=LOW / 놓임=HIGH
- LED: GPIO25 (220~330Ω 저항 직렬), PWM Fade 유지
- `updateButton()`과 `updateBrightness()`를 유지하면서 각각 변경
- 수업 시작 브랜치에는 이번 기능이 아직 구현되지 않음

## 확인 방법
- `pio run -e esp32usb`, USB Upload, Serial Monitor 115200
- 안정된 입력 변화마다 pressed/released가 중복 없이 한 번씩 출력
- MQTT 관련 라이브러리 및 통신 코드는 아직 사용하지 않음

[Step 06 실습 문서](docs/step-06.md) · [강의 흐름 대응표](docs/lecture-alignment.md)
