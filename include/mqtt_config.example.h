#pragma once
// mqtt_config.h로 복사 후 학생 PC의 실제 IP로 변경
#define MQTT_HOST "192.168.0.10"
#define MQTT_PORT 1883
#define MQTT_CLIENT_ID "class-device01"
#define MQTT_BUTTON_TOPIC "class/device01/button/event"
#define MQTT_LED_STATE_TOPIC "class/device01/led/state"
#define MQTT_LED_SET_TOPIC "class/device01/led/set"
