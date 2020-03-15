// This is arduino program to control the eight led series by pushbutton.

#define push_button 11   // setting the push button as pin number 11
#define data 8           
#define latch 9
#define Clock 10
int value;
int number=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(push_button,INPUT_PULLUP);
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
Serial.println("lets do it..");
}

// function for making this led control.
void function(int num){
  
  Serial.println(num);
  digitalWrite(latch,LOW);
  shiftOut(data,Clock,LSBFIRST,num);
  digitalWrite(latch,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
value=digitalRead(push_button);
if (value==LOW){
  function(number);
  number++;
}
else{
}
delay(200);
}
