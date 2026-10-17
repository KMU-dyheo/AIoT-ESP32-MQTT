# Step 13 — AWS IoT LED 원격 제어

## 시작/완료 브랜치
- 시작: `step-13-aws-iot-control` (이전 단계 완성 코드 + TODO)
- 완성: `step-13-aws-iot-control-done` (이번 단계 구현 결과)

## 실습 목표
- AWS IoT MQTT 테스트 클라이언트에서 led/set ON/OFF 발행하고 LED 제어 확인
- 이전 단계와 달라진 점을 관찰하고 설명

## 실습 준비
- ESP32 DevKit, USB 데이터 케이블, PlatformIO/VS Code
- LED/버튼, Wi-Fi, AWS IoT Core 계정·장치 인증서
- 시작 브랜치: `git switch step-13-aws-iot-control`

## 회로 및 설정
- LED: GPIO18 → 저항 → LED (+), LED (-) → GND; 버튼: GPIO19 ↔ GND
- AWS에서 명령/상태 토픽 권한 및 Subscribe/Receive 권한 확인

## 이번 단계에서 변경되는 코드
- AWS에서 수신한 원격 LED 명령을 검증하고 상태 토픽 확인
- 전체 코드: `src/main.cpp`
- 변경 결과를 이전 브랜치와 비교: `git diff step-13-aws-iot-control..step-13-aws-iot-control-done -- src/main.cpp`

## PlatformIO 설정
- `platformio.ini`에서 `[env]`에 공통 설정(`platform`, `board`, `board_build.mcu = esp32`, `board_build.f_cpu = 240000000L`, `framework`, `monitor_speed`; 외부 라이브러리는 필요한 단계에서 `lib_deps`) 배치
- `[env:esp32usb]`와 `[env:esp32ota]`는 공통 `[env]` 설정을 자동으로 공유
- 기본값 `default_envs = esp32usb`
- 사용하는 ESP32의 모델에 따라 `board = esp32doit-devkit-v1` 변경
- `[env]`의 `lib_deps`에 `cyijun/ESP32MQTTClient@^1.1.3` 및 `bblanchon/ArduinoJson` 지정; TLS는 `setCaCert`/`setClientCert`/`setKey` 사용

## 실습 순서
1. 위 브랜치 선택 후 `src/main.cpp` 확인
2. 회로 구성과 GPIO 점검
3. `platformio.ini`의 `board` 및 `esp32usb` 선택 확인
4. Wi-Fi/MQTT 설정 파일과 AWS 인증서 예제 파일을 실사용 .h로 복사하고 실제 인증서/엔드포인트 설정
5. USB Build/Upload 후 Serial Monitor(115200) 및 네트워크 연결 상태 확인
6. AWS 콘솔에서 ON/OFF 명령 전송 후 LED 반응 및 상태 갱신 확인
7. 코드와 실험 결과 비교 기록

## 검증 기준
- ESP32 빌드·업로드 성공
- AWS 콘솔에서 ON/OFF 명령 전송 후 LED 반응 및 상태 갱신 확인
- 네트워크 연결 실패 시에도 로컬 LED/버튼 루프가 계속 실행

## 문제 해결
- USB 업로드 실패: 데이터 케이블, USB 포트, 드라이버, 실제 `board` 설정 확인
- Wi-Fi 연결 실패: SSID/인증 방식/네트워크 분리·방화벽 확인
- MQTT 접속 실패: 브로커 주소, 포트, Client ID, 정책 및 토픽 확인

## 주의사항 및 추가 실습
- AWS에서 명령/상태 토픽 권한 및 Subscribe/Receive 권한 확인
- 사용자 계정, OTA 비밀번호, 개인키 등 비밀 정보는 공개 저장소에 커밋하지 않기
- 네트워크 연결을 끊어 로컬 기능 유지 및 재연결 시험

## 강의노트 연계
- 강의노트 25~50쪽의 IoT 클라우드 구성과 45~46쪽의 MQTT 브로커 통신을 연결. AWS IoT Core 인증서 절차는 강의노트 외 실습.
- [전체 강의노트–실습 대응표](lecture-alignment.md) 참고

## 이번 단계 새 과제: JSON 데이터 교환
- Step 12에는 이미 일반 문자열 `ON`/`OFF` 명령 수신과 LED 제어가 포함되어 있음
- 이번 단계에는 `ArduinoJson`을 활용해 `{"state":"ON"}`/`{"state":"OFF"}` 명령을 추가
- 응답 `led/state`는 `device`, `led`, `brightness`, `uptime_ms` 필드를 갖는 JSON으로 전환
- 이전 문자열 명령은 계속 수용; AWS MQTT 테스트 클라이언트에서 두 형식을 비교
- 강의노트 11쪽의 반정형 데이터 설명과 연결한 실습이며, JSON 프로그래밍 예시는 강의노트 본문에 없음
