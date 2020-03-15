// This is arduino program to analyse the temperature and show that on serial monitor.
// The temperature sensor is LM35.

#define temp_sensor A0
int sensor_value;   // for taking the value of sensor from analogRead() function.
float temp_centigrade;         // for taking the value of temperature in centigrade or in celieus.
float temp_fahrenheit;         // for taking the value of temperature in Fahrenheit.
float temp_kelvin;             // for taking the value of temperature in kelvin.
int voltage;        // for taking the value of voltage out from sensor LM35 (in milliVolt).
int count=0;
void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);     // setting baud rate of 9600 for serial communication.
Serial.println("########################## Temperature sensor #############################");
pinMode(temp_sensor,INPUT);          // setting the temperature sensor in input mode.
}

void loop() {
  // put your main code here, to run repeatedly:
count++;
Serial.print("Case ");
Serial.println(count);
sensor_value=analogRead(temp_sensor);
Serial.print("sensor_value:");
Serial.println(sensor_value);

voltage = (5000.0*sensor_value)/1023.0;
Serial.print("voltage out:");
Serial.println(voltage);

temp_centigrade = (voltage/10.0);
Serial.print("Temperature:");
Serial.print(temp_centigrade);
Serial.print(" C");

temp_fahrenheit=(temp_centigrade*1.8)+32.0;
Serial.print(" || ");
Serial.print(temp_fahrenheit);
Serial.print(" F");

temp_kelvin = temp_centigrade+273.15;
Serial.print(" || ");
Serial.print(temp_kelvin);
Serial.println(" K");
Serial.println("---------------------");
delay(1000);   // for some seconds delay.
}
