#define buzzer A1
void setup() {
  // put your setup code here, to run once:
pinMode(buzzer,OUTPUT);
//ringtone();
}
void ringtone(){
  tone(buzzer,659);   // E5
delay(250);
tone(buzzer,587);   // D5
delay(250);
tone(buzzer,370);   // FS_4
delay(250);
tone(buzzer,415);   // GS_4
delay(250);
tone(buzzer,554);   // CS_5
delay(250);
tone(buzzer,494);   // B4
delay(250);
tone(buzzer,294);   // D4
delay(250);
tone(buzzer,330);   // E4
delay(250);
tone(buzzer,494);   // B4
delay(250);
tone(buzzer,440);   // A4
delay(250);
tone(buzzer,370);   // CS_4
delay(250);
tone(buzzer,330);   // E4
delay(250);
tone(buzzer,440);   // A4
delay(250);

noTone(buzzer);
delay(500);
}
void loop() {
  // put your main code here, to run repeatedly:
// ringtone();
}
