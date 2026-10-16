# Step 12 — AWS IoT Core TLS 연결

## 실습 목적
- AWS IoT Core 엔드포인트에 X.509 인증서로 TLS MQTT 연결
- 로컬 LED Dimming/버튼, Wi-Fi 및 OTA 기능 유지
- 네트워크 오류가 발생해도 로컬 기능은 계속 실행

## 준비물
- ESP32 DevKit, LED, 저항, 버튼, PlatformIO
- AWS IoT Core 사물, X.509 인증서, 정책, MQTT 테스트 클라이언트

## 핵심 개념
- `setupApplication()` / `loopApplication()`에서 로컬 기능 유지
- `WiFiClientSecure`로 TLS 연결
- NTP 시간 동기화 후 서버 인증서 검증
- MQTT subscribe/publish와 LED 명령 콜백
- AWS IoT Core의 인증서 활성화 및 IoT 정책 권한 필요

## 학생 수행 과제
- [ ] `git switch step-12-aws-iot-connect` 실행
- [ ] `include/wifi_config.example.h` → `include/wifi_config.h` 복사 후 설정
- [ ] `include/mqtt_config.example.h` → `include/mqtt_config.h` 복사 후 토픽/Client ID 설정
- [ ] `include/aws_certificates.example.h` → `include/aws_certificates.h` 복사 후 엔드포인트, Root CA, 디바이스 인증서, 개인키 입력
- [ ] AWS IoT Core에 사물, 인증서, IoT 정책 설정
- [ ] USB 업로드 및 시리얼 모니터 확인
- [ ] AWS IoT Core 엔드포인트에 X.509 인증서로 TLS MQTT 연결
- [ ] Wi-Fi가 끊겨도 로컬 LED/버튼 동작하는지 확인

## PlatformIO 설정
- `[env:default]`: 공통 `platform`, `board`, `framework`, `monitor_speed`, `lib_deps`
- `lib_deps = knolleary/PubSubClient @ ^2.8`
- `[env:esp32usb]`와 `[env:esp32ota]`는 `extends = env:default` 상속
- OTA의 `upload_port`는 실제 ESP32 IP로 변경

## 검증 기준
- 빌드 및 업로드 성공
- AWS IoT Core 엔드포인트에 X.509 인증서로 TLS MQTT 연결
- 연결 실패 시 로컬 동작 유지

## 주의사항
- 인증서, 개인키, 비밀번호를 공개 Git 저장소에 등록하지 않음
- AWS IoT 정책의 Connect, Publish, Subscribe, Receive 권한 확인
- 인증서 검증을 위해 네트워크 시간 동기화 필요
