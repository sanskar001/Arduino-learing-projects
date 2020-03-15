// This is arduino project of pull_up switching.
#define led_pin 9
#define push_button 3
void setup() {
  // put your setup code here, to run once:
pinMode(push_button,INPUT_PULLUP);
pinMode(led_pin,OUTPUT);
}
int status;
void loop() {
  // put your main code here, to run repeatedly:
status=digitalRead(push_button);
if(status==HIGH){                  // really switch is open.
  digitalWrite(led_pin,LOW);
}
else{                              // really switch is closed.
  digitalWrite(led_pin,HIGH);
}
}
