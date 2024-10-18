/*
Poteniopot - 1 (First potentiometer from black capacitor side)

Clockwise or Right
increase Delay. Fully right and the delay will be 
approximately 5 minutes.

Counter-Clockwise or Left
Decrease Delay. Fully left and the delay will be 
approximately 3 seconds.



Poteniopot - 2 (First potentiometer from Yellow capacitor side)

Clockwise or Right
Decrease Sensitivity. Fully right and the range wiil be 
approximately 3 meters.

Counter-Clockwiser or Left
Increase Sensitivity. Fully left and the range will be 
approximately 7 meters.

*/
int pir=4;

void setup() 
{  
  Serial.begin(115200);
  pinMode(pir,INPUT);
}

void loop() 
{
  int a=digitalRead(pir);
  Serial.println(a);
  if(a==HIGH)
  {
    Serial.print("Motion Detected");
  }
  else
  {
    Serial.print("Motion Not Detected");
  }
  delay(200);
}
