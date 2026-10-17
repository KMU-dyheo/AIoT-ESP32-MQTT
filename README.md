# AIoT ESP32 단계별 실습

PlatformIO + Arduino Framework 기반 ESP32 교육 저장소.

## 브랜치 규칙

- **수업 시작**: `step-XX-기능명` (접미사 없음). 이전 단계에서 완성한 동작을 유지하고 이번 실습의 TODO 제공.
- **수업 완료**: `step-XX-기능명-done`. 현재 단계에서 구현해야 하는 기능까지 포함.
- **서브스텝**: 필요할 때 `step-09-01-mqtt-topic` / `step-09-01-mqtt-topic-done`처럼 하위 번호 부여. 서브스텝을 추가해도 같은 시작/완료 규칙 적용.
- 기존 `-start`, `-complete` 브랜치는 과거 링크 호환용이며 **새로운 수업에서는 사용하지 않음**.
- 각 단계의 `docs/step-XX.md`는 공통 실습 설명서이며, `README.md`는 체크아웃한 브랜치에 맞는 시작 또는 완료 안내서.

## 전체 13단계

| Step | 수업 시작 | 수업 완료 | 핵심 기능 | 학습 문서 |
|---|---|---|---|---|
| 01 | [`step-01-onboard-led`](../../tree/step-01-onboard-led) | [`step-01-onboard-led-done`](../../tree/step-01-onboard-led-done) | 내장 LED 점멸 | [실습 문서](docs/step-01.md) |
| 02 | [`step-02-external-led`](../../tree/step-02-external-led) | [`step-02-external-led-done`](../../tree/step-02-external-led-done) | 외부 LED 출력 | [실습 문서](docs/step-02.md) |
| 03 | [`step-03-led-pwm`](../../tree/step-03-led-pwm) | [`step-03-led-pwm-done`](../../tree/step-03-led-pwm-done) | PWM 밝기 제어 | [실습 문서](docs/step-03.md) |
| 04 | [`step-04-led-nonblocking`](../../tree/step-04-led-nonblocking) | [`step-04-led-nonblocking-done`](../../tree/step-04-led-nonblocking-done) | millis() 비차단 PWM | [실습 문서](docs/step-04.md) |
| 05 | [`step-05-button`](../../tree/step-05-button) | [`step-05-button-done`](../../tree/step-05-button-done) | 버튼 상태 수집 | [실습 문서](docs/step-05.md) |
| 06 | [`step-06-button-nonblocking`](../../tree/step-06-button-nonblocking) | [`step-06-button-nonblocking-done`](../../tree/step-06-button-nonblocking-done) | 버튼 디바운싱 | [실습 문서](docs/step-06.md) |
| 07 | [`step-07-button-led`](../../tree/step-07-button-led) | [`step-07-button-led-done`](../../tree/step-07-button-led-done) | 버튼→LED 로컬 제어 | [실습 문서](docs/step-07.md) |
| 08 | [`step-08-wifi`](../../tree/step-08-wifi) | [`step-08-wifi-done`](../../tree/step-08-wifi-done) | Wi-Fi 및 OTA | [실습 문서](docs/step-08.md) |
| 09 | [`step-09-mqtt-connect`](../../tree/step-09-mqtt-connect) | [`step-09-mqtt-connect-done`](../../tree/step-09-mqtt-connect-done) | 로컬 MQTT 브로커 연결 | [실습 문서](docs/step-09.md) |
| 10 | [`step-10-mqtt-publish`](../../tree/step-10-mqtt-publish) | [`step-10-mqtt-publish-done`](../../tree/step-10-mqtt-publish-done) | 버튼/LED 메시지 발행 | [실습 문서](docs/step-10.md) |
| 11 | [`step-11-mqtt-control`](../../tree/step-11-mqtt-control) | [`step-11-mqtt-control-done`](../../tree/step-11-mqtt-control-done) | MQTT LED 제어 | [실습 문서](docs/step-11.md) |
| 12 | [`step-12-aws-iot-connect`](../../tree/step-12-aws-iot-connect) | [`step-12-aws-iot-connect-done`](../../tree/step-12-aws-iot-connect-done) | AWS IoT Core 인증서 연결 | [실습 문서](docs/step-12.md) |
| 13 | [`step-13-aws-iot-control`](../../tree/step-13-aws-iot-control) | [`step-13-aws-iot-control-done`](../../tree/step-13-aws-iot-control-done) | AWS IoT 원격 제어 | [실습 문서](docs/step-13.md) |

## 실습 시작 예시

```bash
git clone https://github.com/KMU-dyheo/AIoT-ESP32-MQTT.git
cd AIoT-ESP32-MQTT
git switch step-01-onboard-led
```

학생은 시작 브랜치의 TODO를 구현하고, 수업 종료 후 동일 Step의 `-done`과 비교.

```bash
git diff step-01-onboard-led..step-01-onboard-led-done -- src/main.cpp
```

## 단계별 코드 누적 원칙

- Step 01~07: `setup()` / `loop()`를 직접 사용. GPIO → PWM → `millis()` → 버튼 → 로컬 제어 순서.
- Step 08: 이전 로컬 기능을 `setupApplication()` / `loopApplication()`으로 옮기고 Wi-Fi/OTA를 도입.
- Step 09~11: 로컬 Mosquitto 브로커 연결 → 발행 → 원격 LED 제어를 각각 도입.
- Step 12~13: AWS IoT Core X.509 TLS 연결 → AWS 원격 제어.
- **각 시작 브랜치에는 이번 단계 완성 기능을 미리 넣지 않음**. 다음 단계의 라이브러리와 개인 설정도 조기에 추가하지 않음.
- Wi-Fi/MQTT/AWS가 동작하지 않아도 로컬 LED와 버튼 처리는 지속할 수 있도록 분리.
- `docs/`에는 미래 단계의 자료가 미리 포함되어도 소스는 현재 단계 범위를 넘지 않음.

## PlatformIO 공통 설정

- `[env]`: `board = esp32doit-devkit-v1`, `board_build.mcu = esp32`, `board_build.f_cpu = 240000000L`, `framework = arduino`, `monitor_speed = 115200`.
- `[env:esp32usb]` / `[env:esp32ota]`: 업로드 프로토콜만 개별 설정. 두 프로필은 공통 `[env]`를 자동 공유.
- Step 09 이후부터 `[env]`의 `lib_deps`에 `cyijun/ESP32MQTTClient@^1.1.3`, `bblanchon/ArduinoJson` 포함.
- `include/wifi_config.h`, `include/mqtt_config.h`, `include/aws_certificates.h` 등 실제 계정·인증서 파일은 Git에서 제외.

## 강의노트와 실습의 관계

[강의노트-실습 대응표](docs/lecture-alignment.md) 참고.
첨부 강의노트 「IoT기초 - IOT 빅데이터」는 빅데이터(3~24쪽), 클라우드(25~50쪽), MQTT 브로커·Pub/Sub·QoS(45~46쪽), 에지/포그(51~81쪽)를 설명함. ESP32/PlatformIO 단계별 코딩 예제는 별도로 수록되어 있지 않으므로, 위 실습은 강의노트의 개념과 연결해 구성한 실습 과정임.

## 빌드 검증

`.github/workflows/platformio-build.yml`은 기본 13개 브랜치와 각 `-done` 브랜치, 총 26개 빌드를 검사함. CI 통과는 USB 펌웨어 컴파일 성공을 뜻하며 실제 하드웨어, Wi-Fi, OTA, MQTT, AWS IoT 동작을 보증하지 않음.
