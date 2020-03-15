// This is arduino project to make 8 led binary number representation. 
// after giving the input number in serial monitor(from 0 to 255).
// example-->
// In serial monitor -->
// input number: 10
// so,the output on serial monitor is 00001010 and eight led also show this result.
// o --> on led  and x --> off led
// eight led show: xxxxoxox.

#define data 8
#define latch 9
#define Clock 10
int input_number;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("lets begin...");
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Enter the number(0 to 255):");
while(Serial.available()==0){}
input_number=Serial.parseInt();
Serial.print("number:");
Serial.println(input_number);
if(input_number>=0 && input_number<=255)       // only if input_number is between 0 and 255.
{
  Serial.println(String(input_number,BIN));
  
  digitalWrite(latch,LOW);
  shiftOut(data,Clock,LSBFIRST,input_number);
  digitalWrite(latch,HIGH);
}
else{
  Serial.println("Invalid input,Enter the number again:");
}
}
