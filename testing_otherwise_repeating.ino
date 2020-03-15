// This is arduino program to see that, we are taking input number.
// if this number is equal to 90 so, correct.
// else repeating taking number until the correct answer will not come.

int number;      // input number.
int count=0;     // counting the number incorrect stages.
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
// for taking the input number.
void function_1(){
Serial.println("Enter the number:");
while(Serial.available()==0){}
number=Serial.parseInt();
Serial.println(number);
function(number);
}
// for checking the number is equal to 90.
void function(int number){
 if (number==90){
  Serial.println("Correct");
}
else{
  // if number is incorrect then again repeat input means,calling function_1() again again,
  //until correct answer reach.
  Serial.println("Incorrect");
  Serial.println("ok , try again");
  function_1();
  count++;
}
}
void loop() {
  // put your main code here, to run repeatedly:
count=0;
function_1();        // calling the function_1() method.
Serial.print("count:");
Serial.println(count);
}
