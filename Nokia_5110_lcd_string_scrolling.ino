// This is arduino project with Nokia 5110 lcd module for horizontal string scrolling.

#include<LCD5110_Graph.h>  // firstly inlcude the lcd library.

LCD5110 sample_glcd(8,9,10,11,12);    // create the lcd instance as name "sampe_glcd".

extern unsigned char SmallFont[];

void setup() {
  // put your setup code here, to run once:
sample_glcd.InitLCD(67);
sample_glcd.setFont(SmallFont);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int x=-80;x<84;x++){
  sample_glcd.print("Left to Right",x,15);
  sample_glcd.update();
  delay(50);
}

for(int x=84;x>-80;x--){
  sample_glcd.print("Right to Left ",x,30);
  sample_glcd.update();
  delay(50);
}
}
