// This is arduino project to understand basic working with 4*3 keypad module.

#include<Keypad.h>    // firslty include the library "Keypad.h"

const byte ROWS = 4;    // for four rows
const byte COLS = 3;    // for three columns 

// defining the key map (showing symbolic values) throw keypad.
char keys[ROWS][COLS] = 
{{'1','2','3'},
 {'4','5','6'},             // KEYPAD LAYOUT
 {'7','8','9'},
 {'*','0','#'} };

byte rowPins[ROWS] = {13,12,11,10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9,8,7}; //connect to the column pinouts of the keypad

// Defining the constructor for key.
Keypad sample_keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);         // initializing the Serial comm with baud rate 9600.
Serial.println("Input character from keypad:");
}

void loop() {
  // put your main code here, to run repeatedly:
char input_key = sample_keypad.getKey();

if(input_key != NO_KEY){
  Serial.print(input_key);
}
}
