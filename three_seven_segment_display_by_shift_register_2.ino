// This is arduino project to learn how to control three seven segment led display by potentiometer.
// With the help of shift register name 74hc595.
        
#define data 8
#define latch 9
#define Clock 10
#define led_pin 11
#define pot A0
int number_array[]={3,159,37,13,153,73,65,31,1,9};    // This is number array for shift register input.
int input_number;
int number;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);     // setting baud rate of 9600 for Serial communication.
Serial.println("Hi,buddy lets start the game....");
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
pinMode(led_pin,OUTPUT);
pinMode(pot,INPUT);
}

// function for displaying the number from 0 to 9 according to potentiometer.
void function(int a[],int num){
int h_digit=num/100.0;
int t_digit=(num%100)/10.0;
int o_digit=(num%100)%10;
 digitalWrite(latch,LOW);
 shiftOut(data,Clock,LSBFIRST,a[h_digit]);
 shiftOut(data,Clock,LSBFIRST,a[t_digit]);
 shiftOut(data,Clock,LSBFIRST,a[o_digit]);
 digitalWrite(latch,HIGH);
 if (num%111==0){
  digitalWrite(led_pin,HIGH);
 }
 else{
  digitalWrite(led_pin,LOW);
 }
}
int pot_value(){
  int value=analogRead(pot);
  return value;
}
void loop() {
  // put your main code here, to run repeatedly:

input_number=pot_value();
Serial.print("input_number:");
Serial.println(input_number);
number=((999.0*input_number)/1023.0)+0.8;
Serial.print("number:");
Serial.println(number);
function(number_array,number);
}
