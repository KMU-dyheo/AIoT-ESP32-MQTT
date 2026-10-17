# Step 12 — AWS IoT TLS 연결 (수업 완료)

## 실습 목적
- AWS IoT Core 엔드포인트에 X.509 인증서로 TLS MQTT 연결
- 로컬 LED Dimming/버튼, Wi-Fi 및 OTA 기능 유지
- 네트워크 오류가 발생해도 로컬 기능은 계속 실행

## 준비물
- ESP32 DevKit, LED, 저항, 버튼, PlatformIO
- AWS IoT Core 사물, X.509 인증서, 정책, MQTT 테스트 클라이언트

## 핵심 개념
- `setupApplication()` / `loopApplication()`에서 로컬 기능 유지
- `ESP32MQTTClient`의 `setCaCert()` / `setClientCert()` / `setKey()`로 TLS 연결
- NTP 시간 동기화 후 서버 인증서 검증
- MQTT subscribe/publish와 LED 명령 콜백
- AWS IoT Core의 인증서 활성화 및 IoT 정책 권한 필요

## 학생 수행 과제
- [ ] `git switch step-12-aws-iot-connect-done` 실행
- [ ] `include/wifi_config.example.h` → `include/wifi_config.h` 복사 후 설정
- [ ] `include/mqtt_config.example.h` → `include/mqtt_config.h` 복사 후 토픽/Client ID 설정
- [ ] `include/aws_certificates.example.h` → `include/aws_certificates.h` 복사 후 엔드포인트, Root CA, 디바이스 인증서, 개인키 입력
- [ ] AWS IoT Core에 사물, 인증서, IoT 정책 설정
- [ ] USB 업로드 및 시리얼 모니터 확인
- [ ] AWS IoT Core 엔드포인트에 X.509 인증서로 TLS MQTT 연결
- [ ] Wi-Fi가 끊겨도 로컬 LED/버튼 동작하는지 확인

## PlatformIO 설정
- `[env]`: 공통 `platform`, `board`, `framework`, `monitor_speed`, `lib_deps`
- `lib_deps = cyijun/ESP32MQTTClient@^1.1.3`
- `[env:esp32usb]`와 `[env:esp32ota]`는 공통 `[env]` 설정 자동 공유
- OTA의 `upload_port`는 실제 ESP32 IP로 변경

## 검증 기준
- 빌드 및 업로드 성공
- AWS IoT Core 엔드포인트에 X.509 인증서로 TLS MQTT 연결
- 연결 실패 시 로컬 동작 유지

## 주의사항
- 인증서, 개인키, 비밀번호를 공개 Git 저장소에 등록하지 않음
- AWS IoT 정책의 Connect, Publish, Subscribe, Receive 권한 확인
- 인증서 검증을 위해 네트워크 시간 동기화 필요

## 브랜치 사용
- [수업 시작 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-12-aws-iot-connect): 이전 단계 완성 코드와 이번 과제 TODO
- 현재 브랜치: Step 12 수업 종료 완성 코드
- 실습 안내: `docs/step-12.md`
- 보드: `esp32doit-devkit-v1`, MCU ESP32, CPU 240MHz
- 공통 PlatformIO 설정은 `[env]`에 두고 `esp32usb`, `esp32ota`가 자동 공유
- MQTT/JSON 라이브러리: `cyijun/ESP32MQTTClient@^1.1.3`, `bblanchon/ArduinoJson`
- MQTT는 백그라운드 `mqttClient.loopStart()` 방식으로 동작

## 강의 진행 브랜치
- **수업 시작**: [`step-12-aws-iot-connect`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-12-aws-iot-connect)
- **수업 완료**: [`step-12-aws-iot-connect-done`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-12-aws-iot-connect-done)
- 현재 브랜치: **수업 완료 코드**
- 현재 실습 문서: `docs/step-12.md`; 강의노트와의 연결은 `docs/lecture-alignment.md` 참고

## 이전 단계 기능 유지
- Step 11에서 구현한 `led/set` ON/OFF 구독과 LED 제어를 AWS TLS 전환 후에도 유지
- Step 12의 신규 학습 목표는 **서버 변경 및 X.509 인증서 기반 연결**
