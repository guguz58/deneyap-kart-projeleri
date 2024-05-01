#include <Adafruit_NeoPixel.h> //burda hata alıyorsan kütüpanesini yükle
#ifdef __AVR__
#include <avr/power.h> 
#endif
#define LED_PIN   11 //burası data pin
#define LED_COUNT 60 //buraya led sayısı yazılacak
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  strip.begin();           
  strip.show();            
  strip.setBrightness(250);

}

void loop() {
  rainbow(10);
  }

void rainbow(int wait) {

  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); 
    delay(wait);  
  }
}
