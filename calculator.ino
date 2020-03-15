// This is arduino project to make calculator using function concept.

float number1;      // float type number1 varibale to store first number(first operand).
float number2;      // float type number2 varibale to store second number(second operand).
float result;       // float type result varibale to store the result of operation.
char ch;            // for taking noting decision.
int choice;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  // to start serial communicatio of baud rate 9600.
}
// function for addition
float add(float a, float b){
  return a+b;
}

//function for substraction
float sub(float a, float b){
  return a-b; 
}

//function for multiplication
float mul(float a, float b){
  return a*b;
}

//function for division
float divi(float a, float b){
  return a/b;
}

//function for taking decision for continue more.
void decision(char ch){
  Serial.println("Do you want to continue?(y/n or Y/N):");
  while(Serial.available()==0){}
  ch=Serial.read();
  if(ch=='y' || ch=='Y'){
    Serial.println("Continue...");
    Serial.println("\n\n");
  }
  else if(ch=='n' || ch=='N'){
    Serial.println("Thankyou");
    Serial.end();                         // for ending the serial communication.
  }
}
void loop() {
  // put your main code here, to run repeatedly:

Serial.println("#############################   Calculator   ##############################");

Serial.println("1.Addition");
Serial.println("2.Substaction");
Serial.println("3.Multiplication");
Serial.println("4.Division");

Serial.println("Enter the choice(1,2,3,4):");
while(Serial.available()==0){}
choice=Serial.parseInt();

Serial.println("Enter the number1:");
while(Serial.available()==0){}
  number1=Serial.parseInt();

Serial.println("Enter the number2:");
while(Serial.available()==0){}
  number2=Serial.parseInt();

switch(choice){
  // addition
  case 1:
  result=add(number1,number2);
  Serial.print("Result of addition: ");
  Serial.println(result);
  break;

  //substraction
  case 2:
  result=sub(number1,number2);
  Serial.print("Result of substraction: ");
  Serial.println(result);
  break;

  //multiplication
  case 3:
  result=mul(number1,number2);
  Serial.print("Result of multiplication: ");
  Serial.println(result);
  break;
  
  //division
  case 4:
  result=divi(number1,number2);
  Serial.print("Result of division: ");
  Serial.println(result);
  break;

  //otherwise
  default:Serial.println("Thats not right");
  break;
}
// for continue... or not.
decision(ch);
}
