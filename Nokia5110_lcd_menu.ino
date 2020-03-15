// This is arduino project  to make menu display for showing different different operation.

#include<LCD5110_Graph.h>   // here i am including the library called as "LCD5110_Graph.h" for Nokia 5110 lcd display.

// Creating the instance of LCD5110 class.
LCD5110 sample_glcd(8,9,10,11,12);   // LCD5110 sample_glcd(SCLK,DIN,DC,RST,SCE);

#define button1 7     // for increamenting the number.
#define button2 6     // for decreamentinig the number.
#define button3 5     // for selecting the options.
int count = 0;         // increamenting and decrementinig number.
int value = 0;         // for entering and exiting purposes.

extern unsigned char SmallFont[];    // including the SmallFont font type.
extern unsigned char TinyFont[];    // including the TinyFont font type.
extern unsigned char MediumNumbers[];
void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);  
//Serial.println(count);


sample_glcd.InitLCD(60);
sample_glcd.setFont(SmallFont);
//sample_glcd.printNumI(count,CENTER,10);
//sample_glcd.update();
pinMode(button1,INPUT_PULLUP);
pinMode(button2,INPUT_PULLUP);
pinMode(button3,INPUT_PULLUP);
}

void function1(int number){
  switch(number){

    case 1:
          sample_glcd.invertText(true);
          sample_glcd.print("1.first     ",2,15);
          sample_glcd.invertText(false);
          sample_glcd.print("2.second    ",2,26);
          sample_glcd.print("3.third     ",2,37);
          sample_glcd.update();
          break;

    case 2:
          sample_glcd.print("1.first     ",2,15);
          sample_glcd.invertText(true);
          sample_glcd.print("2.second    ",2,26);
          sample_glcd.invertText(false);
          sample_glcd.print("3.third     ",2,37);
          sample_glcd.update();
          break;
          
    case 3:
          sample_glcd.print("1.first     ",2,15);
          sample_glcd.print("2.second    ",2,26);
          sample_glcd.invertText(true);
          sample_glcd.print("3.third     ",2,37);
          sample_glcd.invertText(false);
          sample_glcd.update();
          break;   

    default:
          sample_glcd.print("1.first     ",2,15);
          sample_glcd.print("2.second    ",2,26);
          sample_glcd.print("3.third     ",2,37);
          sample_glcd.update();
          break; 
  }
}

void function2(int number){
  switch(number){

    case 1:
           sample_glcd.printNumI(1,CENTER,10);
           sample_glcd.update();
           break;
    case 2:
           sample_glcd.printNumI(2,CENTER,10);
           sample_glcd.update();
           break;
    case 3:
           sample_glcd.printNumI(3,CENTER,10);
           sample_glcd.update();
           break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
int button1_value = digitalRead(button1);
int button2_value = digitalRead(button2);
int button3_value = digitalRead(button3); 

////////////////////////////////////////////////////////////////////

if (button3_value == HIGH & value == 0){

  sample_glcd.drawRect(0,0,83,47);
  sample_glcd.print("MENU",CENTER,2);
  sample_glcd.drawLine(5,12,78,12);
  sample_glcd.update();

  if (count>=0){
    if (button1_value == LOW & button2_value == HIGH){
      count = count + 1;
      if(count > 3){
        count = 1;
      }
//      Serial.println(count);
        delay(150);

    }
    else if (button1_value == HIGH & button2_value == LOW){
      count = count - 1;
      if (count < 1){
        count = 3;
      }
//      Serial.println(count);
        delay(150);
    }
  }
  function1(count); 
}

else if(button3_value == HIGH & value == 1){
  function2(count);
}

else if(button3_value == LOW){
  value = value + 1;
  if (value == 2){
    value = 0;
  }
   sample_glcd.clrScr();
   sample_glcd.update();
   Serial.println(value);
}
delay(220);
////////////////////////////////////////////////////////////////////
}
