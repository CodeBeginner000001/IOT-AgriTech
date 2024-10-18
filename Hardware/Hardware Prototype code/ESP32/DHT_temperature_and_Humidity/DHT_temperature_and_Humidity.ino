#include <DHT.h>

DHT dht(15,DHT22);
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Temp: ");
Serial.println((dht.readTemperature()));
Serial.print("Humidity: ");
Serial.println((dht.readHumidity()));
delay(2000);

}
