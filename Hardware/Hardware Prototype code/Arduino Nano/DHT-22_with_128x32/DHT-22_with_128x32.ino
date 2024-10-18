#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#include <dht.h>        // Include library
int outPin=9;        // Defines pin number to which the sensor is connected
dht DHT;               // Creates a DHT object

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
    display.clearDisplay();
}
void loop()
{

 temp();

}
void temp()
{
  int readData = DHT.read22(outPin);
  float t = DHT.temperature;        // Read temperature
  float h = DHT.humidity;           // Read humidity
   display.setTextSize(0.2);
   display.setTextColor(WHITE);
   display.setCursor(0,0);
   display.print("Temperature = ");
   display.print(t);
   display.print(" C");
   display.setCursor(0,12);
   display.print("Humidity =  ");
   display.print(h);
   display.print(" %");
   delay(10);
   display.display();
   display.clearDisplay();
}
