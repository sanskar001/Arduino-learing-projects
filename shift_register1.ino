// This is arduino project to create an led binary number display (using the shift register 74hc595).

#define data 8    // arduino 8 pin for data input to register (connect to 14 pin of register).
#define latch 9   // arduino 9 pin for latch to register (connect to 12 pin of register).
#define Clock 10  // arduino 10 pin for clock to register (connect to 11 pin of register).

void setup() {
  // put your setup code here, to run once:
pinMode(data,OUTPUT);  
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<=255;i+=1){
  digitalWrite(latch,LOW);        // for initializing the shifting of data.
  shiftOut(data,Clock,LSBFIRST,i);  // shifting of data happens
  digitalWrite(latch,HIGH);       // shifting of data completed .
  delay(1000);
}
}
