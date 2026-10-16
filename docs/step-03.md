# Step 03 실습 — PWM LED Dimming

## 실습 목적
- PWM 듀티비 0~255 변화로 밝기 조절
- 이전 단계 기능과 새 기능의 차이 이해

## 준비물
- ESP32 DevKit, USB 데이터 케이블, PlatformIO
- LED, 220~330Ω 저항, 버튼, 브레드보드, 점퍼선(해당 단계에서 필요한 부품)

## 회로 및 환경 구성
- Step 02의 LED 회로 유지
- 사용 보드의 GPIO 핀 배치 확인

## 실습 진행
1. `git switch step-03-led-pwm` 실행
2. `src/main.cpp`에서 핀 번호와 설정값 확인
3. `platformio.ini`의 `[env:default]`에서 실제 보드 ID 확인
4. `[env:esp32usb]`가 `extends = env:default`로 공통 설정을 참조하는지 확인
5. PlatformIO에서 USB Build 및 Upload 실행
6. PWM 듀티비 0~255 변화로 밝기 조절
7. 동작 결과 기록 및 이전 단계와 비교

## platformio.ini 설명
- `[env:default]`: `platform`, `board`, `framework`, `monitor_speed`, 공통 `lib_deps` 설정
- `[env:esp32usb]`: USB 업로드, `upload_protocol = esptool`
- `[env:esp32ota]`: 무선 업로드, `upload_protocol = espota`
- `extends = env:default`: 두 프로필의 공통 설정 상속
- Step 01~07은 USB 업로드 사용, Step 08부터 OTA 사용 가능
- 실제 보드에 맞춰 `board` 수정, OTA 시 `upload_port`를 실제 ESP32 IP로 수정

## 확인할 결과
- 빌드 및 업로드 성공
- PWM 듀티비 0~255 변화로 밝기 조절
- 기존 기능 유지

## 주의사항
- PWM 함수가 보드의 Arduino Core 버전과 호환되는지 확인
- LED에는 전류 제한 저항 사용
- ESP32 GPIO에 5V 직접 입력 금지

## 추가 실습
- 코드의 주기 또는 설정값을 변경하여 동작 비교
- 이전 단계와 변경된 코드 구간을 찾아 설명
