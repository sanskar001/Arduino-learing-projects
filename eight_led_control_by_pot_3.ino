// This is arduino project for making controlling the 8 series led using potentiometer.

#define pot A0     // for potentiomter .
#define data 8
#define latch 9
#define Clock 10
int pot_value;      // sensor value from 0 to 1023.
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("############################# Temperature sensor #############################");
pinMode(pot,INPUT);
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("-----------------");
Serial.println("Hi, buddy lets do this ...");
pot_value=analogRead(pot);
Serial.print("Sensor value:");
Serial.println(pot_value);
int num=(9.0*pot_value)/1024.0;
Serial.print("number:");
Serial.println(num);
int value=pow(2,num)-0.1;
Serial.print("value:");
Serial.println(value);
digitalWrite(latch,LOW);
shiftOut(data,Clock,LSBFIRST,value);
digitalWrite(latch,HIGH);
delay(300);

}
