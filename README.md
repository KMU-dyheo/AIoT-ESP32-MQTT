# Step 06 — millis 버튼 디바운싱

시작 코드

- 입력의 마지막 변화로부터 `DEBOUNCE_DELAY = 30` ms가 지나야 상태를 확정합니다.
- `buttonState`, `lastReading`, `lastDebounceTime` 사용
- GPIO23 버튼 외부 Pull-up 회로 유지, LED GPIO25 Fade 유지
- `pio run -e esp32usb` 빌드
