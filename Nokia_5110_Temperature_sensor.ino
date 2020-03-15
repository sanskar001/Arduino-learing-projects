// This is arduino project work with Temperature sensor LM35 and Nokia 5110 LCD module by making menu screeen.

#include<LCD5110_Graph.h>   // including the library for LCD 5110.

// Creatinig the instance of Nokia 5110 lcd .
LCD5110 sample_glcd(8,9,10,11,12);

extern unsigned char SmallFont[];

void setup() {
  // put your setup code here, to run once:
sample_glcd.InitLCD(60);
sample_glcd.setFont(SmallFont);

sample_glcd.drawRect(0,0,83,47);
sample_glcd.print("Temperature",CENTER,8);
sample_glcd.print("Sensor",CENTER,18);
sample_glcd.print("LM35",CENTER,30);
sample_glcd.update();
delay(2000);
sample_glcd.clrScr();
}

void loop() {
  // put your main code here, to run repeatedly:
sample_glcd.drawRect(0,0,83,47);  
sample_glcd.print("Next page",CENTER,10);
sample_glcd.update();
}
