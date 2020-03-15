// This is arduino project to understand about read() function.
char character;    // Input character variable.
char d;            // Input decision variable.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);   // This is serial communication baud rate 9600
}
void loop() {
  // put your main code here, to run repeatedly:
  
Serial.println("Enter the character:");
while(Serial.available()==0){ }  // while loop is going on until the input recieve.
  character=Serial.read();      // reading one character.

Serial.println("##################################");
Serial.print("Input character: ");
Serial.println(character);

Serial.println("Do you want to continue(y/n or Y/N):");
while(Serial.available()==0){ }
   d=Serial.read();

if (d=='n' || d=='N'){
  Serial.end();
}
else if(d=='y' || d=='Y'){
  Serial.println("Continue....");
}
}
