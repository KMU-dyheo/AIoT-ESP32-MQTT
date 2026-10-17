# Step 08 — Wi-Fi 코드 구조 준비 완료

완성 코드

## 실행 구조
- `setupApplication()` / `loopApplication()`: 기존 버튼 및 LED 코드
- `setupWiFi()` / `handleWiFi()`: Wi-Fi 처리를 추가할 위치
- 이 단계는 Wi-Fi 호출 위치 준비까지만 실습하며 실제 접속은 구현하지 않습니다.
- `setup()`과 `loop()`는 기존 앱 코드를 계속 실행해야 합니다.

## 빌드
`pio run -e esp32usb`
