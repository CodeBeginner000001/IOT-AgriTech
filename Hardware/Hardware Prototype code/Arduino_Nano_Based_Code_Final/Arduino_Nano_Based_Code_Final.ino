#include <SPI.h>
#include <Wire.h>
#include <BH1750.h>   // light intensity Sensor header file
BH1750 lightMeter;

#include <dht.h>        // Include library
int outPin=3;        // Defines pin number to which the sensor is connected
dht DHT;               // Creates a DHT object

#define sensorPin A0  // for capacitive soil moisture sensor

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int t1=3000;
int t2=3000;
int t3=3000;

const int dry=560; // value for dry sensor
const int wet=239; // value for wet sensor

int waterIn_relay=10;
int waterOut_relay=9;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
    display.clearDisplay();
    pinMode(waterIn_relay,OUTPUT);
    pinMode(waterOut_relay,OUTPUT);
    digitalWrite(waterIn_relay,HIGH);
    digitalWrite(waterOut_relay,HIGH);
}

void loop()
{
  lux();
  delay(t1);
  temp();
  delay(t2);
  soil_mositure();
  delay(t3);

  
  int a=soil_mositure()-10;
  int b=temp();
  if(a<=50)
  {
    waterIn_relay_On();
    delay(10000);
    waterIn_relay_off();
    delay(1);
  }

  if(a<=50 && b>=30)
  {
    waterIn_relay_On();
    delay(10000);
    waterIn_relay_off();
    delay(1);
  }

  if(a>100)
  {
    delay(10000);
    waterOut_relay_On();
    delay(5000);
    waterOut_relay_off();
    delay(1);
  }
  delay(1000);
}

void lux()
{
   float lux = lightMeter.readLightLevel();
   display.setTextSize(0.2);
   display.setTextColor(WHITE);
   display.setCursor(0,0);
   display.print("BH1750 Test Begin =  ");
   display.setCursor(0,12);
   display.print(lux);
   delay(10);
   display.display();
   display.clearDisplay();
}

int temp()
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
   return t;
}

int soil_mositure()
{
  int value = analogRead(sensorPin);
  Serial.print(value);
  int per=map(value,wet,dry, 100, 0);
   display.setTextSize(0.2);
   display.setTextColor(WHITE);
   display.setCursor(0,0);
   display.print("Soil Mositure = ");
   display.print(per);
   display.print(" %");
   delay(10);
   display.display();
   display.clearDisplay();
   return per;
}

void waterIn_relay_On()
{
  digitalWrite(waterIn_relay,LOW);
}

void waterIn_relay_off()
{
  digitalWrite(waterIn_relay,HIGH);
}

void waterOut_relay_On()
{
  digitalWrite(waterOut_relay,LOW);
}

void waterOut_relay_off()
{
  digitalWrite(waterOut_relay,HIGH);
}
