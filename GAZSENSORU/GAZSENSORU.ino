#include <deneyap.h>

void setup() {
  Serial.begin(115200);
pinMode(A0, INPUT);
  pinMode(D9, OUTPUT);
  pinMode(D8, OUTPUT);

}

void loop() {
    Serial.println(analogRead(A0));
    delay(400);
    if (analogRead(A0) > 2000) {
      digitalWrite(D9, HIGH);
      digitalWrite(D8, HIGH);
    } else {
      digitalWrite(D9, LOW);
      digitalWrite(D8, LOW);
    }

}