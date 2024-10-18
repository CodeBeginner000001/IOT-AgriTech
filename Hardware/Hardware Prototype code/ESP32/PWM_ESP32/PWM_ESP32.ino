// setting PWM properties
const int freq = 10000;
const int ledchannel =0;
const int resolution = 8;

void setup() {
// configure LED PWM functionalities
ledcSetup(ledchannel,freq,resolution);

// attach the channel to the GPIO to be controlled
ledcAttachPin(LED_BUILTIN, ledchannel);
}

void loop() {
  // increase the LED Brightness
for(int dutycycle =0 ; dutycycle <=255; dutycycle++)
{
  ledcWrite(ledchannel, dutycycle);
  delay(5);
}

  // decrease the LED Brightness
for(int dutycycle=255;dutycycle>=0;dutycycle--)
{
  ledcWrite(ledchannel,dutycycle);
  delay(5);
}
}
