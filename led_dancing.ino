// This is arduino projects of LED dancing.
void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=8;i<=12;i++){
  digitalWrite(i,HIGH);
  delay(100);
  digitalWrite(i,LOW);
  delay(50);
}
for(int j=11;j>=8;j--){
  digitalWrite(j,HIGH);
  delay(100);
  digitalWrite(j,LOW);
  delay(50);
}
for(int a=0;a<=2;a++)
{
  digitalWrite(10+a,HIGH);
  digitalWrite(10-a,HIGH);
  delay(300);
  digitalWrite(10+a,LOW);
  digitalWrite(10-a,LOW);
  delay(100);
}
}
