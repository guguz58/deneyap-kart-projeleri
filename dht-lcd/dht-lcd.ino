#include <deneyap.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "DHT.h"


LiquidCrystal_I2C lcd1(0x27,16,2);
DHT dht_RX(D0,DHT11);


void setup() {
  Serial.begin(9600);

  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  lcd1.init();
  lcd1.backlight();

  dht_RX.begin();

    

}

void loop() {
int  ISI = dht_RX.readTemperature();
int  NEM = dht_RX.readHumidity();
    Serial.println(ISI);
    Serial.println(NEM);
    if (ISI <= 23 ) {
      
      delay(1000);
      lcd1.setCursor(1,0);
      lcd1.print("Sicaklik: ");
        lcd1.setCursor(11,0);
lcd1.print(ISI);
        lcd1.setCursor(1,1);
     lcd1.setCursor(1,1);
  
      lcd1.print("Kazak Giy");
      digitalWrite(LEDR,255);
   digitalWrite(LEDG,255);
   digitalWrite(LEDB,255);
    }
    if (ISI > 23) {
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
    }

}