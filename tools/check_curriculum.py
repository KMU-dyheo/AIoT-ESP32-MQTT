#!/usr/bin/env python3
"""Validate progression of each student starter and instructor done branch."""
from pathlib import Path
import argparse
import re
import sys

parser = argparse.ArgumentParser()
parser.add_argument("--branch", required=True)
parser.add_argument("--root", default=".")
args = parser.parse_args()
root = Path(args.root)
src = (root / "src/main.cpp").read_text(encoding="utf-8")
ini = (root / "platformio.ini").read_text(encoding="utf-8")
branch = args.branch
match = re.match(r"^step-(\d\d)(?:-(\d\d))?-[a-z0-9-]+(?:-done)?$", branch)
if not match:
    sys.exit("Invalid classroom branch: " + branch)
num = int(match.group(1))
sub = match.group(2)
done = branch.endswith("-done")
errors = []

def want(ok, reason):
    if not ok:
        errors.append(reason)

want(bool(re.search(r"board\s*=\s*esp32doit-devkit-v1", ini)), "DOIT board not set")
want("board_build.f_cpu = 240000000L" in ini, "CPU frequency not set")
want("[env]" in ini and "[env:esp32usb]" in ini and "[env:esp32ota]" in ini, "USB/OTA env missing")
want((root/"README.md").exists(), "README missing")
for n in range(1, 14):
    want((root/f"docs/step-{n:02d}.md").exists(), f"guide for step {n} missing")
for path in ("docs/step-10-01.md", "docs/step-10-02.md", "docs/lecture-alignment.md"):
    want((root/path).exists(), f"{path} missing")
want("TODO" in src if not done else "TODO" not in src, "starter/done TODO state incorrect")
want("#define LED_PIN 2" in src if num == 1 or (num == 2 and not done) else "#define LED_PIN 25" in src, "LED pin progression wrong")

has_button = num >= 6 or (num == 5 and done)
want(("#define BUTTON_PIN 23" in src) == has_button, "button GPIO23 introduced at wrong step")
has_helpers = has_button
want(("void updateButton()" in src and "void updateBrightness()" in src) == has_helpers, "application helper functions not progressive")

has_wifi = num >= 9 or (num == 8 and done)
want(("#include <WiFi.h>" in src) == has_wifi, "Wi-Fi introduced at wrong step")
has_mqtt = num >= 10 or (num == 9 and done)
want(("#include <ESP32MQTTClient.h>" in src) == has_mqtt, "MQTT library introduced at wrong step")
want(("cyijun/ESP32MQTTClient" in ini) == has_mqtt, "MQTT platformio dependency introduced at wrong step")
want(("mqttClient.setURL(" in src) == has_mqtt, "MQTT connection introduced at wrong step")

has_button_publish = (num > 10) or (num == 10 and (done or sub == "02"))
has_led_publish = (num > 10) or (num == 10 and done and (sub is None or sub == "02"))
want(('mqttClient.publish(MQTT_BUTTON_TOPIC' in src) == has_button_publish, "button publish not progressive")
want(('mqttClient.publish(MQTT_LED_STATE_TOPIC' in src) == has_led_publish, "LED publish not progressive")

has_subscribe = num > 11 or (num == 11 and done)
want(("mqttClient.subscribe(MQTT_LED_SET_TOPIC" in src) == has_subscribe, "LED subscribe not progressive")

has_aws = num > 12 or (num == 12 and done)
want(('#include "aws_certificates.h"' in src) == has_aws, "AWS cert introduced at wrong step")
want(('mqttClient.setCaCert(' in src) == has_aws, "AWS TLS introduced at wrong step")

has_json = num == 13 and done
want(("#include <ArduinoJson.h>" in src) == has_json, "JSON code introduced at wrong step")
want(("serializeJson(" in src) == has_json, "JSON state not progressive")

if has_mqtt:
    conf = root / "include/mqtt_config.example.h"
    want(conf.exists(), "MQTT config example missing")
    if conf.exists():
        s = conf.read_text(encoding="utf-8")
        for topic in ("aiot/esp32-01/button/state", "aiot/esp32-01/led/state", "aiot/esp32-01/led/set"):
            want(topic in s, f"original classroom MQTT topic missing: {topic}")

if errors:
    for e in errors:
        print("FAIL:", e)
    sys.exit(1)
print(f"PASS: {branch}: progressive features, GPIO23/25, MQTT topics and docs")
