// This is arduino project to understand the functions like readString() , parseInt() and parseFloat().

String person_name;        // string type name variable.
int person_age;            // int type age variable.
String person_gender;      // string type gender variable.
float person_height;       // float type height variable.
float person_weight;       // float type weight variable.
char ch;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);         // this is serial communication baud rate given as 9600.
//Serial.setTimeout(1000*60);  // 1 hour time out.
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("##########################    Person detail   ############################");

Serial.println("What's your name? ");
while(Serial.available()==0){}
person_name=Serial.readString();                 // reading string type name by readString() function.

Serial.println("How old are you? ");
while(Serial.available()==0){}
person_age=Serial.parseInt();                 // reading int type age by parseInt() function.

Serial.println("What's your gender? ");
while(Serial.available()==0){}
person_gender=Serial.readString();               // reading string type gender by readString() function.

Serial.println("How tall are you? ");
while(Serial.available()==0){}
person_height=Serial.parseFloat();               // reading float type height by parseFloat() function.

Serial.println("What's your weight? ");
while(Serial.available()==0){}
person_weight=Serial.parseFloat();                // reading float type weight by parseFloat() function.

Serial.println("###################################################");

Serial.print("Hello ");
Serial.println(person_name);
Serial.print("You are ");
Serial.print(person_age);
Serial.print(" years old,and ");
Serial.print(person_gender);
Serial.println(".");
Serial.print("your height is");
Serial.print(person_height);
Serial.println(" feets");
Serial.print("your weight is ");
Serial.print(person_weight);
Serial.println(" kg");

Serial.println("Do you want to continue? (y/n or Y/N)");
while(Serial.available()==0){}
ch=Serial.read();

if(ch=='y' || ch=='Y'){
  Serial.println("Continue...");
  Serial.println("\n\n");
}
else if(ch=='n' || ch=='N'){
  Serial.println("Thankyou");
  Serial.end();
}
}
