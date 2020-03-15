// This is arduino project to learn how to control seven segment led display by shift register 74hc595.

#define data 8
#define latch 9
#define Clock 10
int number_array[]={3,159,37,13,153,73,65,31,1,9};    // This is number array for shift register input.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);     // setting baud rate of 9600 for Serial communication.

pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
}

// function for displaying the number from 0 to 9 with the help of shift register.
void function(int a[]){
for(int x=0;x<10;x++){
digitalWrite(latch,LOW);
shiftOut(data,Clock,LSBFIRST,a[x]);
digitalWrite(latch,HIGH);
delay(500);
}
}

// function for displaying the number with decimal point with the help of shift register.
void function_1(int a[]){
  for(int x=0;x<10;x++){
   digitalWrite(latch,LOW);
   shiftOut(data,Clock,LSBFIRST,a[x]-1);
   digitalWrite(latch,HIGH);
   delay(500); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
function(number_array);
delay(2000);
function_1(number_array);
delay(2000);
}
