# Step 01 — 내장 LED 디지털 출력

## 학습 목표
GPIO2를 OUTPUT으로 설정하고 HIGH/LOW를 delay(1000)으로 토글

## 시작 코드와 완성 코드
- **시작**: `git switch step-01-onboard-led` — 프로젝트 골격와 이 단계 TODO
- **완료**: `git switch step-01-onboard-led-done` — 이 단계 기능까지 구현
- 비교: `git diff step-01-onboard-led..step-01-onboard-led-done -- src/main.cpp platformio.ini include/`

## 연결 및 준비
- 회로: 내장 LED(GPIO2; 보드에 따라 유무·핀 번호가 다름)
- Arduino/PlatformIO의 실제 보드 설정과 USB 포트를 확인

## 구현 내용
- 핵심 구현: `pinMode(LED_PIN, OUTPUT); digitalWrite(LED_PIN, HIGH/LOW); delay(1000)`
- 개념: Digital GPIO와 출력 상태

## 실습 순서
1. 수업 시작 브랜치로 이동하고 `src/main.cpp`의 TODO 읽기
2. 새로 필요한 회로·설정·라이브러리만 추가
3. 핵심 로직 구현 후 `pio run -e esp32usb`로 빌드
4. ESP32를 USB로 업로드하고 시리얼 모니터(`115200`) 확인
5. 보드 내장 LED가 1초 켜지고 1초 꺼짐
6. 완료 브랜치와 `git diff`로 구현 차이를 비교

## 검증 기준
- **필수 동작**: 보드 내장 LED가 1초 켜지고 1초 꺼짐
- MQTT 이전 단계는 MQTT 헤더·접속 코드·라이브러리를 추가하지 않음

## 문제 해결

## 개발 환경
- 실제 사용 보드: `esp32doit-devkit-v1`, ESP32 240MHz, Arduino Framework, Serial 115200

- LED: 보드 내장 GPIO2
- 빌드: `pio run -e esp32usb`
