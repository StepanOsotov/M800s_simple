#ifndef _MY_ESP32_SERVER_H_
#define _MY_ESP32_SERVER_H_

#include <ArduinoJson.h>
#include <WiFi.h>
#include <WebServer.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <iostream>
#include <ESPmDNS.h>
#include <stdint-gcc.h>

#include "webpage.h"

#define GPIO_DEBUGGING  23
//#define SEND_SIMPLE_RANDOM
#define SEND_SITE_ON_BUTTON

extern WebServer server;

void initMyServerESP32(void);
void handleNotFound(void);
void handlerButtonRecipe(void);
void handlerButtonFastRun(void);
void handlerButtonProgs(void);
JsonObject receiveMessageFromClient(void);
void generateJsonBufAntTX(String jsonKey, int jsonVal);

#endif  //_MY_ESP32_SERVER_H_