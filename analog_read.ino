// This is arduino project to read variable quantity.

#define analog_pin A0
void setup() {
  // put your setup code here, to run once:

//analogReference(INTERNAL);
pinMode(analog_pin,INPUT);   
Serial.begin(9600);   // defining the speed of transmission 9600 bits per second.   
Serial.println("# variable quantity value:");        
}
int output;
void loop() {
  // put your main code here, to run repeatedly:
output=analogRead(analog_pin);
float voltage=(5.0*output*1000.0)/1023.0;
Serial.print("output value:");
Serial.println(output);
Serial.print("voltage:");
Serial.println(voltage,6);
delay(2000);
}
