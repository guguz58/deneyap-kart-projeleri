//SİVAS DENEYAP Günay Güzel-  sorular için  guguz58@gmail.com 
//deneyap 1A için SDA D10 , RST D8, SCK SCK, MOSİ MOSI, MISO MISO
// DENEYAP MİNİ İÇİN SDA D2, RST D3 ,  SCK MS, MOSİ MOSI, MISO MISO
#include <SPI.h>                   	//SPI kütüphanesini tanımlıyoruz.
#include <MFRC522.h>              	//MFRC522 kütüphanesini tanımlıyoruz.
#include <deneyap.h>
#define RED D14     	// Kırmızı LED D14 pinine bağlı
#define BLUE D13   	// Mavi LED D13 pinine bağlı
#define GREEN D12   	// Yeşil LED D12 pinine bağlı
#define RST_PIN D8  	// RC522 modülü reset pini D0'a bağlı
#define SDA_PIN D10  	// RC522 modülü chip select pini D1'e bağlı

MFRC522 rfid(SDA_PIN, RST_PIN); 	//RC522 modülü ayarlarını yapılır.
byte ID[4] = {229,249,251,209};		 //Yetkili kartın ID'si
void setup() {
  Serial.begin(115200); 		//Seri haberleşme başlatılır
  SPI.begin();  			//SPI iletişimi başlatılır.
  rfid.PCD_Init(); 		//RC522 modülü başlatılır.
  pinMode(RED,OUTPUT);  	// LED'ler çıkış olarak ayarlanır
  pinMode(BLUE,OUTPUT);
  pinMode(GREEN,OUTPUT);
  Serial.print("Merhaba Deneyap Sivas");
}
void loop() {;
  if (!rfid.PICC_IsNewCardPresent()) 	// Yeni kartın okunması beklenir
    {
      BEKLE(); // Kart okutulmazsa mavi LED yanar
      delay(1000);
      return;
    }
    
  if (!rfid.PICC_ReadCardSerial()) 		//Kart okunmadığı zaman beklenilir
  {
      BEKLE(); // Kart okutulmazsa mavi LED yanar
      delay(1000);
      return;
  }
  if (rfid.uid.uidByte[0] == ID[0] && 	//Okunan kart ID'si ile ID değişkeni karşılaştırılır
    rfid.uid.uidByte[1] == ID[1] &&
    rfid.uid.uidByte[2] == ID[2] &&
    rfid.uid.uidByte[3] == ID[3]) {
    DOGRU(); 		// Okutulan kart doğruysa yesil LED yanar
    delay(1000);
  } else { 		// Okutulan kart yanlışsa bu blok çalışır
    YANLIS(); 		// Okutulan kart yanlışsa mavi LED yanar
    ID_OGREN();		// seri port ekranında kartın ID'si yazılır.
    delay(1000);
  }
  rfid.PICC_HaltA();
}
void BEKLE() {
      digitalWrite(BLUE,HIGH);
      digitalWrite(RED,LOW);
      digitalWrite(GREEN,LOW);
}
void DOGRU() {
      digitalWrite(BLUE,LOW);
      digitalWrite(RED,LOW);
      digitalWrite(GREEN,HIGH);
}
void YANLIS() {
      digitalWrite(BLUE,LOW);
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,LOW);
}
void ID_OGREN() {
  Serial.print("ID Numarasi: ");
  for (int sayac = 0; sayac < 4; sayac++) {
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");
  }
  Serial.println("");
}

