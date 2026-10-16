# Step 12 실습 — AWS IoT Core TLS 연결

## 실습 목적
- AWS IoT Core TLS 연결 기능 구현
- 이전 단계의 LED Dimming, 버튼 입력, Wi-Fi/OTA 기능 유지

## 준비물
- ESP32 DevKit, LED(220~330Ω 저항), 버튼, USB 케이블
- VS Code + PlatformIO, Wi-Fi
- AWS IoT Core 사물, X.509 인증서 및 MQTT 테스트 클라이언트

## 회로
- GPIO18 → 저항 → LED 애노드(+), LED 캐소드(-) → GND
- GPIO19 → 버튼 → GND (INPUT_PULLUP)

## 실습 절차
1. `git switch step-12-aws-iot-connect` 실행
2. `include/wifi_config.example.h`를 `include/wifi_config.h`로 복사 후 실제 Wi-Fi 설정
3. `include/mqtt_config.example.h`를 `include/mqtt_config.h`로 복사 후 MQTT 토픽 및 고유 Client ID 설정
4. `include/aws_certificates.example.h`를 `include/aws_certificates.h`로 복사하고 AWS 엔드포인트/Root CA/인증서/개인키 설정
4. `platformio.ini`의 `board`, `default_envs` 확인
5. USB 업로드 후 시리얼 모니터 확인
6. AWS IoT Core에서 인증서·정책 활성화 및 TLS MQTT 연결 확인
7. 네트워크 연결을 끊고 로컬 LED/버튼 동작 유지 확인

## PlatformIO 설정
- `[env:default]`: 보드 및 공통 `lib_deps` 관리
- `lib_deps = knolleary/PubSubClient @ ^2.8`
- `[env:esp32usb]`, `[env:esp32ota]`는 `extends = env:default`
- OTA는 실제 IP 주소와 비밀번호 설정 후 사용

## 검증 기준
- USB 업로드 성공
- AWS IoT Core TLS 연결 성공
- 네트워크 장애 시에도 로컬 기능 유지

## 문제 해결
- MQTT 연결 실패: PC IP, 방화벽, 브로커 리스너/인증 확인
- AWS 연결 실패: TLS 인증서, 엔드포인트, NTP, 정책 권한 확인
- LED 반응 없음: GPIO18 배선 및 led/set 토픽 확인

## 추가 실습
- 토픽의 장치 ID를 학생별로 변경
- 연결 실패 후 재접속되는 과정 관찰
