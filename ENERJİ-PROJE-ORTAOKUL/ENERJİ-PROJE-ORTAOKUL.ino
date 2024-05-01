#include <deneyap.h>
#include <Deneyap_Servo.h>
HardwareSerial SerialBT(1);

int kapikapali=1;
int kapiacik=0;
int pencerekapali=1;
int pencereacik=0;
/*
#define kirmiziLed D12
#define yesilLed D13
#define maviLed D14  */
#define gazsensor A1
#define buzzer D2
#define pirsensor D4

Servo servo_d9;
Servo servo_d8;
void setup() {
  Serial.begin(9600);
  SerialBT.begin(9600, SERIAL_8N1, D1, D0);
  pinMode (D12, OUTPUT);
  pinMode (D13, OUTPUT);
  pinMode (D14, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (gazsensor, INPUT);
  servo_d9.attach(D9);
  servo_d9.write(0);
 servo_d8.attach(D8,1);
  servo_d8.write(0);
}

void loop() {
  if(SerialBT.available()>0) {
    char veri=SerialBT.read();
    Serial.print("Uygulamadan gelen deger: ");
    Serial.println(veri) ;
    delay(50);
  
    //char deger =hc06.available();
    if(veri=='1') {
      digitalWrite(D12, 1);
    }
   else if(veri=='2') {
      digitalWrite(D12, 0);
   }
    if(veri=='3') {
      digitalWrite(D13, HIGH);
    }
    if(veri=='4') {
      digitalWrite(D13, LOW);
    }
    if(veri=='5') {
      digitalWrite(D14, HIGH);
    }
    if(veri=='6') {
      digitalWrite(D14, LOW);
    }
    if(veri=='7') {
      if(kapikapali==1){
        kapikapali--;
        kapiacik++;
         Serial.print("Kapı Kapalı: ");
         Serial.println(kapikapali) ;
         Serial.print("Kapı Açık: ");
         Serial.println(kapiacik) ;
     // for (int derece=0; derece<=100; derece++) {
        servo_d9.write(90);
        delay(15);
      //}   
      }
   }
    if(veri=='8') {
      if(kapiacik==1){
        kapikapali++;
        kapiacik--;
         Serial.print("Kapı Kapalı: ");
         Serial.println(kapikapali) ;
         Serial.print("Kapı Açık: ");
         Serial.println(kapiacik) ;
   //   for (int derece=100; derece>0; derece--) {
        servo_d9.write(0);
        delay(15);   
     // } 
    } 
  }
     if(veri=='9') {
      if(pencerekapali==1){
        pencerekapali--;
        pencereacik++;
         Serial.print("Pencere Kapalı: ");
         Serial.println(pencerekapali) ;
         Serial.print("Pencere Açık: ");
         Serial.println(pencereacik) ;
     // for (int derece=0; derece<=100; derece++) {
        servo_d8.write(90);
        delay(15);
      //}   
      }
   }
    if(veri=='0') {
      if(pencereacik==1){
        pencerekapali++;
        pencereacik--;
         Serial.print("Pencere Kapalı: ");
         Serial.println(pencerekapali) ;
         Serial.print("Pencere Açık: ");
         Serial.println(pencereacik) ;
   //   for (int derece=100; derece>0; derece--) {
        servo_d8.write(0);
        delay(15);   
     } 
    } 
  }
  int deger= analogRead(gazsensor);
  SerialBT.println(deger);
  Serial.print("ortam gaz değeri: ");
  Serial.println(deger);
  delay(1000);
  if(deger<2000) {
    noTone(buzzer);
  }
  if(deger>=2000) {
    tone (buzzer,  1000);
  }
  int hareket=digitalRead(pirsensor);
  if(hareket==1){
    tone (buzzer,  1000);
  }


}
