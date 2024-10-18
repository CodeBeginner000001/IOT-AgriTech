int ldr=34;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(ldr,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(ldr));
delay(1000);
}
