# Step 08 — Wi-Fi 및 OTA

## 시작/완료 브랜치
- 시작: `step-08-wifi` (이전 단계 완성 코드 + TODO)
- 완성: `step-08-wifi-done` (이번 단계 구현 결과)

## 실습 목표
- 로컬 기능을 setupApplication/loopApplication으로 분리, 비차단 Wi-Fi 재연결/ArduinoOTA 처리
- 이전 단계와 달라진 점을 관찰하고 설명

## 실습 준비
- ESP32 DevKit, USB 데이터 케이블, PlatformIO/VS Code
- GPIO18 LED/저항, GPIO19 버튼, Wi-Fi 접속 정보
- 시작 브랜치: `git switch step-08-wifi`

## 회로 및 설정
- LED: GPIO18 → 저항 → LED (+), LED (-) → GND; 버튼: GPIO19 ↔ GND
- 개인용 WPA2-Personal과 기업용 WPA2-Enterprise(PEAP) 중 접속 방식 설정; 학교망의 인증/CA 정책 확인

## 이번 단계에서 변경되는 코드
- wifi_config.h, ArduinoOTA, connectWifi, setupApplication/loopApplication, esp32ota 사용 가능
- 전체 코드: `src/main.cpp`
- 변경 결과를 이전 브랜치와 비교: `git diff step-08-wifi..step-08-wifi-done -- src/main.cpp`

## PlatformIO 설정
- `platformio.ini`에서 `[env]`에 공통 설정(`platform`, `board`, `board_build.mcu = esp32`, `board_build.f_cpu = 240000000L`, `framework`, `monitor_speed`; 외부 라이브러리는 필요한 단계에서 `lib_deps`) 배치
- `[env:esp32usb]`와 `[env:esp32ota]`는 공통 `[env]` 설정을 자동으로 공유
- 기본값 `default_envs = esp32usb`
- 사용하는 ESP32의 모델에 따라 `board = esp32doit-devkit-v1` 변경
- OTA 사용 시 ESP32 IP 주소와 인증 비밀번호를 로컬에서 설정

## 실습 순서
1. 위 브랜치 선택 후 `src/main.cpp` 확인
2. 회로 구성과 GPIO 점검
3. `platformio.ini`의 `board` 및 `esp32usb` 선택 확인
4. include/wifi_config.example.h를 include/wifi_config.h로 복사하고 실제 Wi-Fi/OTA 계정 정보 입력
5. USB Build/Upload 후 Serial Monitor(115200) 및 네트워크 연결 상태 확인
6. 네트워크 끊김 중에도 버튼/LED 동작, 연결 시 IP 출력 및 OTA 업로드
7. 코드와 실험 결과 비교 기록

## 검증 기준
- ESP32 빌드·업로드 성공
- 네트워크 끊김 중에도 버튼/LED 동작, 연결 시 IP 출력 및 OTA 업로드
- 네트워크 연결 실패 시에도 로컬 LED/버튼 루프가 계속 실행

## 문제 해결
- USB 업로드 실패: 데이터 케이블, USB 포트, 드라이버, 실제 `board` 설정 확인
- Wi-Fi 연결 실패: SSID/인증 방식/네트워크 분리·방화벽 확인
- LED 출력 실패: 핀 번호와 회로 상태 확인

## 주의사항 및 추가 실습
- 개인용 WPA2-Personal과 기업용 WPA2-Enterprise(PEAP) 중 접속 방식 설정; 학교망의 인증/CA 정책 확인
- 사용자 계정, OTA 비밀번호, 개인키 등 비밀 정보는 공개 저장소에 커밋하지 않기
- 네트워크 연결을 끊어 로컬 기능 유지 및 재연결 시험

## 강의노트 연계
- 강의노트 25~44쪽은 클라우드, 51~58쪽은 에지 컴퓨팅의 역할을 설명. Wi-Fi/OTA 및 로컬 기능 분리는 이를 체험하기 위해 추가한 실습.
- [전체 강의노트–실습 대응표](lecture-alignment.md) 참고
