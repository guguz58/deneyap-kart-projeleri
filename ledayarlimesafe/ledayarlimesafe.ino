#include <FastLED.h> //Kütüphane import 
#define NUM_LEDS 10 //Led Sayısı
#define DATA_PIN 7 //Led Din giriş pini
CRGB leds[NUM_LEDS]; //Led Dizisi oluşturduk
void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); //Fastlede led dizimizi ekledik
  FastLED.setBrightness(255); //Parlaklık ayarı 0-255
}
void loop() {
  leds[0].setRGB(255, 255, 255); //ilk 5 ledi kırmızı
  delay(1000); FastLED.show();
  delay(1000);leds[1].setRGB(255, 0, 0); //yakıyoruz
 FastLED.show();delay(1000);  leds[2].setRGB(255, 0, 0);
FastLED.show(); delay(1000);  leds[3].setRGB(255, 0, 0);
FastLED.show() ; delay(1000);  leds[4].setRGB(255, 0, 0);
  FastLED.show();  //Değişiklikleri gösteriyoruz
  delay(1000);  // 1 sn bekliyoruz
  leds[5].setRGB(0, 0, 255); //sonraki 5 ledi
  leds[6].setRGB(0, 0, 255); //mavi
  leds[7].setRGB(0, 0, 255);
  leds[8].setRGB(0, 0, 255);
  leds[9].setRGB(0, 0, 255);
  FastLED.show(); //Değişiklikleri gösteriyoruz
  delay(1000); // 1 sn bekliyoruz
  leds[0].setRGB(0, 0, 0); //0-9 yani
  leds[1].setRGB(0, 0, 0); //10 adet ledi
  leds[2].setRGB(0, 0, 0); //kapatıyoruz.
  leds[3].setRGB(0, 0, 0); //(Ledi söndürdük)
  leds[4].setRGB(0, 0, 0);
  leds[5].setRGB(0, 0, 0);
  leds[6].setRGB(0, 0, 0);
  leds[7].setRGB(0, 0, 0);
  leds[8].setRGB(0, 0, 0);
  leds[9].setRGB(0, 0, 0);
  FastLED.show();//Değişiklikleri gösteriyoruz
  delay(1000); // 1 sn bekliyoruz
}