// This is ardunio projects of pull_down resistor switching.
#define push_button 8
#define led_pin 10
void setup() {
  // put your setup code here, to run once:
pinMode(push_button,INPUT);
pinMode(led_pin,OUTPUT);
}
int status;
void loop() {
  // put your main code here, to run repeatedly:
status=digitalRead(push_button);
if(status==HIGH){
  digitalWrite(led_pin,HIGH);
}
else{
  digitalWrite(led_pin,LOW);
}
}
