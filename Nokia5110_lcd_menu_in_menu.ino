// This is arduino project to making menu inside menu means sub-menu.
//example:
//        1.Temperature
//            1.1 Celius
//            1.2 Kelvin
//            1.3 Fahrenheit
//        2.Calculator
//        3.Images
//        4.Grpahs
//        5.Counting
//        etc....

#include<LCD5110_Graph.h>   // firstly include LCD5110 library.

LCD5110 sample_glcd(8,9,10,11,12);  // creating LCD instance.

extern unsigned char SmallFont[];   // including SmallFont font type.

extern uint8_t screen[];      // for main screen and menu screen.

extern uint8_t setting[];
extern uint8_t gallery[];
extern uint8_t volume[];
extern uint8_t torch[];                    // menu icons images
extern uint8_t internet[];
extern uint8_t games[];
extern uint8_t contrast[];

extern uint8_t cricket[];
extern uint8_t football[];                 // games icons images
extern uint8_t puzzle[];

extern uint8_t iron_man[];
extern uint8_t dragon[];                  // images
extern uint8_t kungfu[];
extern uint8_t english_league[];

///////////////////////////////////////////////////////
#define select_button 7     // selection button
#define exit_button 6        // exiting button
#define lt_scroll_button 5    // left and top scrolling button.
#define rd_scroll_button 4     // right and down scrolling button.
#define buzzer 3           // for buzzer.

int button1_value;
int button2_value;     // for storing the button input value.
int button3_value;
int button4_value;

int main_value = 0;    // for level of operation or level of screen display.
int menu_value = 0;    // for selecting the menu icons or app.

/////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:

pinMode(select_button,INPUT_PULLUP);
pinMode(exit_button,INPUT_PULLUP);
pinMode(lt_scroll_button,INPUT_PULLUP);
pinMode(rd_scroll_button,INPUT_PULLUP);

pinMode(buzzer,OUTPUT);     

sample_glcd.InitLCD(60);      // itializing the LCD.
sample_glcd.setFont(SmallFont);
//starting();
}
///////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION1:
// This is function for making the start display.
void starting(){
  sample_glcd.clrScr();
  sample_glcd.drawRect(0, 0, 83, 47);
  for (int i=0; i<48; i+=4)
  {
    sample_glcd.drawLine(0, i, i*1.75, 47);
    sample_glcd.update();
    delay(100);
  }
  for (int i=0; i<48; i+=4)
  {
    sample_glcd.drawLine(83, 47-i, 83-(i*1.75), 0);
    sample_glcd.update();
    delay(100);
  }
  delay(1000);   // delay of 1 second
  sample_glcd.print("NOKIA",CENTER,15);   // printing the string "NOKIA 3310" on screen.
  sample_glcd.print("3310",CENTER,24);
  sample_glcd.update();
  delay(3000);     // delay of 3 seconds
  sample_glcd.clrScr();
  sample_glcd.update();
}
////////////////////////////////////////////////////////
// FUNCTION2:
// This is function for buzzer sound on switch click.
void sound(){
  digitalWrite(buzzer,HIGH);
  delay(10);
  digitalWrite(buzzer,LOW);
  delay(250);
}


// FUNCTION3:
// This is function for showing the main screen.
void main_screen(){
  sample_glcd.clrScr();
  sample_glcd.drawBitmap(0,0,screen,84,48);
  sample_glcd.print("NOKIA",CENTER,15);
  sample_glcd.print("Menu",CENTER,38);
  sample_glcd.drawLine(0,47,83,47);
  sample_glcd.update(); 
}


