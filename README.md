# Step 04 — millis로 비차단 LED Fade (완료 코드)

## 시작과 완료
- 수업 시작: `step-04-led-nonblocking`
- 수업 완료: `step-04-led-nonblocking-done`
- 현재 브랜치: 이번 실습을 구현한 기준 코드
- 코드 변경 비교: `git diff step-04-led-nonblocking..step-04-led-nonblocking-done -- src/main.cpp`

## 실습 핵심
- GPIO25 외부 LED, 220~330Ω 직렬 저항
- delay 대신 millis() 경과 시간을 사용하여 Fade 상태를 주기적으로 갱신
- LED 밝기를 0~255 범위로 변화시키며 시리얼/육안으로 확인
- `pio run -e esp32usb`로 빌드
- MQTT 라이브러리는 이 단계에 포함되지 않음

## 실습 자료
- [현재 단계 강의](docs/step-04.md)
- [전체 강의노트–실습 연결](docs/lecture-alignment.md)
- `docs/`에는 단계별 전체 문서가 포함될 수 있지만 `src/`는 현재 단계까지만 구현
