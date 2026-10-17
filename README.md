# AIoT ESP32 강의 실습 (GPIO / PWM / Wi-Fi / MQTT)

업로드한 실습 자료의 **GPIO25 LED + GPIO23 버튼, 디바운싱, PWM Fade, updateButton()/updateBrightness()** 구조를 기반으로 단계별 구현.

## 브랜치 사용
- `step-XX-...` = 수업 시작 코드 (전 단계 완료 + 현재 TODO)
- `step-XX-...-done` = 현재 단계 완료 코드
- 서브스텝도 같은 규칙: `step-10-01-button-event` / `step-10-01-button-event-done`
- 기능 도입은 누적식. Wi-Fi는 Step 08, MQTT는 Step 09부터 등장하고 그전에는 MQTT 소스/라이브러리가 없음.

| Step | 시작 브랜치 | 완료 브랜치 | 이번 단계 |
|---|---|---|---|
| 01 | [`step-01-onboard-led`](../../tree/step-01-onboard-led) | [`step-01-onboard-led-done`](../../tree/step-01-onboard-led-done) | 내장 LED 디지털 출력 |
| 02 | [`step-02-external-led`](../../tree/step-02-external-led) | [`step-02-external-led-done`](../../tree/step-02-external-led-done) | 외부 LED 연결 |
| 03 | [`step-03-led-pwm`](../../tree/step-03-led-pwm) | [`step-03-led-pwm-done`](../../tree/step-03-led-pwm-done) | LED PWM Fade |
| 04 | [`step-04-led-nonblocking`](../../tree/step-04-led-nonblocking) | [`step-04-led-nonblocking-done`](../../tree/step-04-led-nonblocking-done) | millis 기반 비차단 Fade |
| 05 | [`step-05-button`](../../tree/step-05-button) | [`step-05-button-done`](../../tree/step-05-button-done) | 버튼 입력 및 로컬 함수 분리 |
| 06 | [`step-06-button-nonblocking`](../../tree/step-06-button-nonblocking) | [`step-06-button-nonblocking-done`](../../tree/step-06-button-nonblocking-done) | 비차단 디바운싱 |
| 07 | [`step-07-button-led`](../../tree/step-07-button-led) | [`step-07-button-led-done`](../../tree/step-07-button-led-done) | 버튼으로 LED Fade 토글 |
| 08 | [`step-08-wifi`](../../tree/step-08-wifi) | [`step-08-wifi-done`](../../tree/step-08-wifi-done) | Wi-Fi 및 OTA, 앱 루프 독립 |
| 09 | [`step-09-mqtt-connect`](../../tree/step-09-mqtt-connect) | [`step-09-mqtt-connect-done`](../../tree/step-09-mqtt-connect-done) | MQTT Broker 연결 |
| 10 | [`step-10-mqtt-publish`](../../tree/step-10-mqtt-publish) | [`step-10-mqtt-publish-done`](../../tree/step-10-mqtt-publish-done) | 이벤트·상태 메시지 발행 |
| 11 | [`step-11-mqtt-control`](../../tree/step-11-mqtt-control) | [`step-11-mqtt-control-done`](../../tree/step-11-mqtt-control-done) | MQTT LED 제어 명령 수신 |
| 12 | [`step-12-aws-iot-connect`](../../tree/step-12-aws-iot-connect) | [`step-12-aws-iot-connect-done`](../../tree/step-12-aws-iot-connect-done) | AWS IoT Core TLS 연결 |
| 13 | [`step-13-aws-iot-control`](../../tree/step-13-aws-iot-control) | [`step-13-aws-iot-control-done`](../../tree/step-13-aws-iot-control-done) | JSON 명령과 상태정보 확장 |
| 10-01 | [`step-10-01-button-event`](../../tree/step-10-01-button-event) | [`step-10-01-button-event-done`](../../tree/step-10-01-button-event-done) | 버튼 pressed/released |
| 10-02 | [`step-10-02-led-state`](../../tree/step-10-02-led-state) | [`step-10-02-led-state-done`](../../tree/step-10-02-led-state-done) | LED on/off retained |

## 시작하기
```bash
git clone https://github.com/KMU-dyheo/AIoT-ESP32-MQTT.git
cd AIoT-ESP32-MQTT
git switch step-05-button
# 구현 후
git diff step-05-button..step-05-button-done -- src/main.cpp
```

## 하드웨어
- Step 01은 ESP32 내장 GPIO2 LED (보드별 내장 LED 유무 확인).
- Step 02부터 외부 **GPIO25** LED, 직렬저항 220~330Ω.
- Step 05부터 **GPIO23** 버튼↔GND, `INPUT_PULLUP`.
- DOIT ESP32 DevKit V1 / CPU 240MHz / Arduino Core 2.x.
- `platformio.ini`: `[env]` 공통값, `esp32usb` 기본 업로드 및 `esp32ota` (Step 08~).

## MQTT 100분 강의
- 브로커 연결: Step 09
- 버튼 상태(눌림/해제) 발행: Step 10-01
- LED Fade 실행/정지 발행: Step 10-02
- Subscribe/Callback/원격 제어: Step 11
- Topic 예시: `aiot/esp32-01/button/state`, `aiot/esp32-01/led/state`, `aiot/esp32-01/led/set`
- Step 12~13 AWS IoT TLS·JSON은 이후 심화 확장으로 구분.

## 참고
- [강의노트–코드 연계](docs/lecture-alignment.md)
- [Step 10-01 버튼 이벤트](docs/step-10-01.md) / [Step 10-02 LED 상태](docs/step-10-02.md)
- `docs/step-01.md`~`docs/step-13.md`는 각 Step의 수업 과제·검증 기준·확장 설명을 수록.
- 학생은 C++ 코드 표현 방식을 자유롭게 선택하며 강사는 예제에서 단순한 Arduino API 중심 구현을 제시.