// FUNCTION4:
// This is function for showing the menu screen.
void menu_screen(int icon_number){                      // MENU SCREEN
  switch(icon_number){
    case 0:  
          sample_glcd.clrScr();
          sample_glcd.drawBitmap(0,0,screen,84,48);        
          sample_glcd.drawBitmap(30,15,setting,30,30);      // SETTING ICON
          sample_glcd.print("Setting",CENTER,5);
          sample_glcd.update();
          break;
    case 1:
          sample_glcd.clrScr();
          sample_glcd.drawBitmap(0,0,screen,84,48);        
          sample_glcd.drawBitmap(30,15,volume,30,30);      // VOLUME ICON
          sample_glcd.print("Volume",CENTER,5);
          sample_glcd.update();
          break;
    case 2:
          sample_glcd.clrScr();
          sample_glcd.drawBitmap(0,0,screen,84,48);        
          sample_glcd.drawBitmap(30,15,contrast,30,30);      // CONTRAST ICON
          sample_glcd.print("Contrast",CENTER,5);
          sample_glcd.update();
          break;
    case 3:
          sample_glcd.clrScr();
          sample_glcd.drawBitmap(0,0,screen,84,48);        
          sample_glcd.drawBitmap(30,15,games,30,30);      // GAMES ICON
          sample_glcd.print("Games",CENTER,5);
          sample_glcd.update();
          break;
    case 4:
          sample_glcd.clrScr();
          sample_glcd.drawBitmap(0,0,screen,84,48);        
          sample_glcd.drawBitmap(30,15,internet,30,30);      // INTERNET ICON
          sample_glcd.print("Internet",CENTER,5);
          sample_glcd.update();
          break;
    case 5:
          sample_glcd.clrScr();
          sample_glcd.drawBitmap(0,0,screen,84,48);        
          sample_glcd.drawBitmap(30,15,torch,30,30);      // TORCH ICON
          sample_glcd.print("Torch",CENTER,5);
          sample_glcd.update();
          break;
    case 6:
          sample_glcd.clrScr();
          sample_glcd.drawBitmap(0,0,screen,84,48);        
          sample_glcd.drawBitmap(30,15,gallery,30,30);      // GALLERY ICON
          sample_glcd.print("Gallery",CENTER,5);
          sample_glcd.update();
          break;
  }

}

//FUNCTION5:
// This is function for showing functionality of apps in menu.
void app_function(int app_number){                             // INSIDE  APP
  switch(app_number){
    case 0:
          sample_glcd.clrScr();
          sample_glcd.print("Inside",CENTER,10);            
          sample_glcd.print("Setting",CENTER,20);           // INSIDE SETTING APP
          sample_glcd.update();
          break;

    case  1:
          sample_glcd.clrScr();
          sample_glcd.print("Inside",CENTER,10);
          sample_glcd.print("Volume",CENTER,20);           // INSIDE VOLUME APP
          sample_glcd.update();
          break;

    case 2:
          sample_glcd.clrScr();
          sample_glcd.print("Inside",CENTER,10);          // INSIDE CONTRAST APP
          sample_glcd.print("Contrast",CENTER,20);
          sample_glcd.update();
          break;

    case 3:
          sample_glcd.clrScr();
          sample_glcd.print("Inside",CENTER,10);        // INSIDE GAMES APP
          sample_glcd.print("Games",CENTER,20);
          sample_glcd.update();
          break;

    case 4:
          sample_glcd.clrScr();
          sample_glcd.print("Inside",CENTER,10);
          sample_glcd.print("Internet",CENTER,20);        // INSIDE INTERNET APP
          sample_glcd.update();
          break;

    case 5:
          sample_glcd.clrScr();
          sample_glcd.print("Inside",CENTER,10);
          sample_glcd.print("Torch",CENTER,20);          // INSIDE TORCH APP
          sample_glcd.update();
          break;
    
    case 6:
          sample_glcd.clrScr();
          sample_glcd.print("Inside",CENTER,10);
          sample_glcd.print("Gallery",CENTER,20);        // INSIDE GALLERY APP
          sample_glcd.update();
          break;
     
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
////////////////////////////////////////////////////////
// for getting the button status.
button1_value = digitalRead(select_button);
button2_value = digitalRead(exit_button);
button3_value = digitalRead(lt_scroll_button);
button4_value = digitalRead(rd_scroll_button);
///////////////////////////////////////////////////////
// WHEN MAIN SCREEN IS DISPLAYING.
if(main_value == 0){
  if(button1_value == LOW){     // when select button is press
    main_value = 1;
    sound();
  }
  else{
    main_screen();
  }
}

// WHEN MENU SCREEN IS DISPLAYING.
else if(main_value == 1){
   if(button2_value == LOW){      // when exit button is press in menu.
    main_value = 0;
    sound();
  }
  else{
    menu_screen(menu_value);       // calling menu screen function.
    
    if(button4_value == LOW){      // when right scroll button press in menu.
      menu_value++;
      if(menu_value == 7){
        menu_value = 0;
      }
      sound();
    }
    
    else if(button3_value == LOW){    // when left scroll button press in menu.
      menu_value--;
      if(menu_value == -1){
        menu_value = 6;
      }
      sound();
    }

    else if(button1_value == LOW){     // when select button press in menu.
      main_value = 2;
      app_function(menu_value);
      sound();
    }
  }
}

// WHEN INSIDE APP IS DISPLAYING.
else if(main_value == 2){
  if(button2_value == LOW){      // when exit button is  press inside app function.
    main_value = 1;
    sound();
  }
  else{
    app_function(menu_value);    
  }
}
//////////////////////////////////////////////////////


}
