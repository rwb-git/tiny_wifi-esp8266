#include "esp_server.h"


WiFiClient client; 

int wifistatus;

uint16_t app_msg;

WiFiServer server(80);

void server_loop(){
  
  client = server.available();

  if (client) {

    while (client.connected()){
      
      if (client.available()){
        
        String line = client.readStringUntil('\r');
      
        app_msg = 0;

        char * paych = strdup(&line[0]); // strdup copies line, and needs to be freed when done
         
        char * save_paych = paych; // save so i can free, which requires original pointer value, and strsep alters paych
      
        char * token;
      
        if (strlen(paych) > 0){
      
          token = strsep(&paych," ");
      
          if (strlen(token) > 0){
         
            app_msg = atoi(token); 
          }      
        }
      
        free(save_paych);
            
        char buf[300];
    
        app_msg ++;
        
        sprintf(buf,"%d \r\n",app_msg);        // needs final " " or app says not an integer (if final entity is a number)
    
        client.print(buf);

        break;

      } // if client.available
    }

    client.stop();
  }
}
