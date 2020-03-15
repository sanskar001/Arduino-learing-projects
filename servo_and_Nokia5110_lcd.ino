// This is arduino project to build pattern on lcd5110 module.

// firslty include the required libraries.(Servo.h and LCD5110_Graph.h)
#include<LCD5110_Graph.h>


LCD5110 sample_glcd(6,5,4,2,3);        // LCD5110 glcd_object(SCLK,DIN,DC,RST,SCE);

extern unsigned char SmallFont[];

void setup() {
  // put your setup code here, to run once:
sample_glcd.InitLCD(50);
sample_glcd.setFont(SmallFont);

sample_glcd.print("SERVO",CENTER,15);
sample_glcd.print("MOTOR",CENTER,28);
sample_glcd.drawRect(0,0,83,47);
sample_glcd.update();
delay(200);
sample_glcd.clrScr();
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=0;i<=40;i+=4){
  sample_glcd.drawLine(42,40,2+i,40-i);
  sample_glcd.update();
  delay(20);
}
for (int i=0;i<=40;i+=4){
  sample_glcd.drawLine(42,40,42+i,i);
  sample_glcd.update();
  delay(20);
}
//sample_glcd.update();
}
