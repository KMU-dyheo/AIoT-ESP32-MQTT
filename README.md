# Step 9 — 로컬 MQTT 연결

## 실습 목적
- 학생 PC에서 Mosquitto 실행. ESP32와 PC가 같은 네트워크에서 접근 가능한지 확인. MQTT_HOST는 localhost가 아니라 PC의 실제 IP.
- 이전 단계 LED Dimming, 버튼 디바운싱, Wi-Fi/OTA 동작 유지
- 네트워크 연결 실패 시에도 로컬 LED/버튼 동작 유지

## 준비물
- ESP32 DevKit, LED(저항 포함), 버튼, Wi-Fi, VS Code + PlatformIO
- 학생 PC에 설치한 Mosquitto 브로커 및 MQTT 클라이언트

## 핵심 개념
- `setupApplication()`, `loopApplication()`: 로컬 애플리케이션 로직
- MQTT 연결과 수신 콜백은 별도 함수로 관리
- `mqtt.loop()` 호출과 주기적 재접속으로 메시지 처리
- 학생 PC에서 Mosquitto 실행. ESP32와 PC가 같은 네트워크에서 접근 가능한지 확인. MQTT_HOST는 localhost가 아니라 PC의 실제 IP.

## 학생 수행 과제
- [ ] `git switch step-09-mqtt-connect` 실행
- [ ] `include/wifi_config.example.h`를 `include/wifi_config.h`로 복사하고 설정
- [ ] `include/mqtt_config.example.h`를 `include/mqtt_config.h`로 복사하고 브로커 IP 설정
- [ ] USB 업로드 후 시리얼 모니터에서 연결 상태 확인
- [ ] 학생 PC에서 Mosquitto 실행. ESP32와 PC가 같은 네트워크에서 접근 가능한지 확인. MQTT_HOST는 localhost가 아니라 PC의 실제 IP.
- [ ] Wi-Fi/MQTT 연결을 끊어도 버튼과 LED가 동작하는지 확인

## PlatformIO 설정
- `[env:default]`: 공통 `platform`, `board`, `framework`, `monitor_speed`, `lib_deps` 관리
- `lib_deps = knolleary/PubSubClient @ ^2.8`: MQTT 클라이언트 라이브러리
- `[env:esp32usb]`, `[env:esp32ota]`는 `extends = env:default`로 상속
- OTA IP는 실제 장치 주소로 변경, 비밀번호는 공개 저장소에 기록하지 않음

## 검증 기준
- 정상 빌드 및 업로드
- 학생 PC에서 Mosquitto 실행. ESP32와 PC가 같은 네트워크에서 접근 가능한지 확인. MQTT_HOST는 localhost가 아니라 PC의 실제 IP.
- 네트워크 장애에도 로컬 동작 유지

## 주의사항
- 비밀번호·인증서·개인키는 공개 저장소에 커밋하지 않음
- MQTT 토픽의 장치 ID가 학생별로 충돌하지 않도록 변경
- 브로커 포트 1883의 PC 방화벽 및 접속 허용 범위 확인
