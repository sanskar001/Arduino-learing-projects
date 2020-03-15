// This is arduino project to understand the work between serial commmunication and Nokia 5110 lcd module.

#include<LCD5110_Graph.h> // including the library.

// creating the lcd instance as name  sample_glcd.
LCD5110 sample_glcd(8,9,10,11,12);  // LCD5110 sample_lcd(SCLK,DIN,DC,RST,SCE);

String sample_string;   // it is String type variable.
int sample_number;      // it is integer type variable.
float sample_fnumber;   // it is floating type variable.

extern unsigned char SmallFont[];

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);   // Intializing the Serial Communication with baud rate of 9600.

sample_glcd.InitLCD(60);
sample_glcd.setFont(SmallFont);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Enter the sample string:");
while(Serial.available()==0){}
sample_string = Serial.readString();

Serial.println("Enter the sample number:");
while(Serial.available() == 0){}
sample_number = Serial.parseInt();

Serial.println("Enter the floating sample number:");
while(Serial.available() == 0){}
sample_fnumber = Serial.parseFloat();
// for Nokia 5110 LCD screen
sample_glcd.drawRect(0,0,83,47);
sample_glcd.print(sample_string,CENTER,5);
sample_glcd.printNumI(sample_number,CENTER,15);
sample_glcd.printNumF(sample_fnumber,3,CENTER,25);
sample_glcd.update();

// for Serial monitor.
Serial.print("sample string:");
Serial.println(sample_string);

Serial.print("sample integer number:");
Serial.println(sample_number);

Serial.print("sample floating number:");
Serial.println(sample_fnumber,3);
}
