#include <deneyap.h>
#include <HCSR04.h>

int  MESAFE;

UltraSonicDistanceSensor distanceSensor_MO(D4,D5);

void setup() {
  Serial.begin(115200);

  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);

}

void loop() {
  MESAFE = distanceSensor_MO.measureDistanceCm();
   // delay(20);
    Serial.println(MESAFE);
    if (MESAFE > 1 && MESAFE < 10) {
      digitalWrite(D2, HIGH);
      delay(1000);
      digitalWrite(D3, HIGH);
      delay(1000);
      digitalWrite(D8, HIGH);
      delay(1000);
      digitalWrite(D9, HIGH);
      delay(1000);
      digitalWrite(D10, HIGH);
      delay(1000);
    } else {
      digitalWrite(D2, LOW);
      delay(1000);
      digitalWrite(D3, LOW);
      delay(1000);
      digitalWrite(D8, LOW);
      delay(1000);
      digitalWrite(D9, LOW);
      delay(1000);
      digitalWrite(D10, LOW);
      delay(1000);
    }

}