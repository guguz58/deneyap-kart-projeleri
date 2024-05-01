/*
  Software serial multple serial test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 
 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts, 
 so only the following can be used for RX: 
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
 
 Not all pins on the Leonardo support change interrupts, 
 so only the following can be used for RX: 
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 
 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 */

#include <deneyap.h>
#include <HardwareSerial.h>

HardwareSerial MySerial(1);
#define in1 D2 //L298n Motor Driver pins.
#define in2 D3
#define in3 D9
#define in4 D10
int command; //Int to store app command state.
int Speed = 204; // 0 - 255.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 100; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1; 
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
    MySerial.begin(9600, SERIAL_8N1, DA1, DA0);
}

void loop() {
    if (MySerial.available()) {
    command = MySerial.read();
     
   
    switch (command) {
      ş
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        Serial.print("ali");
        break;
      case 'I':
        Serial.print("ali");
        break;
      case 'H':
        Serial.print("ali");
        break;
      case 'J':
        Serial.print("ali");
        break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 120;
        break;
      case '2':
        Speed = 130;
        break;
      case '3':
        Speed = 150;
        break;
      case '4':
        Speed = 170;
        break;
      case '5':
        Speed = 190;
        break;
      case '6':
        Speed = 200;
        break;
      case '7':
        Speed = 210;
        break;
      case '8':
        Speed = 220;
        break;
      case '9':
        Speed = 240;
        break;
      case 'q':
        Speed = 255;
        break;
        
    }
    Speedsec = Turnradius;
    if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }
  }
}

void forward() {
  analogWrite(in1, HIGH);
  analogWrite(in2, LOW);
  analogWrite(in3, HIGH);
  analogWrite(in4, LOW);
  Serial.print("ileri");

}

void back() {
 analogWrite(in1, LOW);
  analogWrite(in2, HIGH);
  analogWrite(in3, LOW);
  analogWrite(in4, HIGH);
  Serial.print("geri");

}

void left() {
 analogWrite(in1, HIGH);
  analogWrite(in2, LOW);
  analogWrite(in3, LOW);
  analogWrite(in4, HIGH);
  Serial.print("sol");

}

void right() {
 analogWrite(in1, LOW);
  analogWrite(in2, HIGH);
  analogWrite(in3, HIGH);
  analogWrite(in4, LOW);
  Serial.print("sag");}
void Stop() {
 analogWrite(in1, LOW);
  analogWrite(in2, LOW);
  analogWrite(in3, LOW);
  analogWrite(in4, LOW);
  Serial.print("stop");
}

void brakeOn() {
  //Here's the future use: an electronic braking system!
  // read the pushbutton input pin:
  buttonState = command;
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState = buttonState;
  }
}
void brakeOff() {
     // Do something
    }
    
   

