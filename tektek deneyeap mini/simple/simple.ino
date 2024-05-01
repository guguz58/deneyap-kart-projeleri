#include <Adafruit_NeoPixel.h> //burda hata alıyorsan kütüpanesini yükle
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN       11 //burası data pin
#define NUMPIXELS 60 //buraya led sayısı yazılacak
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 10 

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

float mesafe = 0;
float boy = 0;
float led = 0;

float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}


void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif


  pixels.begin(); 
}

void loop() {
  

    mesafe = getDistance(12,13);
      delay(100);
      if(mesafe < 195 && mesafe > 1){
          boy = (210 - mesafe);
          led = round(((mesafe-10) / 3.3));
 for(int i=led; i<NUMPIXELS; i++) { 
 pixels.setPixelColor(i, pixels.Color(100, 50, 100)); //Beyaz
 pixels.show();   

    delay(DELAYVAL); 
  }
      }
      else {
 for(int i=0; i<NUMPIXELS; i++) { 
 pixels.setPixelColor(i, pixels.Color(0, 0, 0)); //kapalı
 pixels.show();   

    delay(DELAYVAL); 
  }
      }

}
