#include <ESP32Servo.h>
Servo myservo;
int servopin=18;
void setup() {
  // put your setup code here, to run once:
myservo.attach(servopin);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  int angle=Serial.parseInt();
  myservo.write(angle);
  
}
delay(20);
}
