#include <deneyap.h>
#include <Deneyap_Servo.h>

Servo servo_TX;
Servo servo_D2;

void setup() {
  servo_TX.attach(D1,0);
  servo_D2.attach(D2,0);
  pinMode(D3, INPUT);
    servo_TX.write(0);
  delay(100);
  servo_D2.write(0);
  delay(100);

}

void loop() {
    if (digitalRead(D3) == 0) {
      servo_TX.write(180);
      delay(100);
      servo_D2.write(0);
      delay(100);
    }
 if (digitalRead(D4) == 0) {
      servo_TX.write(0);
      delay(100);
      servo_D2.write(180);
      delay(100);
    }

}