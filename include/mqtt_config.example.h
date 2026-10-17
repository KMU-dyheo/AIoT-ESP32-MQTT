#pragma once
// 6주차 34쪽: mqtt_config.h로 복사하여 개인 설정 입력
// 각 학생은 고유한 Client ID와 장치별 Topic을 사용합니다.
#define MQTT_HOST "192.168.0.10"
#define MQTT_PORT 1883
#define MQTT_CLIENT_ID "esp32-01"
#define MQTT_BUTTON_TOPIC "aiot/esp32-01/button/state"
#define MQTT_LED_STATE_TOPIC "aiot/esp32-01/led/state"
#define MQTT_LED_SET_TOPIC "aiot/esp32-01/led/set"
