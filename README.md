# Step 08 — Wi-Fi 및 OTA (완성 코드)

## 실습 목적
- 로컬 LED/버튼 동작과 네트워크 기능 분리
- `setupApplication()`, `loopApplication()`으로 코드 구조 확장
- WPA2-Personal 및 WPA2-Enterprise(PEAP) 연결 방식 비교
- USB/OTA 업로드 방식 이해

## 준비물
- ESP32 DevKit, LED+저항, 버튼, Wi-Fi 네트워크, PlatformIO
- 개인용 또는 기업용 Wi-Fi 접속 정보

## 핵심 개념
- `setup()`과 `loop()`는 Wi-Fi 및 OTA를 관리
- `setupApplication()`과 `loopApplication()`은 로컬 LED/버튼 기능 관리
- Wi-Fi 접속에 실패해도 LED/버튼은 동작
- `WIFI_ENTERPRISE = 0`: 개인용 WPA2-Personal
- `WIFI_ENTERPRISE = 1`: 기업용 WPA2-Enterprise(PEAP, 사용자 이름/비밀번호)
- Wi-Fi 연결 시도는 반복 루프를 막지 않고 진행
- 기업망은 인증서 검증 정책과 EAP 방식에 따라 추가 설정이 필요할 수 있음

## 학생 수행 과제
- [ ] `git switch step-08-wifi` 실행
- [ ] `include/wifi_config.example.h`를 `include/wifi_config.h`로 복사
- [ ] SSID, 비밀번호, OTA 호스트 이름과 비밀번호 설정
- [ ] 개인용 Wi-Fi에서는 `WIFI_ENTERPRISE 0` 설정
- [ ] 기업용 Wi-Fi에서는 `WIFI_ENTERPRISE 1` 설정 및 계정 입력
- [ ] USB 업로드 후 시리얼 모니터에서 IP 확인
- [ ] Wi-Fi를 끊고 LED/버튼이 계속 동작하는지 확인
- [ ] OTA 업로드를 사용하려면 `platformio.ini`의 `upload_port`를 실제 IP로 변경

## PlatformIO 설정
- `[env]`: 보드/프레임워크/공통 라이브러리 설정
- `[env:esp32usb]`: 공통 `[env]` 자동 상속, USB 업로드
- `[env:esp32ota]`: 공통 `[env]` 자동 상속, OTA 업로드
- `default_envs = esp32usb` 유지
- OTA는 USB로 Wi-Fi/ArduinoOTA 코드가 먼저 설치되어 있어야 사용 가능
- OTA 비밀번호는 `upload_flags = --auth=...` 설정 또는 업로드 시 입력 방법 확인
- `lib_deps`는 아직 추가 외부 라이브러리 없음

## 검증 기준
- USB 업로드 성공, IP 출력
- Wi-Fi 연결/해제 중 LED Dimming 및 버튼 동작 유지
- OTA 설정이 완료된 환경에서 무선 업로드 가능

## 주의사항
- `wifi_config.h`는 Git에 등록하지 않음
- 기업용 Wi-Fi는 PEAP 외 EAP-TLS 등을 요구할 수 있어 본 예제로 연결되지 않을 수 있음
- ESP32 Arduino Core 버전에 따라 기업용 Wi-Fi API가 다름. 본 코드는 Core 2.0.17 기준
- OTA 인증 비밀번호와 실제 계정 정보를 공개 저장소에 기록하지 않음
- OTA 업로드 시 PC와 ESP32 사이 네트워크 경로 및 방화벽 확인

## 브랜치 사용
- [수업 시작 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-08-wifi-start): 이전 단계 완성 코드와 이번 과제 TODO
- 현재 브랜치: Step 08 수업 종료 완성 코드
- 실습 안내: `docs/step-08.md`
- 보드: `esp32doit-devkit-v1`, MCU ESP32, CPU 240MHz
- 공통 PlatformIO 설정은 `[env]`에 두고 `esp32usb`, `esp32ota`가 자동 공유
- 추가 MQTT 라이브러리 미사용
