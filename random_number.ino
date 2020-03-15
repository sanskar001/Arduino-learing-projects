// This is arduino project to understand the random() function.
int value;

#define led1 7
#define led2 8
#define led3 9
#define led4 10
#define led5 11
#define led6 12

void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
Serial.begin(9600);
}

void dice_function(int value){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  
  switch(value){
  case 1:
  digitalWrite(led1,HIGH);
  break;

  case 2:
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  break;

  case 3:
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  break;

  case 4:
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  break;

  case 5:
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  break;
  
  case 6:
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  break;

  default: 
  Serial.println("Thats not right");
  break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
value=random(1,7);
Serial.println(value);
dice_function(value);
delay(500);
}
