// This is arduino projects to understand working the push button with lcd module.

#include<LiquidCrystal.h>    // firstly including the library of  LCD.

LiquidCrystal sample_lcd(4,5,6,7,8,9);   // assinging the arduino pin for LCD out pin RS,E,DO4,DO5,DO6,DO7.

#define push_button 2
int number = 0;
int input;
void setup() {
  // put your setup code here, to run once:
  pinMode(push_button,INPUT_PULLUP);
  sample_lcd.begin(16,2);      // initializing the type of lcd module as 16 by 2 lcd.
  sample_lcd.clear();          // clearing the lcd previous input data.
  Serial.begin(9600);
  Serial.println("Number increament: ");
  sample_lcd.print("Number:");
  Serial.println("Number:");
}

void loop() {
  // put your main code here, to run repeatedly:
input = digitalRead(push_button);
if(input == LOW)   {           // when switch is on.
Serial.print("Number: ");
Serial.println(number);
sample_lcd.setCursor(0,0);
sample_lcd.print("Number:");
sample_lcd.setCursor(9,0);
sample_lcd.print(number);
number++;
if (number>9){
  number = 0;
}
}
delay(160);             // giving the delay of 160 ms for neglecting the push_button bouncing.
}
