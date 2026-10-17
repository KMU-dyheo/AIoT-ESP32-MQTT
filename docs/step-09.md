# Step 09 — MQTT Broker 연결

## 학습 목표
ESP32MQTTClient로 Mosquitto Broker 접속; 아직 발행·구독은 하지 않음

## 시작 코드와 완성 코드
- **시작**: `git switch step-09-mqtt-connect` — Step 08 완료 코드와 이 단계 TODO
- **완료**: `git switch step-09-mqtt-connect-done` — 이 단계 기능까지 구현
- 비교: `git diff step-09-mqtt-connect..step-09-mqtt-connect-done -- src/main.cpp platformio.ini include/`

## 연결 및 준비
- 회로: GPIO23 버튼, GPIO25 LED, 같은 네트워크 PC Mosquitto
- Arduino/PlatformIO의 실제 보드 설정과 USB 포트를 확인
- 개인 Wi-Fi 또는 WPA2-Enterprise 연결정보는 `include/wifi_config.example.h`를 복사한 비공개 `wifi_config.h`에 입력
- MQTT 접속정보는 `include/mqtt_config.example.h`의 예시를 복사한 비공개 `mqtt_config.h`에 입력; `MQTT_HOST`는 브로커 PC의 실제 IP

## 구현 내용
- 핵심 구현: `mqttClient.setURL(MQTT_HOST, MQTT_PORT), onMqttConnect(), handleMQTT(), serviceMqtt()`
- 개념: Broker, Client, Topic, Pub/Sub 구조

## 실습 순서
1. 수업 시작 브랜치로 이동하고 `src/main.cpp`의 TODO 읽기
2. 새로 필요한 회로·설정·라이브러리만 추가
3. 핵심 로직 구현 후 `pio run -e esp32usb`로 빌드
4. ESP32를 USB로 업로드하고 시리얼 모니터(`115200`) 확인
5. 브로커에서 Client 접속 확인, 연결 실패에도 로컬 제어 유지
6. 완료 브랜치와 `git diff`로 구현 차이를 비교

## 검증 기준
- **필수 동작**: 브로커에서 Client 접속 확인, 연결 실패에도 로컬 제어 유지
- Step 04 이후: 루프에서 불필요한 `delay()` 없이 PWM 동작 유지
- Step 08 이후: 네트워크가 끊겨도 `updateButton()`·`updateBrightness()` 동작 유지

## 문제 해결
- LED가 동작하지 않으면 GPIO25, GND 공통 접지, 저항, LED 극성을 확인
- 버튼 값이 반대로 보이면 `INPUT_PULLUP`에서 LOW=눌림인지 확인
- MQTT 연결 실패 시 PC 브로커 리스너·방화벽·IP 주소 및 Client ID 중복 확인

## MQTT 메시지 약속
| Topic | 방향 | Payload |
|---|---|---|
| `aiot/esp32-01/button/state` | ESP32 → Broker | `pressed`, `released` |
| `aiot/esp32-01/led/state` | ESP32 → Broker | `on`, `off` (Step 13에서는 JSON) |
| `aiot/esp32-01/led/set` | Broker → ESP32 | `on`, `off` |
- 장치별 고유한 ID와 Topic 접두어 사용; 예시는 `esp32-01`
- 버튼은 안정된 입력 상태가 **변화했을 때만** 발행. 연결이 끊겨 있는 동안의 모든 과거 이벤트 재전송은 기본 예제의 보장 범위 밖임.
- Step 09는 MQTT 연결 단계이므로 아직 Publish/Subscribe를 하지 않음.

## 개발 환경
- 실제 사용 보드: `esp32doit-devkit-v1`, ESP32 240MHz, Arduino Framework, Serial 115200

- LED: GPIO25, 220~330Ω 직렬저항
- 버튼: GPIO23 ↔ GND, `INPUT_PULLUP` (눌림 LOW, 해제 HIGH)
- 빌드: `pio run -e esp32usb`
