// This is arduino project to create function to blink led.
//as per given number of times.
// if num=3
// then led blink for 3 times.

#define led_pin 7
#define push_button 8
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(led_pin,OUTPUT);
pinMode(push_button,INPUT_PULLUP);
}

void led_blinking(int num){
  for (int i=1; i<=num; i++){
    digitalWrite(led_pin,HIGH);
    delay(500);
    digitalWrite(led_pin,LOW);
    delay(250);
  }
}
int data;
void loop() {
  // put your main code here, to run repeatedly:
data=digitalRead(push_button);
if (data==LOW){
  Serial.println(data);
  led_blinking(5);
}
else{
  Serial.println(data);
  digitalWrite(led_pin,LOW);
}
delay(500);
}
