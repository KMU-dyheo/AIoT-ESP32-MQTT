# Step 08 — Wi-Fi 및 OTA, 앱 루프 독립

## 학습 목표
로컬 updateButton()/updateBrightness()를 보존하며 setupApplication()/loopApplication(), Wi-Fi, OTA 도입

## 시작 코드와 완성 코드
- **시작**: `git switch step-08-wifi` — Step 07 완료 코드와 이 단계 TODO
- **완료**: `git switch step-08-wifi-done` — 이 단계 기능까지 구현
- 비교: `git diff step-08-wifi..step-08-wifi-done -- src/main.cpp platformio.ini include/`

## 연결 및 준비
- 회로: GPIO23 버튼, GPIO25 LED, Wi-Fi AP
- Arduino/PlatformIO의 실제 보드 설정과 USB 포트를 확인
- 개인 Wi-Fi 또는 WPA2-Enterprise 연결정보는 `include/wifi_config.example.h`를 복사한 비공개 `wifi_config.h`에 입력

## 구현 내용
- 핵심 구현: `connectWifi(), ArduinoOTA.handle(), setupApplication(), loopApplication()`
- 개념: 로컬 동작과 네트워크 서비스 분리

## 실습 순서
1. 수업 시작 브랜치로 이동하고 `src/main.cpp`의 TODO 읽기
2. 새로 필요한 회로·설정·라이브러리만 추가
3. 핵심 로직 구현 후 `pio run -e esp32usb`로 빌드
4. ESP32를 USB로 업로드하고 시리얼 모니터(`115200`) 확인
5. Wi-Fi 끊김 및 재연결 중에도 버튼과 LED Fade가 작동
6. 완료 브랜치와 `git diff`로 구현 차이를 비교

## 검증 기준
- **필수 동작**: Wi-Fi 끊김 및 재연결 중에도 버튼과 LED Fade가 작동
- Step 04 이후: 루프에서 불필요한 `delay()` 없이 PWM 동작 유지
- Step 08 이후: 네트워크가 끊겨도 `updateButton()`·`updateBrightness()` 동작 유지
- MQTT 이전 단계는 MQTT 헤더·접속 코드·라이브러리를 추가하지 않음

## 문제 해결
- LED가 동작하지 않으면 GPIO25, GND 공통 접지, 저항, LED 극성을 확인
- 버튼 값이 반대로 보이면 `INPUT_PULLUP`에서 LOW=눌림인지 확인

## 개발 환경
- 실제 사용 보드: `esp32doit-devkit-v1`, ESP32 240MHz, Arduino Framework, Serial 115200

- LED: GPIO25, 220~330Ω 직렬저항
- 버튼: GPIO23 ↔ GND, `INPUT_PULLUP` (눌림 LOW, 해제 HIGH)
- 빌드: `pio run -e esp32usb`
