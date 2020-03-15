// This is arduino project to learn how to control seven segment led display by push button.
// With the help of shift register name 74hc595.

#define push_button 11
#define data 8
#define latch 9
#define Clock 10
int number_array[]={3,159,37,13,153,73,65,31,1,9};    // This is number array for shift register input.
int number=0;
int button_value;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);     // setting baud rate of 9600 for Serial communication.
Serial.println("Hi,buddy lets start the game....");
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
pinMode(push_button,INPUT_PULLUP);
}

// function for displaying the number from 0 to 9 according to push button.
void function(int a[],int num){
digitalWrite(latch,LOW);
shiftOut(data,Clock,LSBFIRST,a[num]-1);
digitalWrite(latch,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
button_value=digitalRead(push_button);
if(button_value==LOW){
  number++;
// if number is greater than 9.
  if(number>9){
    number=0;
  }
  Serial.print("number:");
  Serial.println(number);
}
function(number_array,number);
delay(200);
}
