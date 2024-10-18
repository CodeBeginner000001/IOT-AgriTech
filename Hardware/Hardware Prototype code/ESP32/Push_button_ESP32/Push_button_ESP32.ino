int push_button=15;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(push_button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if((digitalRead(push_button))==0)
{
  Serial.print("Not pressed");
}
else
{
  Serial.print("Pressed");
}
}
