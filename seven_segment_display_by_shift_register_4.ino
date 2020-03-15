// This is arduino project to learn how to control seven segment led display by potentiometer(trimpot).
// With the help of shift register name 74hc595.

#define pot A0          // setting the potentiometer pin A0.
#define data 8
#define latch 9
#define Clock 10
int number_array[]={3,159,37,13,153,73,65,31,1,9};    // This is number array for shift register input.
int number;
int pot_value;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);     // setting baud rate of 9600 for Serial communication.
Serial.println("Hi,buddy lets start the game....");
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
pinMode(pot,INPUT);
}

// function for displaying the number from 0 to 9 according to potentiometer.
void function(int a[],int num){
digitalWrite(latch,LOW);
shiftOut(data,Clock,LSBFIRST,a[num]-1);
digitalWrite(latch,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
pot_value=analogRead(pot);
Serial.println(pot_value);
number=(10.0*pot_value)/1023.0;         // input number for shift register function.
Serial.print("number:");
Serial.println(number);
function(number_array,number);
}
