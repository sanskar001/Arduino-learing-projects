// this is arduino project to understand seven segment led.

#define led_a 7          
#define led_b 6
#define led_c 5
#define led_d 4
#define led_e 3
#define led_f 8
#define led_g 9
#define led_dp 10
#define push_button 11
int data;
int value = 0;
void setup() {
  // put your setup code here, to run once:
for (int i=3; i<=10; i++){     // setting the pin mode as OUTPUT by using loop.
  pinMode(i,OUTPUT);
}
pinMode(push_button,INPUT_PULLUP);
Serial.begin(9600);
}

void seven_segment_led(int num){
  for(int a=3;a<=10;a++){
    digitalWrite(a,HIGH);        // all led is off.
  }

  switch(num){

  // for 0 number display
  case 0:
  digitalWrite(led_a,LOW);
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_dp,LOW);
  break;

  // for 1 number display.
  case 1:
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_dp,LOW);
  break;
   // for 2 number display.
  case 2:
  digitalWrite(led_a,LOW);
  digitalWrite(led_b,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
   // for 3 number display.
  case 3:
  digitalWrite(led_a,LOW);
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 4 number display.
  case 4:
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 5 number display.
  case 5:
  digitalWrite(led_a,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 6 number display.
  case 6:
  digitalWrite(led_a,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 7 number display.
  case 7:
  digitalWrite(led_a,LOW);
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_dp,LOW);
  break;
   // for 8 number display.
  case 8:
  digitalWrite(led_a,LOW);
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 9 number display.
  case 9:
  digitalWrite(led_a,LOW);
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 10(A) number display.
  case 10:
  digitalWrite(led_a,LOW);
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
   // for 11(B) number display.
  case 11:
  digitalWrite(led_c,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 12(C) number display.
  case 12:
  digitalWrite(led_a,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 13(D) number display.
  case 13:
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 14(E) number display.
  case 14:
  digitalWrite(led_a,LOW);
  digitalWrite(led_d,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
 // for 15(F) number display.
  case 15:
  digitalWrite(led_a,LOW);
  digitalWrite(led_e,LOW);
  digitalWrite(led_f,LOW);
  digitalWrite(led_g,LOW);
  digitalWrite(led_dp,LOW);
  break;
  
  default:
  Serial.println("Thats not right");
}
}

void loop() {
  // put your main code here, to run repeatedly:
data=digitalRead(push_button);
if (data==LOW && value<=15){
  seven_segment_led(value);
  value++;
}
else{
  
}
delay(200);
}
