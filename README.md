# Step 08 — Wi-Fi 및 OTA (수업 시작)

## 제공되는 코드
- 이전 Step에서 완성한 LED/버튼 기능 제공
- 현재 코드는 setup()/loop() 구조이며 이번 단계에서 애플리케이션 함수 분리

## 학생 수행 과제
- [ ] setupApplication() / loopApplication()으로 LED/버튼 분리
- [ ] 개인용·기업용 Wi-Fi 연결, 재연결 및 ArduinoOTA 처리
- [ ] `include/wifi_config.example.h`는 완성 브랜치에서 추가되는 예시 파일이므로, Wi-Fi 설정과 보안 파일 생성 절차를 직접 학습

## 실행과 비교
- `pio run -e esp32usb` 실행
- 과제 코드 구현 후 [완성 브랜치](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-08-wifi-done)와 비교
- 실습 자료: `docs/step-08.md`

## PlatformIO
- 공통 `[env]` 설정: DOIT ESP32 DevKit V1 / 240MHz / Arduino
- `esp32usb` 기본 사용, Step 08에서 OTA 업로드 도입

## 강의 진행 브랜치
- **수업 시작**: [`step-08-wifi`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-08-wifi)
- **수업 완료**: [`step-08-wifi-done`](https://github.com/KMU-dyheo/AIoT-ESP32-MQTT/tree/step-08-wifi-done)
- 현재 브랜치: **수업 시작 코드**
- 현재 실습 문서: `docs/step-08.md`; 강의노트와의 연결은 `docs/lecture-alignment.md` 참고
