#include<SD.h>                  // for including SD.h library.
#include<SPI.h>

#define CSE 4                   // for chip selection pin

File example_file;              // for file object.

void setup(){

pinMode(CSE,OUTPUT);

Serial.begin(9600);            // for initializing the Serial communication with 9600 baud rate.

Serial.println("------------------ micro SD card -------------------- \n");

Serial.println("# Initialization of SD card begin...");

// if SD card does not exist or failed to recognize or failed with some error.
if(!SD.begin(CSE)){
  Serial.println("# ERROR: SD initialization failed !");
}
else{
  Serial.println("# SD initialization done :)\n");
}

Serial.println("-------------------------------------------------");

Serial.println("FILE WRITING:");


example_file = SD.open("Sample.txt",FILE_WRITE);

if(example_file){
  Serial.println("# file writing begin...");

  example_file.println("This is sample.txt file WELCOME");

  example_file.close();

  Serial.println("# file writing done :)");
}

else{
  Serial.println("# ERROR: example.txt file opening failed.");
}

Serial.println("-----------------------------------------------\n");

Serial.println("FILE READING:");

example_file = SD.open("sample.txt",FILE_READ);

if(example_file){
  Serial.println("# file reading begin...");

  while(example_file.available()){
    Serial.write(example_file.read());
  }
  example_file.close();

  Serial.println("# file reading done :)");
}

else{
  Serial.println("# ERROR: example.txt file opening failed.");
}
}

void loop(){
  
}
