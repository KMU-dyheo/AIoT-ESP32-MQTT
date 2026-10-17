# Step 05-01 — 외부 Pull-up 버튼 입력

완성 코드

## 회로
- GPIO25 LED 회로 유지
- GPIO23 버튼: 외부 10kΩ Pull-up 저항, 버튼 반대쪽은 GND

## 실습
- `pinMode(PIN_BUTTON, INPUT)`과 `digitalRead(PIN_BUTTON)`
- LED 비차단 처리 코드를 함께 유지
- `pio run -e esp32usb` 빌드 및 시리얼 모니터(115200) 확인
