/*Using Adruino IDE and Google Firebase
To connect your custom website to IOT the only it can be achieved 
is through sending your IOT data to an API Database and then connect 
to a MongoDB and then to website.

IOT----->API---->MongoDB---->Website
*/
#include<WiFi.h>
#include<Firebase_ESP_Client.h>
#include "addons/TokenHelper.h" // Used for token generation
#include "addons/RTDBHelper.h" // Used for Realtime Database exchange

#include<BH1750.h>

#define WIFI_SSID "EXCITEL_2.4G"  // Enter wifi name
#define WIFI_Password "AA0327927" //Enter wifi password
#define API_Key "AIzaSyCUtd2umTirdedyHwtJsiYtHe3QEtsx8-Q"  //Add your Project API key 
#define Database_URL "https://iot-agritech-default-rtdb.asia-southeast1.firebasedatabase.app/" //Add your created Database project URL

BH1750 lightMeter;

// Three Firebase Objects
FirebaseData fbdo;  // when there is a specific data exchange on a specific database node path
FirebaseAuth auth; // need for authentication
FirebaseConfig config; //need for configuration

unsigned long sendDataPrevMillis = 0;
bool signupOK = false;
float lux=0;

void setup() 
{
 Wire.begin();
 lightMeter.begin();
 Serial.begin(115200);
 WiFi.begin(WIFI_SSID, WIFI_Password);   // start wifi connection
 Serial.print("Connecting to Wi-Fi ......");
 while(WiFi.status() != WL_CONNECTED)   // check if wifi is connected or not
 {
  Serial.print(".");delay(200);
 }
 Serial.println();
 Serial.print("Connected with IP: ");
 Serial.println(WiFi.localIP());      // used to print IP Address of the Wifi
 Serial.println();

 config.api_key = API_Key;
 config.database_url = Database_URL;
 if(Firebase.signUp(&config, &auth, "", "")) //denote anom user
 {
  Serial.println("SignUp OK");
  signupOK = true;
 }else{
  Serial.printf("%s\n", config.signer.signupError.message.c_str()); //error message
 }

 config.token_status_callback = tokenStatusCallback;
 Firebase.begin(&config, &auth);
 Firebase.reconnectWiFi(true);
}

void loop() {
  if(Firebase.ready() && signupOK && (millis()-sendDataPrevMillis>2000 || sendDataPrevMillis == 0))
  {
    sendDataPrevMillis = millis();
    // ------------------------------ Store sensor data to a RTDB
    lux=lightMeter.readLightLevel();
    /*Following functions are used to store data in the specific node in the the realtime database
    ---> set
    ---> setInt
    ---> setFloat
    ---> setDouble
    ---> setString
    ---> setJSON
    ---> setArray
    ---> setBlob
    ---> setFile
    These function return boolean value if everything go well that is
    Return true if
    The server returns
    HTTP status code 200

    The data types matched between request and response
    */

    // ---------- to send data to firebase by creating a node path if it exists it will update in that path
    // below is for getting light intensity 
    if(Firebase.RTDB.setFloat(&fbdo, "Sensor/Light Intensity", lux))
    {
      Serial.println();
      Serial.print(lux);
      Serial.print(" -successfully saved to: " + fbdo.dataPath());  // get to know in which node path
      Serial.println(" (" +fbdo.dataType() + ")");  //and which datatype it is
    }else{
      Serial.println("FAILED: " + fbdo.errorReason());
    }

  
  }
}
