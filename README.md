# Step 11 — MQTT LED 제어 (수업 완료)

## 실습 목적
- 버튼 눌림은 button/event, LED 상태는 led/state 토픽에 발행. mosquitto_sub로 수신 확인.
- 이전 단계 LED Dimming, 버튼 디바운싱, Wi-Fi/OTA 동작 유지
- 네트워크 연결 실패 시에도 로컬 LED/버튼 동작 유지

## 준비물
- ESP32 DevKit, LED(저항 포함), 버튼, Wi-Fi, VS Code + PlatformIO
- 학생 PC에 설치한 Mosquitto 브로커 및 MQTT 클라이언트

## 핵심 개념
- `setupApplication()`, `loopApplication()`: 로컬 애플리케이션 로직
- MQTT 연결과 수신 콜백은 별도 함수로 관리
- `mqttClient.loopStart()` 호출과 주기적 재접속으로 메시지 처리
- 버튼 눌림은 button/event, LED 상태는 led/state 토픽에 발행. mosquitto_sub로 수신 확인.

## 학생 수행 과제
- [ ] `git switch step-10-mqtt-publish` 실행
- [ ] `include/wifi_config.example.h`를 `include/wifi_config.h`로 복사하고 설정
- [ ] `include/mqtt_config.example.h`를 `include/mqtt_config.h`로 복사하고 브로커 IP 설정
- [ ] USB 업로드 후 시리얼 모니터에서 연결 상태 확인
- [ ] 버튼 눌림은 button/event, LED 상태는 led/state 토픽에 발행. mosquitto_sub로 수신 확인.
- [ ] Wi-Fi/MQTT 연결을 끊어도 버튼과 LED가 동작하는지 확인

## PlatformIO 설정
- `[env]`: 공통 `platform`, `board`, `framework`, `monitor_speed`, `lib_deps` 관리
- `lib_deps = cyijun/ESP32MQTTClient@^1.1.3`: MQTT 클라이언트 라이브러리
- `[env:esp32usb]`, `[env:esp32ota]`는 공통 `[env]` 자동 상속로 상속
- OTA IP는 실제 장치 주소로 변경, 비밀번호는 공개 저장소에 기록하지 않음

## 검증 기준
- 정상 빌드 및 업로드
- 버튼 눌림은 button/event, LED 상태는 led/state 토픽에 발행. mosquitto_sub로 수신 확인.
- 네트워크 장애에도 로컬 동작 유지

## 주의사항
- 비밀번호·인증서·개인키는 공개 저장소에 커밋하지 않음
- MQTT 토픽의 장치 ID가 학생별로 충돌하지 않도록 변경
- 브로커 포트 1883의 PC 방화벽 및 접속 허용 범위 확인

## 브랜치 사용
- [수업 시작 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-11-mqtt-control): 이전 단계 완성 코드와 이번 과제 TODO
- 현재 브랜치: Step 11 수업 종료 완성 코드
- 실습 안내: `docs/step-11.md`
- 보드: `esp32doit-devkit-v1`, MCU ESP32, CPU 240MHz
- 공통 PlatformIO 설정은 `[env]`에 두고 `esp32usb`, `esp32ota`가 자동 공유
- MQTT/JSON 라이브러리: `cyijun/ESP32MQTTClient@^1.1.3`, `bblanchon/ArduinoJson`
- MQTT는 백그라운드 `mqttClient.loopStart()` 방식으로 동작

## 강의 진행 브랜치
- **수업 시작**: [`step-11-mqtt-control`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-11-mqtt-control)
- **수업 완료**: [`step-11-mqtt-control-done`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-11-mqtt-control-done)
- 현재 브랜치: **수업 완료 코드**
- 현재 실습 문서: `docs/step-11.md`; 강의노트와의 연결은 `docs/lecture-alignment.md` 참고
