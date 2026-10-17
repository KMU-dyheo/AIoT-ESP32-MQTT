# Step 08 — Wi-Fi·OTA와 로컬 앱 함수 분리 (수업 종료)

## 브랜치 및 누적 코드
- 시작: `step-08-wifi` (이전 단계 완료 코드 + 새 TODO)
- 완료: `step-08-wifi-done` (새 기능 추가)
- `git diff step-08-wifi..step-08-wifi-done -- src/main.cpp platformio.ini include/`

## 이 수업의 목표
- setupApplication()/loopApplication()에서 updateButton()/updateBrightness() 실행, Wi-Fi·OTA 별도
- GPIO25 LED PWM, GPIO23 INPUT_PULLUP 버튼 유지
- `updateButton()`과 `updateBrightness()`의 동작을 삭제하거나 이름을 바꾸지 않음
- Wi-Fi 설정은 include/wifi_config.example.h를 include/wifi_config.h로 복사한 후 실제 정보 입력
- MQTT 라이브러리는 아직 추가하지 않음. MQTT 연결은 Step 09부터 실습

## 검증
- `pio run -e esp32usb`로 빌드·업로드
- 네트워크가 끊어져도 버튼으로 Fade를 켜고 끌 수 있고 OTA 업로드 서비스는 연결 시 동작
- 실제 강의: [docs/step-08.md](docs/step-08.md)
- [강의노트 연계](docs/lecture-alignment.md)
