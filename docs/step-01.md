# Step 01 — 내장 LED 점멸

## 시작/완성 코드
- 시작: `step-01-onboard-led-start` (이전 단계 완성 코드 + TODO)
- 완성: `step-01-onboard-led-complete` (이번 단계 구현 결과)

## 실습 목표
- GPIO2(보드별 상이) 내장 LED에 pinMode/digitalWrite/delay 적용
- 이전 단계와 달라진 점을 관찰하고 설명

## 실습 준비
- ESP32 DevKit, USB 데이터 케이블, PlatformIO/VS Code
- ESP32 내장 사용자 LED
- 시작 브랜치: `git switch step-01-onboard-led-start`

## 회로 및 설정
- 내장 사용자 LED GPIO를 보드 핀맵에서 확인
- GPIO2 내장 LED 존재 여부는 보드마다 상이

## 이번 단계에서 변경되는 코드
- setup/loop, delay(1000), #define LED_PIN
- 전체 코드: `src/main.cpp`
- 변경 결과를 이전 브랜치와 비교: `git diff step-01-onboard-led-start..step-01-onboard-led-complete -- src/main.cpp`

## PlatformIO 설정
- `platformio.ini`에서 `[env]`에 공통 설정(`platform`, `board`, `board_build.mcu = esp32`, `board_build.f_cpu = 240000000L`, `framework`, `monitor_speed`; 외부 라이브러리는 필요한 단계에서 `lib_deps`) 배치
- `[env:esp32usb]`와 `[env:esp32ota]`는 공통 `[env]` 설정을 자동으로 공유
- 기본값 `default_envs = esp32usb`
- 사용하는 ESP32의 모델에 따라 `board = esp32doit-devkit-v1` 변경
- 이 단계는 USB 업로드로 진행, OTA 실습은 Step 08부터

## 실습 순서
1. 위 브랜치 선택 후 `src/main.cpp` 확인
2. 회로 구성과 GPIO 점검
3. `platformio.ini`의 `board` 및 `esp32usb` 선택 확인
4. Build, Upload 실행
5. Build, Upload 후 회로 동작 관찰
6. LED가 1초 ON/1초 OFF, 500ms 변경 후 속도 비교
7. 코드와 실험 결과 비교 기록

## 검증 기준
- ESP32 빌드·업로드 성공
- LED가 1초 ON/1초 OFF, 500ms 변경 후 속도 비교
- 이전 단계에서 배운 GPIO 기능 이해

## 문제 해결
- USB 업로드 실패: 데이터 케이블, USB 포트, 드라이버, 실제 `board` 설정 확인
- GPIO 동작 실패: 보드 핀맵, 회로 극성, GND 연결 확인
- LED 출력 실패: 핀 번호와 회로 상태 확인

## 주의사항 및 추가 실습
- GPIO2 내장 LED 존재 여부는 보드마다 상이
- 사용자 계정, OTA 비밀번호, 개인키 등 비밀 정보는 공개 저장소에 커밋하지 않기
- 코드의 시간/핀 설정을 변경해 동작 비교
