#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#define USE_SERIAL Serial

WiFiMulti wifiMulti;  //delcaring wifiMulti instance in WiFiMulti class

void setup() {

    USE_SERIAL.begin(115200);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();  // flush is used to clear the stack
        delay(1000);
    }

    //using wifiMulti, we can add multiple wifi credentials
    wifiMulti.addAP("Agrawals", "Vivaan123");
    wifiMulti.addAP("Iphone","123456789");

}

void loop() {
    // wait for WiFi connection
    if((wifiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        USE_SERIAL.print("[HTTP] begin...\n");
        // configure traged server and url
        
        //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
        http.begin("http://example.com/index.html"); //HTTP

        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) 
            {
                String payload = http.getString();
                USE_SERIAL.println(payload);
            }
        } else 
        {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

    delay(5000);
}
