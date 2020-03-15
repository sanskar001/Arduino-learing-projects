// This is arduino project to understand all function and tools of LiquidCrystal library.

#include<LiquidCrystal.h>  // including the LCD library.

LiquidCrystal sample_lcd(4,5,6,7,8,9);   // creating the lcd object as "sample_lcd".

void setup() {
  // put your setup code here, to run once:
sample_lcd.begin(16,2);    // initializing the lcd object as 16 by 2 lcd module.
sample_lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
sample_lcd.setCursor(0,0);
// printing the string type data into lcd screen.
//String string = "Hi Arduino";
//sample_lcd.print(string);

// printing the integer data.
//int number = 1045;
//sample_lcd.print("Number: ");
//sample_lcd.setCursor(8,0);
//sample_lcd.print(number);

// printing the floating number on screen.
//float f_number = 16.4556456;
//sample_lcd.print("Fnumber: ");
//sample_lcd.setCursor(8,0);
//sample_lcd.print(f_number,4);    // printing the floating number with 4 digits precision.
//sample_lcd.cursor();           // for showing the cursor on screen.

// printing the number with base BIN,DEC,OCT,HEX.
int number = 10;
sample_lcd.print("Number:");
sample_lcd.setCursor(8,0);
sample_lcd.print(number);
delay(1000);
sample_lcd.noDisplay();   // off showing display.
delay(1000);
sample_lcd.display();     // on showing display.
sample_lcd.setCursor(8,0);
sample_lcd.print(number,BIN);
delay(1000);
sample_lcd.blink();        // on blinking cursor for 2 second delay.
delay(2000);
sample_lcd.noBlink();     // off blinking cursor.
sample_lcd.clear();       // for clearing the data in lcd.
}
