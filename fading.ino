// for pwm pins 3,5,6,9,10,11
// for pwm pins 5,6 frequency is abut 1000Hz.
// for pwm pins 9,10,11 frequency is abour 500Hz.
// This is ardunio project of fading LED(chaning its brightness).
int led_pin=5;
void setup() {
  // put your setup code here, to run once:
pinMode(led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int i=0;
while(i<=255){
  analogWrite(led_pin,i);
  delay(50);
  i+=1;
}
}
