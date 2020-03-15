// This is arduino project for making usee defined addition function add()
int result;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
result=add(7,80);                     // add() function call.
Serial.print("result:");
Serial.print(result);
}

int add(int a , int b){              // add() function defination.
  return a+b; 
}

void loop() {
  // put your main code here, to run repeatedly:

}
