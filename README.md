# Step 01 — ESP32 내장 LED 제어

## 실습 목적
- PlatformIO에서 ESP32 프로그램을 작성하고 업로드하는 과정을 익힘
- Arduino의 `setup()`, `loop()` 구조 이해
- `pinMode()`, `digitalWrite()`, `delay()`로 LED 제어
- `#define`을 이용한 핀 번호 정의와 함수 호출의 기본 형태 확인

## 준비물
- ESP32 개발 보드, USB 데이터 케이블, PC
- VS Code 및 PlatformIO 확장 프로그램

## 핵심 개념
- `#define LED_PIN 2`: LED 핀 번호를 상수처럼 이름 붙여 사용
- `setup()`: 시작할 때 한 번 실행
- `loop()`: 계속 반복 실행
- `pinMode(LED_PIN, OUTPUT)`: LED 핀을 출력으로 설정
- `digitalWrite(LED_PIN, HIGH)`: LED 켜기(일반적인 액티브 HIGH 회로 기준)
- `digitalWrite(LED_PIN, LOW)`: LED 끄기
- `delay(1000)`: 1000ms(1초) 기다리기

## PlatformIO 설정 파일 수정 (`platformio.ini`)
- 프로젝트 루트의 `platformio.ini` 파일을 열어 다음 항목을 확인

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
```

- `[env:esp32dev]`: 빌드 환경 이름. 다른 이름으로 변경해도 되지만 `board`와 혼동하지 않기
- `platform = espressif32`: ESP32 개발 플랫폼 사용
- `board = esp32dev`: 현재 설정된 보드 ID. **실제 보드에 맞는 ID로 변경**
- `framework = arduino`: Arduino Framework 사용
- `monitor_speed = 115200`: 시리얼 모니터 통신 속도. `Serial.begin(115200)`을 사용하는 단계에서는 같은 값으로 설정
- `upload_port`, `monitor_port`: 자동 인식이 안 될 때만 포트 지정. Windows 예: `COM3`, Linux 예: `/dev/ttyUSB0`, macOS 예: `/dev/cu.usbserial-xxxx`
- 보드 ID는 PlatformIO Boards 목록 또는 실제 보드의 공식 문서에서 확인. 외형이 비슷해도 보드 ID가 다를 수 있음

### 학생 설정 실습
- [ ] 실제 보드 모델 확인 후 `board` 항목 점검 및 필요 시 수정
- [ ] PC에서 USB 포트가 인식되는지 확인
- [ ] 업로드 실패 시 포트 및 USB 케이블 확인
- [ ] `platformio.ini`를 수정한 뒤 다시 Build 및 Upload 실행

## 학생 수행 과제
- [ ] 저장소를 복제하고 `step-01-onboard-led` 브랜치로 이동
- [ ] 위 설명을 참고하여 `platformio.ini`의 `board` 설정 확인 및 필요 시 변경
- [ ] 보드 문서를 보고 `LED_PIN`을 내장 LED 핀 번호로 수정
- [ ] Build 및 Upload 실행
- [ ] LED가 1초 켜지고 1초 꺼지는지 확인
- [ ] `delay(1000)`을 `delay(500)`으로 바꿔 점멸 속도 비교

## 실행 방법
```bash
git clone https://github.com/KMU-dyheo/AIoT-ESP32-MQTT.git
cd AIoT-ESP32-MQTT
git switch step-01-onboard-led
```
- PlatformIO에서 프로젝트 열기
- Build 및 Upload 실행
- 보드의 LED 점멸 확인

## 검증 기준
- 오류 없이 빌드 및 업로드 완료
- LED가 지정한 시간 간격으로 켜지고 꺼짐
- 지연 시간을 바꾸면 점멸 속도도 변경됨

## 주의사항
- 보드에 내장 사용자 LED가 없을 수 있음
- GPIO 2가 모든 ESP32 보드의 LED 핀은 아님
- 일부 보드는 LED의 켜짐/꺼짐 논리가 반대일 수 있음
- USB 충전 전용 케이블로는 업로드할 수 없음
- Step 01~07에서는 `setup()`, `loop()`를 직접 사용
- `millis()`를 이용한 비차단 처리 방식은 Step 04에서 학습
- 핀 번호 및 고정 설정값은 `#define`으로 작성
- `namespace`, `constexpr`, `static` 등은 기초 단계에서 사용하지 않음

## 생각해 볼 문제
- `setup()`과 `loop()`의 차이는?
- `HIGH`와 `LOW`의 의미는?
- `delay(1000)`을 두 번 호출하면 LED 한 주기에 걸리는 시간은?
