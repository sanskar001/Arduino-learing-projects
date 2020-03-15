// This is arduino project to create simple function.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Lets create user defined function.");
print("hello world");
print("India");
print(56);
print(4.5321331534);
}
void print(String string){
  Serial.println(string);
}
void print(int number){
  Serial.println(number);
}
void print(float number){
  Serial.println(number);
}
void print(double number){
  Serial.println(number);
}
void loop() {
  // put your main code here, to run repeatedly:

}
