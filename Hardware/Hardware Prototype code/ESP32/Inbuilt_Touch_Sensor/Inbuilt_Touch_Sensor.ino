/* 
 ESP32 Inbuilt touch sensor
 
 -> GPIO32 - Touch 9
 -> GPIO33 - Touch 8
 -> GPIO27 - Touch 7
 -> GPIO14 - Touch 6
 -> GPIO12 - Touch 5
 -> GPIO13 - Touch 4
 -> GPIO15 - Touch 3
 -> GPIO2  - Touch 2
 -> GPIO4  - Touch 0
 -> GPIO1  - Touch 1
 
*/
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(touchRead(T9));
delay(1000);
}
