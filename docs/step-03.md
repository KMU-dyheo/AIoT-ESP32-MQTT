# Step 03 — LED PWM Fade

## 학습 목표
LEDC PWM 밝기를 0~255 범위로 상승·하강시키며 delay() 사용

## 시작 코드와 완성 코드
- **시작**: `git switch step-03-led-pwm` — Step 02 완료 코드와 이 단계 TODO
- **완료**: `git switch step-03-led-pwm-done` — 이 단계 기능까지 구현
- 비교: `git diff step-03-led-pwm..step-03-led-pwm-done -- src/main.cpp platformio.ini include/`

## 연결 및 준비
- 회로: GPIO25 외부 LED 및 직렬 저항
- Arduino/PlatformIO의 실제 보드 설정과 USB 포트를 확인

## 구현 내용
- 핵심 구현: `ledcSetup(0, 5000, 8); ledcAttachPin(25, 0); ledcWrite(0, brightness)`
- 개념: PWM 주파수, 듀티 비율, 8비트 해상도

## 실습 순서
1. 수업 시작 브랜치로 이동하고 `src/main.cpp`의 TODO 읽기
2. 새로 필요한 회로·설정·라이브러리만 추가
3. 핵심 로직 구현 후 `pio run -e esp32usb`로 빌드
4. ESP32를 USB로 업로드하고 시리얼 모니터(`115200`) 확인
5. LED 밝기가 부드럽게 증가·감소
6. 완료 브랜치와 `git diff`로 구현 차이를 비교

## 검증 기준
- **필수 동작**: LED 밝기가 부드럽게 증가·감소
- MQTT 이전 단계는 MQTT 헤더·접속 코드·라이브러리를 추가하지 않음

## 문제 해결
- LED가 동작하지 않으면 GPIO25, GND 공통 접지, 저항, LED 극성을 확인

## 개발 환경
- 실제 사용 보드: `esp32doit-devkit-v1`, ESP32 240MHz, Arduino Framework, Serial 115200

- LED: GPIO25, 220~330Ω 직렬저항
- 빌드: `pio run -e esp32usb`
