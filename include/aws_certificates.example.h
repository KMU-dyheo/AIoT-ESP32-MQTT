#pragma once
#define AWS_IOT_ENDPOINT "YOUR_ENDPOINT-ats.iot.ap-northeast-2.amazonaws.com"
const char AWS_ROOT_CA[] = R"EOF(-----BEGIN CERTIFICATE-----
PASTE_ROOT_CA
-----END CERTIFICATE-----)EOF";
const char AWS_DEVICE_CERT[] = R"EOF(-----BEGIN CERTIFICATE-----
PASTE_DEVICE_CERT
-----END CERTIFICATE-----)EOF";
const char AWS_PRIVATE_KEY[] = R"EOF(-----BEGIN PRIVATE KEY-----
PASTE_PRIVATE_KEY
-----END PRIVATE KEY-----)EOF";
