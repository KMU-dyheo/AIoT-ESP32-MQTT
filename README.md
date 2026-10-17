# Step 07-05 — updateButton() 분리

완성 코드

- 버튼 읽기·30ms 디바운싱·토글을 `updateButton()`으로 분리합니다.
- `loop()`는 PWM 시간 확인 후 `updateButton()`을 호출합니다.
- `updateBrightness()`는 기존대로 사용합니다.
- GPIO25 LED / GPIO23 내부 Pull-up 버튼
- `pio run -e esp32usb`
