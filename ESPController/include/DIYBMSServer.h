#ifndef DIYBMSServer_H_
#define DIYBMSServer_H_

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include <EEPROM.h>

#include "ArduinoJson.h"

class DIYBMSServer {
   public:
      static void StartServer(AsyncWebServer  *webserver);

  private:
      static AsyncWebServer * _myserver;

      static void handleRedirect();
      static void handleNotFound(AsyncWebServerRequest *request);
      static void monitor(AsyncWebServerRequest *request);
      static void sendHeaders();
      static void settings(AsyncWebServerRequest *request);
      static void identifyModule(AsyncWebServerRequest *request);
};


extern bool waitingForReply;
extern uint8_t missedPacketCount;
extern uint16_t totalMissedPacketCount;
extern uint16_t totalCRCErrors;
extern uint16_t totalNotProcessedErrors;
extern bool requestPending;

#endif
