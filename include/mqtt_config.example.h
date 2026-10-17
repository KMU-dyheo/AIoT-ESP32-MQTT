#pragma once
// 학생마다 고유한 Client ID와 Topic 접두어를 사용하세요.
// 이 예제를 mqtt_config.h로 복사하고 MQTT_HOST를 PC의 실제 IP로 변경하세요.
#define MQTT_HOST "192.168.0.10"
#define MQTT_PORT 1883
#define MQTT_CLIENT_ID "esp32-01"
#define MQTT_BUTTON_TOPIC "aiot/esp32-01/button/state"
#define MQTT_LED_STATE_TOPIC "aiot/esp32-01/led/state"
#define MQTT_LED_SET_TOPIC "aiot/esp32-01/led/set"
