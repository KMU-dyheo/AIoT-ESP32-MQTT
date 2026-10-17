#pragma once
// mqtt_config.h로 복사하고 MQTT_HOST, 장치 ID, 토픽을 학생별로 변경
#define MQTT_HOST "192.168.0.10"
#define MQTT_PORT 1883
#define MQTT_CLIENT_ID "esp32-01"
#define MQTT_BUTTON_TOPIC "aiot/esp32-01/button/state"
#define MQTT_LED_STATE_TOPIC "aiot/esp32-01/led/state"
#define MQTT_LED_SET_TOPIC "aiot/esp32-01/led/set"
