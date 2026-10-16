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
- `esp32usb`: USB 케이블로 프로그램 업로드
- `esp32ota`: Wi-Fi를 통해 OTA 업로드. **Step 08 이후 ArduinoOTA 기능을 구현한 다음 사용**
- Step 01~07에서는 `esp32usb`를 사용

```ini
[platformio]
default_envs = esp32usb

[env:default]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200

; 공통 라이브러리는 이후 단계에서 여기에 추가
; lib_deps =

[env:esp32usb]
extends = env:default
upload_protocol = esptool

; OTA는 Step 08 이후 Wi-Fi 및 ArduinoOTA 구현 후 사용
[env:esp32ota]
extends = env:default
upload_protocol = espota
upload_port = 192.168.0.100
```


- `default_envs`: 기본으로 사용할 환경. Step 01에서는 `esp32usb` 지정
- `[env:default]`: 보드, 프레임워크, 공통 라이브러리를 모아두는 기본 설정 프로필
- `extends = env:default`: USB/OTA 환경이 공통 설정을 상속
- `lib_deps`: 외부 라이브러리 목록. Step 01에서는 필요하지 않으므로 주석 처리, 이후 단계에서 추가
- `[platformio] default_envs`: 기본 빌드 환경 선택. `esp32usb`만 기본 실행
- `platform`: ESP32 개발 플랫폼
- `board`: 실제 ESP32 보드에 맞는 ID로 수정
- `framework`: Arduino Framework 사용
- `monitor_speed`: 시리얼 모니터 속도. 시리얼 출력을 사용하는 단계에서 `Serial.begin()`과 일치시킴
- `upload_protocol = esptool`: USB 시리얼 업로드
- `upload_protocol = espota`: OTA 업로드
- `upload_port`: OTA 대상 ESP32의 IP 주소. 위 주소는 예시이므로 실제 주소로 변경
- USB 업로드 포트 자동 감지 실패 시 `esp32usb` 환경에 `upload_port = COM3` 등 실제 포트 지정
- OTA 프로필만 추가해도 OTA가 작동하는 것은 아님. ESP32 코드에서 Wi-Fi 연결과 ArduinoOTA 초기화 및 반복 처리가 필요

### 학생 설정 실습
- [ ] 실제 보드의 모델과 `board` 값 확인
- [ ] `default_envs = esp32usb` 확인
- [ ] `esp32usb`, `esp32ota`에 `extends = env:default`가 있는지 확인
- [ ] 라이브러리 추가가 필요할 때 `env:default`의 `lib_deps`에 작성한다는 점 이해
- [ ] USB 연결 후 `esp32usb` 환경에서 Build 및 Upload 실행
- [ ] `esp32ota`는 향후 사용할 환경임을 이해하고 Step 01에서는 실행하지 않기

## 학생 수행 과제
- [ ] 저장소를 복제하고 `step-01-onboard-led` 브랜치로 이동
- [ ] 위 설명을 참고하여 `platformio.ini`의 `board` 설정 확인 및 필요 시 변경
- [ ] `esp32usb` 프로필로 업로드
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
