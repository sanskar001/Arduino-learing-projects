// This is arduino projects to show auto vertical scrolling on lcd screen module.

#include<LiquidCrystal.h>    // firstly including the library of  LCD.

LiquidCrystal lcd(4,5,6,7,8,9);   // assinging the arduino pin for LCD out pin RS,E,DO4,DO5,DO6,DO7.
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);      // initializing the type of lcd module as 16 by 2 lcd.
  lcd.clear();          // clearing the lcd previous input data.
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);      // setting the cursor on lcd screen.
lcd.print("> 1. First task");      // priting the string on lcd screen.
lcd.setCursor(0,1);
lcd.print("  2. Second task");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("> 2. Second task");
lcd.setCursor(0,1);
lcd.print("  3. Third task");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("> 3. Third task");
lcd.setCursor(0,1);
lcd.print("  4. Fourth task");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("> 4. Fourth task");
lcd.setCursor(0,1);
lcd.print("  1. First task");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("> 1. First task");
lcd.setCursor(0,1);
lcd.print("  2. Second task");
delay(2000);
lcd.clear();
}
