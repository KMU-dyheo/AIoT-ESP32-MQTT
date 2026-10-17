# Step 11 — MQTT LED 원격 제어

## 시작/완성 코드
- 시작: `step-11-mqtt-control-start` (이전 단계 완성 코드 + TODO)
- 완성: `step-11-mqtt-control-complete` (이번 단계 구현 결과)

## 실습 목표
- led/set ON/OFF 수신 후 LED 활성 상태 변경, 변경 상태를 led/state에 발행
- 이전 단계와 달라진 점을 관찰하고 설명

## 실습 준비
- ESP32 DevKit, USB 데이터 케이블, PlatformIO/VS Code
- LED/버튼, Wi-Fi, PC Mosquitto 브로커
- 시작 브랜치: `git switch step-11-mqtt-control-start`

## 회로 및 설정
- LED: GPIO18 → 저항 → LED (+), LED (-) → GND; 버튼: GPIO19 ↔ GND
- MQTT 명령은 ON/OFF 대소문자 정확히 사용; 콜백은 수신 길이 검사

## 이번 단계에서 변경되는 코드
- MQTT 콜백의 ON/OFF 명령 파싱, mqtt.subscribe 추가
- 전체 코드: `src/main.cpp`
- 변경 결과를 이전 브랜치와 비교: `git diff step-11-mqtt-control-start..step-11-mqtt-control-complete -- src/main.cpp`

## PlatformIO 설정
- `platformio.ini`에서 `[env]`에 공통 설정(`platform`, `board`, `board_build.mcu = esp32`, `board_build.f_cpu = 240000000L`, `framework`, `monitor_speed`; 외부 라이브러리는 필요한 단계에서 `lib_deps`) 배치
- `[env:esp32usb]`와 `[env:esp32ota]`는 공통 `[env]` 설정을 자동으로 공유
- 기본값 `default_envs = esp32usb`
- 사용하는 ESP32의 모델에 따라 `board = esp32doit-devkit-v1` 변경
- ESP32MQTTClient 라이브러리를 env:default의 lib_deps에서 관리

## 실습 순서
1. 위 브랜치 선택 후 `src/main.cpp` 확인
2. 회로 구성과 GPIO 점검
3. `platformio.ini`의 `board` 및 `esp32usb` 선택 확인
4. include/wifi_config.example.h와 include/mqtt_config.example.h를 각각 실사용 .h 파일로 복사한 뒤 SSID 및 PC MQTT 브로커 IP 설정
5. USB Build/Upload 후 Serial Monitor(115200) 및 네트워크 연결 상태 확인
6. mosquitto_pub -t class/device01/led/set -m ON/OFF; 상태 메시지 확인
7. 코드와 실험 결과 비교 기록

## 검증 기준
- ESP32 빌드·업로드 성공
- mosquitto_pub -t class/device01/led/set -m ON/OFF; 상태 메시지 확인
- 네트워크 연결 실패 시에도 로컬 LED/버튼 루프가 계속 실행

## 문제 해결
- USB 업로드 실패: 데이터 케이블, USB 포트, 드라이버, 실제 `board` 설정 확인
- Wi-Fi 연결 실패: SSID/인증 방식/네트워크 분리·방화벽 확인
- MQTT 접속 실패: 브로커 주소, 포트, Client ID, 정책 및 토픽 확인

## 주의사항 및 추가 실습
- MQTT 명령은 ON/OFF 대소문자 정확히 사용; 콜백은 수신 길이 검사
- 사용자 계정, OTA 비밀번호, 개인키 등 비밀 정보는 공개 저장소에 커밋하지 않기
- 네트워크 연결을 끊어 로컬 기능 유지 및 재연결 시험
