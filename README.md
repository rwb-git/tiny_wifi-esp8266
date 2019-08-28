this sketch works with android app tiny_wifi-android

These files work in platformio, and also work as-is in the Arduino IDE as follows:

Make a directory with a name like tiny_wifi or whatever you like, and copy all the cpp and h files (skip platformio.ini) files into that directory, and change the name of main.cpp to tiny_wifi.ino or the name you chose. All the other cpp and header files compile as-is.

This code works with my Android app "tiny_wifi-android". You will need the IP that your router assigns to your esp device and hard-code it into that app before you install it (this is pretty crude; look at my simple_wifi projects for a slightly more sophisticated approach where the app scans for the ESP device).

Also, you might need to go into your router configuration and allow the esp8266.

