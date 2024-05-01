#include <deneyap.h>


#define RED LEDR
#define BLUE LEDB
#define GREEN LEDG
int  SAYAC = 0;

void setup() {
  pinMode(D0, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);


}

void loop() {
    if (digitalRead(D0) == 1) {
      delay(200);
      SAYAC = SAYAC + 1;
      if (SAYAC == 1) {
        digitalWrite(LEDR,255);
         digitalWrite(LEDG,0);
         digitalWrite(LEDB,0);
      }
      if (SAYAC == 2) {
        digitalWrite(LEDR,0);
         digitalWrite(LEDG,255);
         digitalWrite(LEDB,0);
      }
      if (SAYAC == 3) {
        digitalWrite(LEDR,0);
         digitalWrite(LEDG,0);
         digitalWrite(LEDB,255);
      }
      if (SAYAC == 4) {
        digitalWrite(LEDR,0);
         digitalWrite(LEDG,0);
         digitalWrite(LEDB,0);
        SAYAC = 0;
      }
    
    }

}