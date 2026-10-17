#pragma once
// 장치별 MQTT Client ID 및 장치 토픽은 중복되지 않게 변경
#define MQTT_HOST "192.168.0.10"
#define MQTT_PORT 1883
#define MQTT_CLIENT_ID "esp32-01"
#define MQTT_BUTTON_TOPIC "aiot/esp32-01/button/state"
#define MQTT_LED_STATE_TOPIC "aiot/esp32-01/led/state"
#define MQTT_LED_SET_TOPIC "aiot/esp32-01/led/set"
