// This is arduino project to learn how to control seven segment led display by serial monitor.
// With the help of shift register name 74hc595.

#define data 8
#define latch 9
#define Clock 10
int number_array[]={3,159,37,13,153,73,65,31,1,9};    // This is number array for shift register input.
int input_number;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);     // setting baud rate of 9600 for Serial communication.
Serial.println("Hi,buddy lets start....");
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
}

// function for displaying the number from 0 to 9 according to given input number on serial monitor.
void function(int a[],int num){
digitalWrite(latch,LOW);
shiftOut(data,Clock,LSBFIRST,a[num]-1);
digitalWrite(latch,HIGH);
}

// function for taking input number from serial monitor.
int function_1(){
  Serial.print("Enter the number between 0 and 9 :");
  while(Serial.available()==0){}
  int value=Serial.parseInt();
  return value;
}

void loop() {
  // put your main code here, to run repeatedly:
input_number=function_1();
Serial.println(input_number);

// checking the error of given range(0 to 9).
if (input_number<10){
  function(number_array,input_number);
}
else{
  Serial.println("Error:Input number is out of range as given above");
  function(number_array,8);
}
}
