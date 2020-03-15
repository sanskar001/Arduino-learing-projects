// This is arduino project to increament number on lcd screen module.

#include<LiquidCrystal.h>

LiquidCrystal sample_lcd(4,5,6,7,8,9);

int number=0;     // given number
void setup() {
  // put your setup code here, to run once:
sample_lcd.begin(16,2);
sample_lcd.clear();
Serial.begin(9600);      // initializing the serial commmunication with 9600 baud rate.
Serial.println("Number increamenting: ");
}

void loop() {
  // put your main code here, to run repeatedly:
for(number=0; number<100; number++){                // for creating the incremental iteration.
 Serial.print("number:");
Serial.println(number);                           // for showing the number on serial monitor.
sample_lcd.setCursor(0,0);
sample_lcd.print("Number:");                      // for showing the number on lcd screen module.
sample_lcd.setCursor(9,0);
sample_lcd.print(number);
delay(250);
sample_lcd.clear();                               // for clearing the previous data in lcd module.
}
sample_lcd.print("Finish :)");
delay(3000);
}
