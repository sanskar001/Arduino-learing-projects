// This is arduino project of LED blinking.
int led_pin=10;    // for led pin number(digital pins)
void setup() { 
  // put your setup code here, to run once:
pinMode(led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led_pin,HIGH);    // led blow
delay(1000);
digitalWrite(led_pin,LOW);     // led not blow
delay(500);
}
