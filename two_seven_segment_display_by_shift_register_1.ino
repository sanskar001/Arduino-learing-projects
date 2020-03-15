// This is arduino project to learn how to control two seven segment led display by loop.
// With the help of shift register name 74hc595.
        
#define data 8
#define latch 9
#define Clock 10
int number_array[]={3,159,37,13,153,73,65,31,1,9};    // This is number array for shift register input.
int number;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);     // setting baud rate of 9600 for Serial communication.
Serial.println("Hi,buddy lets start the game....");
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
}

// function for displaying the number from 0 to 9 according to potentiometer.
void function(int a[]){
for(int y=0;y<7;y++){
for(int x=0;x<10;x++){
digitalWrite(latch,LOW);
shiftOut(data,Clock,LSBFIRST,a[y]);    // for tens digit
shiftOut(data,Clock,LSBFIRST,a[x]);    // for ones digit
digitalWrite(latch,HIGH);
delay(1000);
}
}
}
void loop() {
  // put your main code here, to run repeatedly:
function(number_array);
}
