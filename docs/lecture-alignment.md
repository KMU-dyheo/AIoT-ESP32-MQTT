# 강의노트·기존 실습과 코드 단계 매핑

## 참고한 프로젝트 원본 자료
- `Butten 입력 실습.txt`: GPIO23 버튼 → 디바운싱 → 토글 → GPIO25 LED PWM, `updateButton()`·`updateBrightness()` 유지; 다음 100분 MQTT 수업 구성안
- `IoT기초 - IOT 빅데이터.pdf`: 빅데이터 데이터 수집·표현, IoT 클라우드, 브로커 기반 MQTT, 에지/포그 개념
- `MQTT PlatformIO 연결 방법.txt`: 밝기 제어와 상태 보고의 개념도(실제 C++ 전체 구현 소스는 포함되지 않음)
- `이론-빅데이터.txt`: IoT 빅데이터 강의 개편 및 클라우드 자료 분리 맥락

## 원본 실습에서 확인한 고정 설계
- **LED GPIO25, 버튼 GPIO23**
- 기존 디바운싱된 버튼 이벤트와 LED PWM Fade를 **삭제하거나 새 로직으로 대체하지 않음**
- 기능 함수 `updateButton()` / `updateBrightness()`는 Wi-Fi·MQTT 이후에도 유지
- 버튼은 눌림과 해제 모두 MQTT 발행: `pressed` / `released`
- 토픽: `aiot/esp32-01/button/state`, `aiot/esp32-01/led/state`, `aiot/esp32-01/led/set`
- MQTT가 실패하더라도 로컬 입력·출력은 계속 동작

## 100분 MQTT 강의의 연결 순서

| 분량 | 원본 실습 흐름 | 구현 브랜치 |
|---|---|---|
| 5분 | 기존 로컬 버튼·PWM·비차단 로직 복습 | Step 07-done / Step 08-done |
| 10분 | 로컬 제어와 원격 IoT 통신 비교 | Step 08-done |
| 10분 | MQTT 특징 | Step 09 시작 |
| 10분 | Broker, Client, Publisher, Subscriber, Topic | Step 09 |
| 10분 | Topic/Payload/QoS/Retain | Step 09~10 |
| 15분 | ESP32와 Broker 연결 | Step 09-done |
| 10분 | 버튼 pressed/released Publish | Step 10-01-done |
| 10분 | LED 상태 on/off Publish | Step 10-02-done |
| 10분 | LED 명령 Subscribe 및 콜백 | Step 11-done |
| 10분 | MQTT led/set으로 Fade 제어 | Step 11-done |

## 「IoT기초 - IOT 빅데이터」 PDF 연계
- 데이터 수집·분류·전처리: 버튼 디바운싱·변화 이벤트 발행과 연결 (Step 05~10)
- MQTT 브로커와 Publish/Subscribe 및 QoS: MQTT 개념 실습과 연결 (Step 09~11)
- IoT 에지/포그와 빠른 피드백: 네트워크 없이 로컬 제어를 유지 (Step 04~13)
- 클라우드 및 보안: AWS IoT Core TLS 별도 확장 (Step 12)
- 반정형 데이터 개념: JSON 상태정보 확장 (Step 13)

## 강의노트의 범위 구분
PDF에 ESP32 PlatformIO 전체 C++ 코드나 `updateButton()`·`updateBrightness()`의 원본 함수 본문이 수록되어 있지는 않음. 따라서 기존 프로젝트에 있는 실제 C++ 본문을 *원문 그대로 복원했다*고 주장하지 않고, 확인된 함수 인터페이스·핀·토픽·수업 흐름을 기준으로 교육용 코드로 정리함.

## 확장 단계
- Step 01~07: 로컬 제어 교육
- Step 08: Wi-Fi / OTA
- Step 09~11: 첨부된 100분 MQTT 실습의 구현
- Step 12~13: 원본 100분 수업 뒤 AWS TLS 및 JSON 추가 심화
