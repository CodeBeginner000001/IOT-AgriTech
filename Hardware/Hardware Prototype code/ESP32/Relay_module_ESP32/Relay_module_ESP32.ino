/* Replay Module
Relay module will not switch off on 3.3v for 5v relay module (low level triggered)
as 3.3v and gnd is considered as low so to switch on and off a relay 
we need a level shifter which will shift the 3.3v to 5v so that relay can switch 
off and switch on when value is low.
*/
int relaypin=5;

void setup() 
{
  // put your setup code here, to run once:
pinMode(relaypin,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
digitalWrite(relaypin,HIGH);
delay(1000);
digitalWrite(relaypin,LOW);
delay(1000);
}
