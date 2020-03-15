// This is arduino project to create an 8 led display in which one led is glow one by one automatically (with loop).
// By using the shift register 74hc595 IC.

#define data 8    // arduino 8 pin for data input to register (connect to 14 pin of register).
#define latch 9   // arduino 9 pin for latch to register (connect to 12 pin of register).
#define Clock 10  // arduino 10 pin for clock to register (connect to 11 pin of register).

void setup() {
  // put your setup code here, to run once:
pinMode(data,OUTPUT);     //setting the data pin of arduino as output.
pinMode(latch,OUTPUT);    //setting the latch pin of arduino as output.
pinMode(Clock,OUTPUT);    //setting the clock pin of arduino as output.
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=1;i<=128;i*=2){
  digitalWrite(latch,LOW);        // for initializing the shifting of data.
  shiftOut(data,Clock,LSBFIRST,i);  // shifting of data happens
  digitalWrite(latch,HIGH);       // shifting of data completed .
  delay(500);
}
}
