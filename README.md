# Step 01 — ESP32 내장 LED 제어

## 실습 목적
- ESP32 개발 환경인 PlatformIO의 기본 사용법을 익힌다.
- GPIO 출력의 개념을 이해한다.
- Arduino Framework의 `setup()`, `loop()` 실행 구조를 확인한다.
- 내장 LED를 주기적으로 켜고 끄는 프로그램을 작성한다.

## 준비물
- ESP32 개발 보드, USB 데이터 케이블, PC
- VS Code 및 PlatformIO 확장 프로그램
- 내장 사용자 LED가 없는 보드라면 외부 LED 실습은 Step 02에서 진행한다.

## 핵심 개념
- `setup()`: 부팅 후 한 번 실행되는 초기화 함수
- `loop()`: 초기화 이후 반복 실행되는 함수
- `pinMode()`: GPIO 입출력 모드 지정
- `digitalWrite()`: 디지털 출력 HIGH/LOW 설정
- `millis()`: 부팅 이후 경과 시간(ms) 확인

## 학생 수행 과제
- [ ] 저장소를 복제하고 `step-01-onboard-led` 브랜치로 이동한다.
- [ ] `platformio.ini`의 보드 설정이 실제 보드와 일치하는지 확인한다.
- [ ] 보드의 내장 LED GPIO를 확인하고 `Config::LED_PIN`을 수정한다.
- [ ] 프로그램을 업로드하고 시리얼 모니터(115200)를 실행한다.
- [ ] LED가 0.5초 간격으로 점멸하는지 확인한다.
- [ ] 점멸 주기를 1초로 변경하고 결과를 비교한다.

## 실행 방법
```bash
git clone https://github.com/KMU-dyheo/AIoT-ESP32-MQTT.git
cd AIoT-ESP32-MQTT
git switch step-01-onboard-led
```
- PlatformIO에서 프로젝트를 연다.
- Build, Upload를 실행한다.
- Serial Monitor에서 LED 상태 메시지를 확인한다.

## 검증 기준
- 빌드 및 업로드가 완료된다.
- 내장 LED가 설정한 주기로 ON/OFF 된다.
- 시리얼 모니터에 LED 상태가 출력된다.

## 주의사항
- ESP32 DevKit 종류에 따라 내장 사용자 LED가 없을 수 있다.
- GPIO 2는 모든 보드의 내장 LED 핀이 아니다. 반드시 보드 문서를 확인한다.
- USB 케이블 중 충전 전용 케이블은 업로드에 사용할 수 없다.
- 이 단계에서는 `setupApplication()`과 `loopApplication()`을 사용하지 않는다.
- Wi-Fi 연결 및 MQTT 통신은 이후 단계에서 구현한다.

## 생각해 볼 문제
- `setup()`과 `loop()`의 역할은 어떻게 다른가?
- `digitalWrite()`의 HIGH와 LOW는 어떤 차이가 있는가?
- `delay()` 없이 시간을 비교하는 방식은 어떤 장점이 있는가?
