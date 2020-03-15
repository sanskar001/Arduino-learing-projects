// This is arduino project of traffic light management.
// This is timer based traffic light.

#define red_led 5
#define yellow_led 6
#define green_led 7
#define push_button 8
void setup() {
  // put your setup code here, to run once:
pinMode(red_led,OUTPUT);
pinMode(yellow_led,OUTPUT);
pinMode(green_led,OUTPUT);
pinMode(push_button,INPUT_PULLUP);
}
int status;
int count=0;
void loop() {
  // put your main code here, to run repeatedly:
status=digitalRead(push_button);
if(status==LOW){
  count++;
}
int a=0;
if((count%2==0)&&(count==0)){
  digitalWrite(red_led,LOW);
  digitalWrite(yellow_led,LOW);
  digitalWrite(green_led,LOW);
}
else if(count%2!=0){
   digitalWrite(red_led,HIGH);
  delay(1000);
  digitalWrite(red_led,LOW);
  delay(100);
  for(int i=1;i<=5;i++){
     digitalWrite(yellow_led,HIGH);
     delay(300);
     digitalWrite(yellow_led,LOW);
     delay(200);
  }
  digitalWrite(green_led,HIGH);
  delay(1000);
  digitalWrite(green_led,LOW);
  delay(100);
}
 }

  
