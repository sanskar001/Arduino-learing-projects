// This is arduino projects to print "Hello world" on 16*2 lcd module.

#include<LiquidCrystal.h>    // firstly including the library of  LCD.

LiquidCrystal lcd(4,5,6,7,8,9);   // assinging the arduino pin for LCD out pin RS,E,DO4,DO5,DO6,DO7.
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);      // initializing the type of lcd module as 16 by 2 lcd.
  lcd.clear();          // clearing the lcd previous input data.
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(2,0);      // setting the cursor on lcd screen.
lcd.print("Hello");      // priting the string on lcd screen.
lcd.setCursor(8,0);
lcd.print("World");
}
