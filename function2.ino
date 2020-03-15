// This is  arduino project to create function to add two numbers.
int c;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Lets create addition function.");
c = add(2,34);           // this is function call
Serial.println(c);
Serial.println(add(8,90));
Serial.println(add(3,4,5));
}

int add(int a , int b){      // this is function defination
  return a+b; 
}
int add(int a, int b, int c){
  return a+b+c;
}

void loop() {
  // put your main code here, to run repeatedly:

}
