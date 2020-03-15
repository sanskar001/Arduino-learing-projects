
#include<LiquidCrystal.h>
LiquidCrystal sample_lcd(4,5,6,7,8,9);

#define temp_sensor A0
float temp;
int value;
void setup() {
  // put your setup code here, to run once:
pinMode(temp_sensor,INPUT);
Serial.begin(9600);
sample_lcd.begin(16,2);
sample_lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

value = analogRead(temp_sensor);
float v = (value/1023.0)*5000.0;
temp = v/10;
Serial.print("Temperature: ");
Serial.print(temp,1);
Serial.println(" C");
sample_lcd.setCursor(0,0);
sample_lcd.print("Temp: ");
sample_lcd.setCursor(7,0);
sample_lcd.print(temp,1);
sample_lcd.setCursor(12,0);
sample_lcd.print(" C");
delay(1000);
}
