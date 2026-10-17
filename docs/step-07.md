# Step 07 — 버튼으로 LED Fade 토글

## 학습 목표
디바운싱된 pressed 때만 ledEnabled를 반전하고 PWM 출력에 반영

## 시작 코드와 완성 코드
- **시작**: `git switch step-07-button-led` — Step 06 완료 코드와 이 단계 TODO
- **완료**: `git switch step-07-button-led-done` — 이 단계 기능까지 구현
- 비교: `git diff step-07-button-led..step-07-button-led-done -- src/main.cpp platformio.ini include/`

## 연결 및 준비
- 회로: GPIO23 버튼, GPIO25 LED
- Arduino/PlatformIO의 실제 보드 설정과 USB 포트를 확인

## 구현 내용
- 핵심 구현: `if (stableButtonState == LOW) ledEnabled = !ledEnabled; ledcWrite(0, ledEnabled ? brightness : 0)`
- 개념: 입력 이벤트 → 애플리케이션 상태 → 출력

## 실습 순서
1. 수업 시작 브랜치로 이동하고 `src/main.cpp`의 TODO 읽기
2. 새로 필요한 회로·설정·라이브러리만 추가
3. 핵심 로직 구현 후 `pio run -e esp32usb`로 빌드
4. ESP32를 USB로 업로드하고 시리얼 모니터(`115200`) 확인
5. 버튼 누를 때마다 LED Fade 실행/정지, 놓을 때는 토글하지 않음
6. 완료 브랜치와 `git diff`로 구현 차이를 비교

## 검증 기준
- **필수 동작**: 버튼 누를 때마다 LED Fade 실행/정지, 놓을 때는 토글하지 않음
- Step 04 이후: 루프에서 불필요한 `delay()` 없이 PWM 동작 유지
- MQTT 이전 단계는 MQTT 헤더·접속 코드·라이브러리를 추가하지 않음

## 문제 해결
- LED가 동작하지 않으면 GPIO25, GND 공통 접지, 저항, LED 극성을 확인
- 버튼 값이 반대로 보이면 `INPUT_PULLUP`에서 LOW=눌림인지 확인

## 개발 환경
- 실제 사용 보드: `esp32doit-devkit-v1`, ESP32 240MHz, Arduino Framework, Serial 115200

- LED: GPIO25, 220~330Ω 직렬저항
- 버튼: GPIO23 ↔ GND, `INPUT_PULLUP` (눌림 LOW, 해제 HIGH)
- 빌드: `pio run -e esp32usb`
