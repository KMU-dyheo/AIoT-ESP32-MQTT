# Step 07-01 — 버튼으로 Fade 토글

완성 코드

- 디바운싱된 버튼 눌림 이벤트로 `fadeEnabled`를 변경합니다.
- PWM 출력 중지 시 `analogWrite(PIN_LED, 0)`을 실행합니다.
- GPIO25 LED, GPIO23 외부 Pull-up 버튼
- `pio run -e esp32usb`
