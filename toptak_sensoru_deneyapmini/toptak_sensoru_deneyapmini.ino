#include <deneyap.h>

void setup() {
  Serial.begin(115200);
pinMode (A0, INPUT);
 pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
 pinMode(D3,OUTPUT);
}

void loop() {
    if (analogRead(A0) > 6000) {
      delay(1000);
    
digitalWrite(D3, HIGH);
    digitalWrite(LEDR,255);
   digitalWrite(LEDG,0);
   digitalWrite(LEDB,0);
      Serial.print(analogRead(A0));
    }
if (analogRead(A0) < 6000) {
      
    
digitalWrite(D3, LOW);
    digitalWrite(LEDR,0);
   digitalWrite(LEDG,255);
   digitalWrite(LEDB,0);
      Serial.print(analogRead(A0));
      delay(1000);
    }
}