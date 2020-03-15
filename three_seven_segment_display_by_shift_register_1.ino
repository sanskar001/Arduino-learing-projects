// This is arduino project to learn how to control three seven segment led display by loop.
// With the help of shift register name 74hc595.
        
#define data 8
#define latch 9
#define Clock 10
#define led_pin 11
int number_array[]={3,159,37,13,153,73,65,31,1,9};    // This is number array for shift register input.
int number=-1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);     // setting baud rate of 9600 for Serial communication.
Serial.println("Hi,buddy lets start the game....");
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
pinMode(led_pin,OUTPUT);
}

// function for displaying the number from 0 to 9 according to potentiometer.
void function(int a[]){
  for(int x=0;x<10;x++){
    for(int y=0;y<10;y++){
      for(int z=0;z<10;z++){
        digitalWrite(latch,LOW);
        shiftOut(data,Clock,LSBFIRST,a[x]);
        shiftOut(data,Clock,LSBFIRST,a[y]);
        shiftOut(data,Clock,LSBFIRST,a[z]);
        digitalWrite(latch,HIGH);
        number++;
        if (number%111==0){
          digitalWrite(led_pin,HIGH);
          Serial.println(number);
          delay(2000);
        }
        else{
          digitalWrite(led_pin,LOW);
        }
        delay(100);
      }
    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:
function(number_array);
}
