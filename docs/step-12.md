# Step 12 — AWS IoT TLS 인증 연결

## 실습 목표
- WiFiClientSecure로 Root CA/장치 인증서/개인키 설정 후 AWS IoT Core 8883 접속
- 이전 단계와 달라진 점을 관찰하고 설명

## 실습 준비
- ESP32 DevKit, USB 데이터 케이블, PlatformIO/VS Code
- LED/버튼, Wi-Fi, AWS IoT Core 계정·장치 인증서
- 시작 브랜치: `git switch step-12-aws-iot-connect`

## 회로 및 설정
- LED: GPIO18 → 저항 → LED (+), LED (-) → GND; 버튼: GPIO19 ↔ GND
- IoT 정책과 인증서 활성화, 서버 Root CA, 정확한 endpoint, 시간 동기화 필요

## 이번 단계에서 변경되는 코드
- WiFiClient에서 WiFiClientSecure로 변경, AWS 인증서 및 NTP 추가; AWS 연결에 집중
- 전체 코드: `src/main.cpp`
- 변경 결과를 이전 브랜치와 비교: `git diff step-11-mqtt-control..step-12-aws-iot-connect -- src/main.cpp`

## PlatformIO 설정
- `platformio.ini`에서 `[env:default]`에 공통 설정(`platform`, `board`, `framework`, `monitor_speed`, `lib_deps`) 배치
- `[env:esp32usb]`와 `[env:esp32ota]`는 `extends = env:default`로 상속
- 기본값 `default_envs = esp32usb`
- 사용하는 ESP32의 모델에 따라 `board = esp32dev` 변경
- 공통 MQTT 라이브러리 PubSubClient, TLS는 WiFiClientSecure 사용

## 실습 순서
1. 위 브랜치 선택 후 `src/main.cpp` 확인
2. 회로 구성과 GPIO 점검
3. `platformio.ini`의 `board` 및 `esp32usb` 선택 확인
4. Wi-Fi/MQTT 설정 파일과 AWS 인증서 예제 파일을 실사용 .h로 복사하고 실제 인증서/엔드포인트 설정
5. USB Build/Upload 후 Serial Monitor(115200) 및 네트워크 연결 상태 확인
6. AWS IoT MQTT 테스트 클라이언트에서 연결/상태 발행 확인
7. 코드와 실험 결과 비교 기록

## 검증 기준
- ESP32 빌드·업로드 성공
- AWS IoT MQTT 테스트 클라이언트에서 연결/상태 발행 확인
- 네트워크 연결 실패 시에도 로컬 LED/버튼 루프가 계속 실행

## 문제 해결
- USB 업로드 실패: 데이터 케이블, USB 포트, 드라이버, 실제 `board` 설정 확인
- Wi-Fi 연결 실패: SSID/인증 방식/네트워크 분리·방화벽 확인
- MQTT 접속 실패: 브로커 주소, 포트, Client ID, 정책 및 토픽 확인

## 주의사항 및 추가 실습
- IoT 정책과 인증서 활성화, 서버 Root CA, 정확한 endpoint, 시간 동기화 필요
- 사용자 계정, OTA 비밀번호, 개인키 등 비밀 정보는 공개 저장소에 커밋하지 않기
- 네트워크 연결을 끊어 로컬 기능 유지 및 재연결 시험
