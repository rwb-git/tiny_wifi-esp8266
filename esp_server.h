

#include <ESP8266WiFi.h>            // this includes wificlient, wifiserver, and several other header files

extern WiFiClient client; 

extern int wifistatus;

extern uint16_t app_msg;

extern WiFiServer server;

void server_loop();