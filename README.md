# Step 13 — AWS IoT 원격 LED 제어 (수업 시작)

## 시작 코드
- Step 12의 AWS IoT Core TLS 연결 코드
- Step 12까지 완성한 AWS TLS 연결 및 일반 문자열 `ON`/`OFF` 원격 제어가 이미 포함됨
- 이번 단계에서는 JSON 명령과 구조화된 상태정보를 추가

## 학생 과제
- [ ] 기존 일반 문자열 명령 `ON`/`OFF`는 계속 지원
- [ ] `ArduinoJson`으로 `{"state":"ON"}` / `{"state":"OFF"}` 명령 해석
- [ ] LED 상태를 `{"device":"...","led":"ON","brightness":120,"uptime_ms":12345}` 형태의 JSON으로 발행
- [ ] AWS IoT MQTT 테스트 클라이언트에서 일반 문자열·JSON 명령과 JSON 상태 응답 검증
- [ ] 네트워크 실패 시 로컬 LED/버튼 동작 유지

## 실행
- `pio run -e esp32usb`
- 실제 계정 및 인증서는 `include/aws_certificates.h`에만 입력하고 Git에 올리지 않음
- [Step 13 완성 코드](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-13-aws-iot-control-done)와 비교
- `docs/step-13.md` 참고

## PlatformIO
- `[env]`에 보드(`esp32doit-devkit-v1`), 240MHz CPU, MQTT·JSON 라이브러리 관리
- USB/OTA 프로필은 각각 업로드 방법만 달리함

## 강의 진행 브랜치
- **수업 시작**: [`step-13-aws-iot-control`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-13-aws-iot-control)
- **수업 완료**: [`step-13-aws-iot-control-done`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-13-aws-iot-control-done)
- 현재 브랜치: **수업 시작 코드**
- 현재 실습 문서: `docs/step-13.md`; 강의노트와의 연결은 `docs/lecture-alignment.md` 참고

## 강의노트 연계
- 11쪽 정형·반정형·비정형 데이터 개념 중 **반정형 JSON**에 대응하는 확장 실습
- 45~46쪽 MQTT Publish/Subscribe를 유지하면서 데이터의 표현 형태를 개선
