// This is arduino project to create custom character in LiquidCrystal library.

#include<LiquidCrystal.h>       // including the lcd library.

LiquidCrystal sample_lcd(4,5,6,7,8,9);     // creating the lcd object and assigning the arduino for lcd pin RS,E,D04,DO5,DO6,DO7  

byte a[8] = {B00000,B01010,B01010,B00000,B00100,B10001,B01110,B00000};   // creating the custom simley.
void setup() {
  // put your setup code here, to run once:
sample_lcd.createChar(0,a);    
sample_lcd.begin(16,2);    // initializing the lcd as 16*2 lcd module.
//sample_lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
sample_lcd.write(byte(0));        // write the custom character 0 to the next cursor position.     
}
