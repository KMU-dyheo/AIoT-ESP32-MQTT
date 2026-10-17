# Step 02 — 외부 LED 제어 (수업 시작)

## 현재 코드
- Step 01에서 작성한 내장 LED 점멸 코드 제공
- 이번 단계 구현은 아직 포함하지 않음

## 수업 목표
- GPIO18에 LED와 저항을 연결
- LED_PIN을 외부 LED 핀에 맞게 변경하여 점멸 구현

## 학생 구현 과제
- [ ] GPIO18에 LED와 저항을 연결
- [ ] LED_PIN을 외부 LED 핀에 맞게 변경하여 점멸 구현
- [ ] `pio run -e esp32usb`로 빌드
- [ ] LED 동작 확인
- [ ] [완성 코드 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-02-external-led-complete)와 차이 비교

## PlatformIO
- `platformio.ini`의 `[env]`에 공통 보드·MCU·CPU·프레임워크 설정
- `esp32usb`는 USB 업로드, `esp32ota`는 OTA 업로드 프로필
- 보드 `esp32doit-devkit-v1`, CPU 240MHz
- Step 01~07에서는 USB 업로드 사용

## 참고 자료
- `docs/step-02.md`
