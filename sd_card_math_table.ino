// This is arduino project to deal with SD card (SD card with SD card adapter).
// In this project we will see how can we write and read mathematical table of natural number.

// Firstly include he required libraries. (SD.h and SPI.h)
#include<SD.h>
#include<SPI.h>

// File object
File table_file4;

#define CSE 4             // for chip selection pin.

void setup() {
  // put your setup code here, to run once:

pinMode(CSE,OUTPUT);

// Intializing the Serial commuincation with baud rate of 9600.
Serial.begin(9600);

Serial.println("--------------------------- SD card ----------------------------");

SD.mkdir("main_folder/sub_folder1/sub_folder3");

// Firstly checking SD card and its adapter interfacing working well or not.
Serial.println("# SD card Initialization begin...");
delay(1000);                                                               // make delay of 1 second.

if(!SD.begin(CSE)){
  Serial.println("# SD card Initialization Failed Due to Several reason!");
}
else{
  Serial.println("# SD card Initialization Done :)");
}

Serial.println("----------------------------------------------------------------------");

// WRITING :

Serial.println("----------------------- WRITING ------------------------");
table_file4 = SD.open("main_folder/sub_folder1/sub_folder2/table4.txt",FILE_WRITE);
if(table_file4){
  Serial.println("Writing begin...");
  
  table_file4.println(5767);
  
  table_file4.close();
  Serial.println("Writing done :)");
}
else{
  Serial.println("ERROR: table4.txt opening failed !");
}


// READING:

Serial.println("----------------------- READING ------------------------");
table_file4 = SD.open("main_folder/sub_folder1/sub_folder2/table4.txt",FILE_READ);
if(table_file4){
  Serial.println("Reading begin...");
  Serial.print("Read data:");
  while(table_file4.available()){
    Serial.write(table_file4.read());
  }
  Serial.print("\n");
  Serial.println(table_file4.name());
  table_file4.close();
  Serial.println("Reading done :)");
}
else{
  Serial.println("ERROR: table4.txt opening failed !");
}


}



void loop() {
  // put your main code here, to run repeatedly:

}
