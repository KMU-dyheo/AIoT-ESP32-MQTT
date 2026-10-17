# Step 01 — 내장 LED 디지털 출력

## 학습 목표
GPIO2를 OUTPUT으로 설정하고 HIGH/LOW를 delay(1000)으로 토글

## 수업 시작·완료 코드
- **시작**: `git switch step-01-onboard-led` — 프로젝트 골격와 이 단계 TODO
- **완료**: `git switch step-01-onboard-led-done` — 이 단계 기능까지 구현
- 비교: `git diff step-01-onboard-led..step-01-onboard-led-done -- src/main.cpp platformio.ini include/`
- Step 01의 시작 소스에는 이 단계 완성 기능을 미리 넣지 않음

## 연결 및 준비
- 회로: 내장 LED(GPIO2; 보드에 따라 유무·핀 번호가 다름)
- Arduino/PlatformIO의 실제 보드 설정과 USB 포트를 확인

## 이번 수업에서 변경하는 코드
- 핵심 구현: `pinMode(LED_PIN, OUTPUT); digitalWrite(LED_PIN, HIGH/LOW); delay(1000)`
- 직전 완료 단계의 기능을 제거하지 않고, 이번 개념만 점진적으로 추가
- 개념: Digital GPIO와 출력 상태

## 실습 순서
1. 수업 시작 브랜치로 이동하고 `src/main.cpp`의 TODO 읽기
2. 새로 필요한 회로·설정·라이브러리만 추가
3. 핵심 로직 구현 후 `pio run -e esp32usb`로 빌드
4. ESP32를 USB로 업로드하고 시리얼 모니터(`115200`) 확인
5. 보드 내장 LED가 1초 켜지고 1초 꺼짐
6. 완료 브랜치와 `git diff`로 구현 차이를 비교

## 검증 기준
- **필수 동작**: 보드 내장 LED가 1초 켜지고 1초 꺼짐
- Step 04 이후: 루프에서 불필요한 `delay()` 없이 PWM 동작 유지
- Step 08 이후: 네트워크가 끊겨도 `updateButton()`·`updateBrightness()` 동작 유지
- MQTT 이전 단계는 MQTT 헤더·접속 코드·라이브러리를 추가하지 않음

## 문제 해결
- LED가 동작하지 않으면 GPIO25, GND 공통 접지, 저항, LED 극성을 확인
- 버튼 값이 반대로 보이면 `INPUT_PULLUP`에서 LOW=눌림인지 확인
- MQTT 연결 실패 시 PC 브로커 리스너·방화벽·IP 주소 및 Client ID 중복 확인
- AWS 연결 실패 시 장치 정책, endpoint, X.509 인증서, NTP 시각 동기화 확인

## 강의노트 연계
- Step 01~07: 로컬 입력·출력, 신호처리, 비차단 제어로 IoT 데이터 수집·에지 처리 체험
- Step 08: 에지의 독립적 기능과 클라우드 네트워크 연결 구분
- Step 09~11: 첨부된 버튼 실습 흐름의 Broker → 버튼 Publish → LED Publish → Subscribe 단계 적용
- Step 12~13: 별도 클라우드·JSON 확장 실습. 기본 MQTT 100분 수업 이후에 배치
- [강의노트 대응표](lecture-alignment.md) 참고

## 공통 하드웨어 및 PlatformIO 기준
- 실제 사용 보드: `esp32doit-devkit-v1`, ESP32 240MHz, Arduino Framework, Serial 115200
- LED: Step 01은 내장 GPIO2, Step 02부터 외부 GPIO25 + 220~330Ω 직렬저항
- 버튼: Step 05부터 GPIO23 ↔ GND, `INPUT_PULLUP`; 눌림 LOW, 해제 HIGH
- `[platformio]` 기본 `esp32usb`; `[env]`에 공통 설정; `[env:esp32ota]`는 Step 08부터 실제 활용
- 사용자가 제공한 강의 흐름 기준. 학생의 C++ 표현 방식은 제한하지 않음

