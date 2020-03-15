// This is arduino project for building the password locker with keypad module.

// firstly include library "Keypad.h"
#include<Keypad.h>

const byte ROWS = 4;  // for four rows.
const byte COLS = 3;  // for three columns.

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}   };

byte rowPins[ROWS] = {13,12,11,10};     // assigning the arduino pins for rows of keypad.
byte colPins[COLS] = {9,8,7};           // assigning the arduino pins for columns of keypad.

// creating the keypad object.
Keypad sample_keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
/////////////////////////////////////////////////////////////////////////////////////////////////////////

char saved_password[7] = {'0','1','2','#','2','1','0'};     // SAVED PASSWORD : 012#210

int correct = 0;            // for checking the correcness of entering password for unlocking
///////////////////////////////////////////////////////////////////////////////////////////////////////

#define enter_button 6      // for entering the password.
#define blue_led 4          // for blue led (for correctness of password).
#define red_led 5           // for red led (for incorrectness of password).

void setup() {
  // put your setup code here, to run once:
pinMode(enter_button,INPUT_PULLUP);
pinMode(blue_led,OUTPUT);
pinMode(red_led,OUTPUT);
 
Serial.begin(9600);      // initializing the Serial Communication with baud rate of 9600.
Serial.println("################# PASSWORD LOCKER #################");
Serial.print("Enter the password:");
}

void loop() {
  // put your main code here, to run repeatedly:
  
int button_value = digitalRead(enter_button);

if(button_value == HIGH){                        // when enter buutton is not pressed.
  char input_key = sample_keypad.getKey();       // returns the pressed key.

  if (input_key != NO_KEY){
    Serial.print("*");
  
    if (input_key == saved_password[correct]){      // checking condition.
      correct++;             // increamenting correctness
    }
  }
}

else if(button_value == LOW){         // when enter button is pressed.
  if(correct == 7){
    Serial.println("");
    Serial.println("PASSWORD CORRECT :)");
    correct = 0;                         // re-enter the password.
    for(int i=1; i<=3; i++){
      digitalWrite(blue_led,HIGH);
      delay(1000);
      digitalWrite(blue_led,LOW);
      delay(500);
    }
    Serial.end();            // stop Serial communication.
  }
  else{
    Serial.println("");
    Serial.println("PASSWORD INCORRECT");
    correct = 0;                        // re-enter the password.
    for(int i=1; i<=5; i++){
      digitalWrite(red_led,HIGH);
      delay(800);
      digitalWrite(red_led,LOW);
      delay(400);
    }
    Serial.println("Do you want to re-Enter the Password(y/n or Y/N):");
    while(Serial.available() == 0){}
    char choice = Serial.read();
    if (choice == 'y' || choice == 'Y'){
      Serial.print("Enter the password again:");
    }
    else{
      Serial.end();           // Serial communication end.
    }
  }
  delay(200);
}

}
