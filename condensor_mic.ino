// This is arduino project for understanding condenser microphone.

#define mic A0
#define led 5
int data;
int value;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);    // for initializing the serial comm. with baud rate of 9600.
pinMode(mic,INPUT);
pinMode(led,OUTPUT);
Serial.println("Condenser mic input:");
analogReference(INTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:
data = analogRead(mic);
value = (data/1023.0)*255.0;
value = value * 30;
Serial.print("data:");
Serial.println(data);
Serial.print("value:");
Serial.println(value);
analogWrite(led,value);
delay(300);
}
