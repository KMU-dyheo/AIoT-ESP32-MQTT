# AIoT ESP32 Lab

PlatformIO + Arduino Framework 기반 단계별 ESP32 실습 저장소입니다.

## 실습 브랜치

1. `step-01-onboard-led` — ESP32 내장 LED 제어
2. `step-02-external-led` — 외부 LED 제어
3. `step-03-led-pwm` — PWM LED Dimming
4. `step-04-led-nonblocking` — 비차단 Dimming
5. `step-05-button` — 버튼 읽기
6. `step-06-button-nonblocking` — 비차단 버튼 읽기
7. `step-07-button-led` — 버튼으로 LED 제어
8. `step-08-wifi` — 개인/기업 Wi-Fi 연결
9. `step-09-mqtt-connect` — 로컬 MQTT 연결
10. `step-10-mqtt-publish` — MQTT 데이터 발행
11. `step-11-mqtt-control` — MQTT 원격 제어
12. `step-12-aws-iot-connect` — AWS IoT Core TLS 인증서 연결
13. `step-13-aws-iot-control` — AWS IoT Core 제어

각 브랜치는 이전 단계를 기반으로 누적 확장합니다. `setupApplication()`, `loopApplication()` 인터페이스를 유지합니다.

### 시작하기

```bash
git clone https://github.com/KMU-dyheo/AIoT-ESP32-MQTT.git
cd AIoT-ESP32-MQTT
git switch step-01-onboard-led
```

> ESP32 DevKit의 내장 LED GPIO는 모델에 따라 다르며 내장 LED가 없는 보드도 있습니다. 각 단계의 설정값을 확인하세요.
