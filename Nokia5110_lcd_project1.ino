// This is arduino project  to understand the Nokia 5110 Graphics LCD and its regarding library 'LCD5110_Graph.h'.
// lets do some fun with Nokia 5110 lcd.
// First of all ,lets understand the pin alocation for lcd from arduino  uno board.
//     pin number 11 - RESET(RST)
//     pin number 12 - CHIP SELECT(SCE/CE)
//     pin number 10 - DATA / COMMAND(DC)
//     pin number 9 - DATA IN(DI) or MOSI
//     pin number 8 - SERIAL CLOCK(SCLOCK)

#include<LCD5110_Graph.h>  // for including the library called 'LCD5110_Graph.h'

LCD5110 sample_glcd(8,9,10,11,12);   // for creating the Graphic lcd instance as 'sample_glcd' of LCD5110 class.
// LCD5110 sample_glcd(SCLK,DI,DC,SCE,RST);

extern unsigned char SmallFont[];   // extern is use here to brought this SmallFont array.
extern unsigned char BigNumbers[];
extern unsigned char MediumNumbers[];
extern uint8_t avenger[];
extern uint8_t dragon[];
extern uint8_t english_league[];
extern uint8_t iron_man[];
extern uint8_t kungfu[];

void setup() {
  // put your setup code here, to run once:
sample_glcd.InitLCD(60);     // It initializes the display.
sample_glcd.setFont(SmallFont);     // setting the font type as 'SmallFont'.
}

void loop() {
  // put your main code here, to run repeatedly:
//for(int i = 60; i<=127; i++){
//  sample_glcd.setContrast(i);
//  delay(100);
//}
//delay(1000);
//sample_glcd.print("WELCOME",CENTER,5);
//sample_glcd.print("to",CENTER,20);
//sample_glcd.print("Nokia 5110",CENTER,35);
//sample_glcd.drawRect(0,0,83,47);
//sample_glcd.update();
//delay(1000);
////sample_glcd.invert(true);
////delay(1000);
//sample_glcd.clrScr();
///////////////////////////////////////////////////////
//sample_glcd.print("RANJU",CENTER,10);
//sample_glcd.print("MAHESHWARI",CENTER,25);
//sample_glcd.update();
//delay(2000);   // for 2 seconds.
//sample_glcd.invert(true);   // invert mode on.
//delay(2000);
//sample_glcd.invert(false);     // invert mode off.
//sample_glcd.clrScr();
//sample_glcd.update();
//delay(2000);
/////////////////////////////////////////////////////////

//for(int i=0;i<84;i++){
//  sample_glcd.invPixel(i,0);
//  sample_glcd.update();
//  delay(20);
//}
//for(int i=83;i>=0;i--){
//  sample_glcd.clrPixel(i,0);
//  sample_glcd.update();
//  delay(20);
//}
///////////////////////////////////////////////////////////////////
//int Number1 = 112;
//int Number2 = 22;
//int Number3 = Number1 + Number2;
//sample_glcd.printNumI(Number1,0,20);
//sample_glcd.print("+",20,20);
//sample_glcd.printNumI(Number2,30,20);
//sample_glcd.print("=",50,20);
//sample_glcd.printNumI(Number3,60,20);
//sample_glcd.update();

//float number = 130.243523;
//sample_glcd.printNumF(number,1,CENTER,0);
//sample_glcd.update();

//sample_glcd.print("INVERT",CENTER,0);
//sample_glcd.update();
//delay(2000);
//sample_glcd.invertText(true);
//delay(2000);
//sample_glcd.invertText(false);
//sample_glcd.clrScr();
//sample_glcd.update();
//delay(2000);

/////////////////////////////////////////////////
// for drawing the straight line.
//sample_glcd.drawLine(0,0,83,47);
//sample_glcd.drawLine(83,0,0,47);
//sample_glcd.update();
/////////////////////////////////////////////////
// for drawing the rectangle shape.
//sample_glcd.drawRoundRect(5,5,20,20);
//sample_glcd.drawRoundRect(60,5,75,20);
//sample_glcd.drawRoundRect(15,35,65,47);
//sample_glcd.update();
////////////////////////////////////////////////
// for drawing the crcle shape.
//sample_glcd.drawCircle(40,20,20);
//sample_glcd.update();
///////////////////////////////////////////////////////////////////////
// for showing the images on Nokia 5110 lcd screen.
//sample_glcd.drawBitmap(0,0,avenger,84,48);
//sample_glcd.update();
//delay(2000);
//sample_glcd.clrScr();
//
//sample_glcd.drawBitmap(0,0,dragon,84,48);
//sample_glcd.update();
//delay(2000);
//sample_glcd.clrScr();
//
//sample_glcd.drawBitmap(0,0,english_league,84,48);
//sample_glcd.update();
//delay(2000);
//sample_glcd.clrScr();
//
//sample_glcd.drawBitmap(0,0,iron_man,84,48);
//sample_glcd.update();
//delay(2000);
//sample_glcd.clrScr();
//
//sample_glcd.drawBitmap(0,0,kungfu,84,48);
//sample_glcd.update();
//delay(2000);
//sample_glcd.clrScr();
//////////////////////////////////////////////////////////////
// for  shawing the number on Nokia screen.

sample_glcd.setFont(BigNumbers);
sample_glcd.printNumI(12345,CENTER,0);
sample_glcd.update();

sample_glcd.setFont(MediumNumbers);
sample_glcd.printNumI(12345,CENTER,28);
sample_glcd.update();
}
