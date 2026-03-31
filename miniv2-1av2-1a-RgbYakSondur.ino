/*
 *   RgbYakSondur örneği,
 *   Deneyap Geliştirme Kartlarının üzerinde yer alan RGB led 400 milisaniye arayla Kırmızı, Yeşil, Mavi, Turuncu, Magenta, 
 *   Cyan, Beyaz renkleri yakmaktadır. 
*/
#define gecikme_suresi 400  // milisaniye

void setup() {

}

void loop() {

  neopixelWrite(RGBLED, 0, 0, 64);  // Parlaklık değeri 64 seçilmiştir. 0-255 arası parlaklık değeri verilmektedir.
  delay(gecikme_suresi);

  // Yeşil
  neopixelWrite(RGBLED, 0, 64, 0);
  delay(gecikme_suresi);

  // Kırmızı
  neopixelWrite(RGBLED, 64, 0, 0);
  delay(gecikme_suresi);

  // Beyaz
  neopixelWrite(RGBLED, 64, 64, 64);
  delay(gecikme_suresi);

  // Renk Yok
  neopixelWrite(RGBLED, 0, 0, 0);
  delay(gecikme_suresi);

  // Cyan
  neopixelWrite(RGBLED, 0, 64, 64);
  delay(gecikme_suresi);

  // Meganta
  neopixelWrite(RGBLED, 64, 0, 64);
  delay(gecikme_suresi);

  // Sarı
  neopixelWrite(RGBLED, 64, 64, 0);
  delay(gecikme_suresi);

}
