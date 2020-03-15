// This is arduino project to increament number by toggle switch.
/*
#define push_button 8
int data;
void setup() {
  // put your setup code here, to run once:
pinMode(push_button,INPUT_PULLUP);
Serial.begin(9600);
Serial.println("printing something:");
}
int toggle=0;
void loop() {
  // put your main code here, to run repeatedly:
data=digitalRead(push_button);
if (data==LOW && toggle==0){
  toggle=1;
  Serial.println("hello everyone");
}
else if(data==LOW && toggle==1){
  toggle=0;
  Serial.println("hello");
}
else{
}
delay(200);
}*/

#define push_button 8    
int data;
int value=1;

void setup(){
  pinMode(push_button,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("printing number:");
}

void loop(){
  data=digitalRead(push_button);
  if(data==0 && value<=10){             // conidition for increament through push button.
    Serial.println(value);
    value++;
  }
  else{
    
  }
  delay(200);
}
