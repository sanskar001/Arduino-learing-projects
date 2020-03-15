// This is arduino project to make Binary number quiz game.
// In which eight led represent any random number in binary format.
// we have to answer that what its decimal form via Serial monitor.
// if answer is right then tell correct and if wrong then tell Incorrect.

#define data 8       // set pin as 8 for datain for shift register.
#define latch 9      // set pin as 9 for latch for shift register.
#define Clock 10     // set pin as 10 for clock for shift register.
int random_number;
int answer_number;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);     // setting the baud rate 9600 for serial communication.

pinMode(data,OUTPUT);    // setting the datain pin as OUTPUT.
pinMode(latch,OUTPUT);   // setting the latch pin as OUTPUT.
pinMode(Clock,OUTPUT);   // setting the clock pin as OUTPUT.
}

// function for displaying the random binary number by eight series led.
void random_led_display(){
  random_number=random(0,256);    // for taking random between 0 and 255.
  
  digitalWrite(latch,LOW);
  shiftOut(data,Clock,LSBFIRST,random_number);        // data sequence is lsb first.
  digitalWrite(latch,HIGH);
}

// function for getting answer.
int answer_getter(){
  while(Serial.available()==0){}
    int answer_number=Serial.parseInt();
    return answer_number;
}

// function for checking the given answer.
int check_answer(int answer_number,int random_number){
  if (answer_number==random_number){
    return true;
  }
  else{
    return false;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("##########################  BINARY NUMBER QUIZ GAME  ###########################");
Serial.println("Hi, buddy lets start game....");
int count=0;

for (int x=1;x<=5;x++){
random_led_display();
Serial.println("Enter the answer number:");
answer_number=answer_getter();
Serial.print("Answer number:");
Serial.println(answer_number);
if (check_answer(answer_number,random_number)==true){
  Serial.println("Correct");
  count+=10;
}
else if (check_answer(answer_number,random_number)==false){
  Serial.println("Incorrect");
}
}
Serial.print("Your score:");
Serial.println(count);
if (count>30){
  Serial.println("well done buddy");
}
else{
  Serial.println("Bad score,Try again..");
}
}
