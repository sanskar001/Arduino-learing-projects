// This is arduino project to measure the temperature by temperature sensor LM35,
// showing the result by 8 series led.

#define temp_sensor A0     // for taking the value of analog temperature sensor .
#define data 8
#define latch 9
#define Clock 10
int sensor_value;      // sensor value from 0 to 1023.
int voltage;           // for taking the value of voltage.
float temp;           // temperature in centigrade.
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("############################# Temperature sensor #############################");
pinMode(temp_sensor,INPUT);
pinMode(data,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(Clock,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("-----------------");
Serial.println("Hi, buddy lets do this ...");
sensor_value=analogRead(temp_sensor);
Serial.print("Sensor value:");
Serial.println(sensor_value);
int voltage = (sensor_value*5000.0)/1023.0;
Serial.print("voltage:");
Serial.println(voltage);
temp=voltage/10.0;
Serial.print("temperature :");
Serial.println(temp);
int num = (voltage/100.0);
Serial.print("number:");
Serial.println(num);
int value=pow(2,num)-0.1;
Serial.print("value:");
Serial.println(value);
digitalWrite(latch,LOW);
shiftOut(data,Clock,LSBFIRST,value);
digitalWrite(latch,HIGH);
delay(300);
}
