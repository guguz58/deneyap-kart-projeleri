#include <Adafruit_NeoPixel.h> //burda hata alıyorsan kütüpanesini yükle
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN       D3 //burası data pin
#define NUMPIXELS 60 //buraya led sayısı yazılacak
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100 

void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif


  pixels.begin(); 
}

void loop() {
  
  for(int i=0; i<NUMPIXELS; i++) { 
 pixels.setPixelColor(i, pixels.Color(0, 150, 0)); //Yeşil
 pixels.show();   

    delay(DELAYVAL); 
  }

  for(int i=0; i<NUMPIXELS; i++) { 
 pixels.setPixelColor(i, pixels.Color(150, 0, 0)); //Kırmızı
 pixels.show();   

    delay(DELAYVAL); 
  }
  
  for(int i=0; i<NUMPIXELS; i++) { 
 pixels.setPixelColor(i, pixels.Color(0, 0, 150)); //Mavi
 pixels.show();   

    delay(DELAYVAL); 
  }

   for(int i=0; i<NUMPIXELS; i++) { 
 pixels.setPixelColor(i, pixels.Color(80, 80, 80)); //Beyaz
 pixels.show();   

    delay(DELAYVAL); 
  }
}
