// This is arduino program to control the eight led series by potentiometer.

#define pot A0   // setting the potentiometer as pin number 11
#define data 8           
#define latch 9
#define Clock 10
int v;          // for calulation purpose only.
int value;      // for taking analog value from potentiometer pin.    
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);   //setting the baud rate 9600 for serial communication.

pinMode(pot,INPUT);     // setting the potentiometer as Input.
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);  
Serial.println("lets do it..");
}
void loop() {
  // put your main code here, to run repeatedly:
value=analogRead(pot);
Serial.print("potentiometer reading:");
Serial.println(value);
v=((255.0*value)/1023.0)+0.5; // for converting the value as (1023 to 255) and (0 to 0).
Serial.print("number:");
Serial.println(v);
digitalWrite(latch,LOW);
shiftOut(data,Clock,LSBFIRST,v);
digitalWrite(latch,HIGH);
delay(1000);           // for some 1 sec delay
}
