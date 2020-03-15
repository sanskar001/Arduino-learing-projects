// This is arduino project to change the brightness and to change the volume of buzzer.

#define input_pin A0
#define led_pin 9
#define buzzer_pin 10
void setup() {
  // put your setup code here, to run once:
pinMode(input_pin,INPUT);
pinMode(led_pin,OUTPUT);
pinMode(buzzer_pin,OUTPUT);
Serial.begin(9600);
}
float data;
void loop() {
  // put your main code here, to run repeatedly:
data=analogRead(input_pin);
float c=(data/1023.0)*255.0;
int output=c;
Serial.println(output);
delay(50);
analogWrite(buzzer_pin,output);
analogWrite(led_pin,output);
delay(50);
}
