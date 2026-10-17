# Step 06 — 비차단 버튼 입력

## 시작/완료 브랜치
- 시작: `step-06-button-nonblocking` (이전 단계 완성 코드 + TODO)
- 완성: `step-06-button-nonblocking-done` (이번 단계 구현 결과)

## 실습 목표
- millis 기반 40ms 디바운싱으로 버튼 입력 중복 최소화
- 이전 단계와 달라진 점을 관찰하고 설명

## 실습 준비
- ESP32 DevKit, USB 데이터 케이블, PlatformIO/VS Code
- GPIO18 LED + 저항 + GPIO19 버튼
- 시작 브랜치: `git switch step-06-button-nonblocking`

## 회로 및 설정
- LED: GPIO18 → 저항 → LED (+), LED (-) → GND; 버튼: GPIO19 ↔ GND
- 물리 접점 채터링을 확인하고 DEBOUNCE_MS 변경 실험

## 이번 단계에서 변경되는 코드
- lastReading/stableButtonState/lastChangeMillis/DEBOUNCE_MS 추가
- 전체 코드: `src/main.cpp`
- 변경 결과를 이전 브랜치와 비교: `git diff step-06-button-nonblocking..step-06-button-nonblocking-done -- src/main.cpp`

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
6. 각 버튼 눌림/해제 이벤트당 로그 한 번 출력
7. 코드와 실험 결과 비교 기록

## 검증 기준
- ESP32 빌드·업로드 성공
- 각 버튼 눌림/해제 이벤트당 로그 한 번 출력
- 이전 단계에서 배운 GPIO 기능 이해

## 문제 해결
- USB 업로드 실패: 데이터 케이블, USB 포트, 드라이버, 실제 `board` 설정 확인
- GPIO 동작 실패: 보드 핀맵, 회로 극성, GND 연결 확인
- LED 출력 실패: 핀 번호와 회로 상태 확인

## 주의사항 및 추가 실습
- 물리 접점 채터링을 확인하고 DEBOUNCE_MS 변경 실험
- 사용자 계정, OTA 비밀번호, 개인키 등 비밀 정보는 공개 저장소에 커밋하지 않기
- 코드의 시간/핀 설정을 변경해 동작 비교

## 강의노트 연계
- 강의노트 18~24쪽의 IoT 데이터 수집·처리 및 51~58쪽의 로컬 피드백 개념과 연결한 실습.
- [전체 강의노트–실습 대응표](lecture-alignment.md) 참고
