# Step 08 — Wi-Fi 연결과 사용자 코드 분리

6주차 「아두이노 (4)」 9~21쪽을 따라 순서대로 수행합니다. **OTA는 Step 08에서 수행하지 않고 MQTT 실습 이후에 학습합니다.**

| 순서 | 실습 | 시작 브랜치 | 완료 브랜치 | 강의노트 |
|---|---|---|---|---|
| 08-01 | Wi-Fi 라이브러리 준비 | `step-08-01-wifi-library` | `step-08-01-wifi-library-done` | 12~15쪽 |
| 08-02 | 사용자 코드 분리 | `step-08-02-application-split` | `step-08-02-application-split-done` | 9~11쪽 |
| 08-03 | Wi-Fi 처리 구조 | `step-08-03-wifi-structure` | `step-08-03-wifi-structure-done` | 14~17쪽 |
| 08-04 | Wi-Fi 연결 및 재접속 | `step-08-04-wifi-connect` | `step-08-04-wifi-connect-done` | 17~21쪽 |

## 실습 원칙
- GPIO25 LED PWM 및 GPIO23 버튼 디바운싱·토글은 이전 코드 그대로 유지합니다.
- `setupApplication()`, `loopApplication()`은 Wi-Fi 연결 성공 여부와 무관하게 실행됩니다.
- `setup()`에서 `Serial.begin(115200)` 후 `setupApplication()`을 실행합니다.
- `loop()`에서 `loopApplication()`을 먼저 실행합니다. Wi-Fi 연결 대기용 무한 반복이나 `delay()`를 추가하지 않습니다.
- `wifi_config.example.h`를 복사하여 `include/wifi_config.h`에 개인 설정을 입력하고 해당 파일은 커밋하지 않습니다.
- Wi-Fi 연결 시 IP를 한 번 출력하고, 미연결 시 10초 간격으로 재접속합니다.

## 빌드 및 검증
```bash
pio run -e esp32usb
pio device monitor -b 115200
```

Wi-Fi 연결 성공 시 IP 주소를 확인하고, 연결을 차단했을 때에도 버튼과 Fade가 계속 작동하는지 확인합니다.

> 6주차 52~56쪽의 OTA 실습은 MQTT Publish/Subscribe 및 LED 제어 이후의 별도 단계로 이동합니다.
