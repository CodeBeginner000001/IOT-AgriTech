#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
int count=0;
void setup() {
  // put your setup code here, to run once:
  lcd.init();
lcd.begin(16,2);
lcd.print("Hello");
lcd.setCursor(0,1);
lcd.print("Counting begin");
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.clear();
lcd.print("Hello World");
lcd.setCursor(0,1);
lcd.print("Counting:");
lcd.setCursor(11,1);
lcd.print(count);
count++;
delay(200);
}
