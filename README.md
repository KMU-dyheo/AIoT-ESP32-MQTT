# Step 08-02 — setup / loop 애플리케이션 분리

완성 코드

- 기존 `setup()`의 코드를 전부 `setupApplication()`으로 옮깁니다.
- 기존 `loop()`의 코드를 전부 `loopApplication()`으로 옮깁니다.
- `setup()`과 `loop()`는 앱 함수를 호출합니다.
- 이 단계에서는 Wi-Fi 연결 동작을 추가하지 않습니다.
- `pio run -e esp32usb`
