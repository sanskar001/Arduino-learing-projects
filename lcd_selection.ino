// This is arduino project to create menu like structure on lcd screen module with temperature sensing problem.
//###############  Temperature Sensor  ####################
//  # Menu:
//  1.Celius
//  2.Fahrenite
//  3.Kelvin
// selection : Kelvin
//  Temp: 345.34 K
//  Exit..
//##############  Temperature Sensor  #####################

#include<LiquidCrystal.h>    // fitstly including the Lcd library.
LiquidCrystal sample_lcd(4,5,6,7,8,9);  // for making lcd object with assigning the arduino pin with lcd pin.

#define temp_sensor A0
#define selection_button 2
#define pot_for_scroll A1
#define buzzer 12

int pot_value;         // for taking the value of poteniometer for vertical scrolling.
int button_input;      // for taking the value of selection push button.
float temp_c;          // temperature in Centigrade.
float temp_f;          // temperature in Fahrenheit.
float temp_k;          // temperature in Kelvin.
int count = 1;
void setup() {
  // put your setup code here, to run once:
pinMode(temp_sensor,INPUT);
pinMode(selection_button,INPUT_PULLUP);
pinMode(pot_for_scroll,INPUT);
pinMode(buzzer,OUTPUT);

sample_lcd.begin(16,2);          // for initializing the lcd object as 16 by 2 lcd screen.
sample_lcd.clear();
Serial.begin(9600);

//--------------------------------- Initializing the showing on lcd screen.
sample_lcd.setCursor(2,0);
sample_lcd.print("Temp  sensor");
sample_lcd.setCursor(0,1);
sample_lcd.print("----------------");
delay(2000);

sample_lcd.clear();
sample_lcd.setCursor(6,0);
sample_lcd.print("Menu");
sample_lcd.setCursor(5,1);
sample_lcd.print("------");
delay(3000);

//-----------------------------------

for(int i=1;i<=3;i++){
  sample_lcd.clear();
sample_lcd.setCursor(0,0);
sample_lcd.print(">> 1.Celius");
sample_lcd.setCursor(3,1);
sample_lcd.print("2.Fahrenheit");
delay(1000);
sample_lcd.clear();

sample_lcd.setCursor(0,0);
sample_lcd.print(">> 2.Fahrenheit");
sample_lcd.setCursor(3,1);
sample_lcd.print("3.Kelvin");
delay(1000);
sample_lcd.clear();

sample_lcd.setCursor(0,0);
sample_lcd.print(">> 3.Kelvin");
sample_lcd.setCursor(3,1);
sample_lcd.print("----------");
delay(1000);
sample_lcd.clear();
}
}

// This is function for show menu of tempeature in different different units.
void menu_display(int index_value,float temp_c,float temp_f,float temp_k,int count){ 
  switch(index_value){
    case 1:// Temperature in Celius.
            
            if (count%2==0){
              sample_lcd.clear();
            sample_lcd.setCursor(0,0);
            sample_lcd.print("Temp:");
            sample_lcd.setCursor(6,0);
            sample_lcd.print(temp_c,1);
            sample_lcd.setCursor(11,0);
            sample_lcd.print("C");
            sample_lcd.setCursor(10,1);
            sample_lcd.print("Exit...");
            delay(500);
            }
            else{
            sample_lcd.setCursor(0,0);
            sample_lcd.print(">> 1.Celius");
            sample_lcd.setCursor(3,1);
            sample_lcd.print("2.Fahrenheit");
            delay(500);
            } 
           sample_lcd.clear();
           break;
           
    case 2:// Temperature in Fahrenheit.
            
            if (count%2==0){
              sample_lcd.clear();
            sample_lcd.setCursor(0,0);
            sample_lcd.print("Temp:");
            sample_lcd.setCursor(6,0);
            sample_lcd.print(temp_f,1);
            sample_lcd.setCursor(11,0);
            sample_lcd.print("F");
            sample_lcd.setCursor(10,1);
            sample_lcd.print("Exit...");
            delay(500);
            }
            else{
            sample_lcd.setCursor(0,0);
           sample_lcd.print(">> 2.Fahrenheit");
           sample_lcd.setCursor(3,1);
           sample_lcd.print("3.Kelvin");
           delay(500);
            } 
           sample_lcd.clear();
           break;
           
     case 3:// Temperature in Kelvin.
      
            if (count%2==0){
              sample_lcd.clear();
            sample_lcd.setCursor(0,0);
            sample_lcd.print("Temp:");
            sample_lcd.setCursor(6,0);
            sample_lcd.print(temp_k,1);
            sample_lcd.setCursor(12,0);
            sample_lcd.print("K");
            sample_lcd.setCursor(10,1);
            sample_lcd.print("Exit...");
            delay(500);
            }
            else{
            sample_lcd.setCursor(0,0);
           sample_lcd.print(">> 3.Kelvin");
           sample_lcd.setCursor(3,1);
           sample_lcd.print("----------");
           delay(500);
            } 
           sample_lcd.clear();
           break;
           
     default:// Temperature in Kelvin.
     
             if (count%2==0){
              sample_lcd.clear();
            sample_lcd.setCursor(0,0);
            sample_lcd.print("Temp:");
            sample_lcd.setCursor(6,0);
            sample_lcd.print(temp_k,1);
            sample_lcd.setCursor(12,0);
            sample_lcd.print("K");
            sample_lcd.setCursor(10,1);
            sample_lcd.print("Exit...");
            delay(500);
            }
            else{
            sample_lcd.setCursor(0,0);
           sample_lcd.print(">> 3.Kelvin");
           sample_lcd.setCursor(3,1);
           sample_lcd.print("----------");
           delay(500);
            } 
           sample_lcd.clear();
           break;
   }
}



void loop() {
  // put your main code here, to run repeatedly:
int t = analogRead(temp_sensor);
float v = (t/1023.0)*5000.0;
temp_c = v/10;                  // temperature in celius    
temp_f = (1.8*temp_c)+32;       // temperature in fahrenheit.
temp_k = temp_c + 273.15;       // temperature in kelvin.

pot_value = analogRead(pot_for_scroll);     // taking the poteniometer value.
int index_value = (pot_value/30.0)+1;        // defining the index value for menu.
button_input = digitalRead(selection_button);  // taking the button value.

if(button_input == LOW){                  // when selection button get ON.
            digitalWrite(buzzer,1);
            delay(50);
            digitalWrite(buzzer,0);
            count++;
            delay(200);
}
//Serial.print("pot_value:");
//Serial.println(pot_value);
//Serial.print("index_value:");
//Serial.println(index_value);          // index value for vertical menu selection.

//Serial.println(button_input);
//Serial.println("--------");
//Serial.println(count);
//Serial.println("******");

// calling the menu function.
menu_display(index_value,temp_c,temp_f,temp_k,count);

}
