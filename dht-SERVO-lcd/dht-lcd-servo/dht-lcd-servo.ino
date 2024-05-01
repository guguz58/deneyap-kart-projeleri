#include <deneyap.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Deneyap_Servo.h>
#include "DHT.h"
Servo servo_TX;
Servo servo_D2;

LiquidCrystal_I2C lcd1(0x27,16,2);
DHT dht_RX(D0,DHT11);


void setup() {
  Serial.begin(9600);
servo_TX.attach(D1,0);
  servo_D2.attach(D2,0);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  lcd1.init();
  lcd1.backlight();

  dht_RX.begin();
   servo_TX.write(0);
  delay(100);
  servo_D2.write(0);
  delay(100);
    

}

void loop() {
int  ISI = dht_RX.readTemperature();
int  NEM = dht_RX.readHumidity();
    Serial.println(ISI);
    Serial.println(NEM);
    if (ISI < 24 ) {
      
      delay(1000);
      lcd1.setCursor(1,0);
      lcd1.print("Sicaklik: ");
        lcd1.setCursor(11,0);
lcd1.print(ISI);
        lcd1.setCursor(1,1);
     lcd1.setCursor(1,1);
 
      servo_D2.write(0);
      delay(100);

      lcd1.print("Kazak Giy");
      digitalWrite(LEDR,255);
   digitalWrite(LEDG,255);
   digitalWrite(LEDB,0);
    }
    if (ISI > 24) {
     // lcd1.clear();
      delay(1000);
       lcd1.setCursor(1,0);
  
      
      lcd1.print("Sicaklik: ");
        lcd1.setCursor(11,0);
lcd1.print(ISI);
        lcd1.setCursor(1,1);
      
      lcd1.print("Tisort Giy");
      digitalWrite(LEDR,255);
   digitalWrite(LEDG,0);
   digitalWrite(LEDB,0);
   
      servo_D2.write(90);
      delay(100);
    }

}