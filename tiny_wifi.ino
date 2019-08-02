
// enter your router SSID and password
const char * ssid = "NETGEAR84";
const char * password = "rb76543aaa789&*()cvbn";

#include <ESP8266WiFi.h>

int wifistatus;

uint16_t app_msg;

WiFiServer server(80);


void setup() {

  ESP.wdtEnable(2000); // soft wdt works without this

  
  WiFi.persistent(false); // according to readthedocs, the flash can wear out if I call WiFi.begin(ssid,pwd) too many times. setting persistent = false is supposed to make it use whatever is already there and not re-write it. so, I think
                          // that I can leave this alone in every sketch as long as I'm using the same router ssid and pwd. 

  WiFi.mode(WIFI_STA);

  WiFi.begin(); // this will use whatever is in flash

  //WiFi.begin(ssid, password);  // i need to enable this for any new devices that don't have my router ssid/pwd in flash
  
  while (WiFi.status() != WL_CONNECTED){
    
    delay(100);
  }

  server.begin();
}



void loop() {

  server_loop();

  yield();
}
