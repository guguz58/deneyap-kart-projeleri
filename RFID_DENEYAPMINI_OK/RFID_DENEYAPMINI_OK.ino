/* >Sivas deneyap günay güzel sorular için guguz58@gmail.com
 *   Deneyap Mini Kart RFIDkartUIDokuma örneği,
 *   RFIDkartUIDokuma uygulamasında RFID NFC modülüne kart okutulunca kartın UIDsini seri port ekrane yazdırmaktadır.
 *   Kart UIDnizi okunduğunda DAHİLİ RGB LED yanmaktadır. 
 
RC522 -> Deneyap Mini Bağlantı 
SDA -> D3
SCK -> MC
MOSI -> MO
MISO -> MI
GND -> GND
RST -> D2
3.3V -> 3.3V
*/

#include <SPI.h>
#include <MFRC522.h>

#define RED LEDR
#define BLUE LEDB
#define GREEN LEDG
#define RST_PIN D2      // RC522: RST -> D3
#define SDA_PIN D3      // RC522: SDA -> D2

MFRC522 rfid(SDA_PIN, RST_PIN);
byte ID[4] = {144,253,48,32};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(LEDR,OUTPUT);
  pinMode(LEDB,OUTPUT);
  pinMode(LEDG,OUTPUT);
}
void loop() {

  if (!rfid.PICC_IsNewCardPresent())     // Yeni kartın okunması beklenir
    {
      BEKLE(); // Kart okutulmazsa mavi LED yanar
      Serial.println("okunamadi");
      delay(1000);
      return;
    }
 
  if (!rfid.PICC_ReadCardSerial())         //Kart okunmadığı zaman beklenilir
  {
      BEKLE(); // Kart okutulmazsa mavi LED yanar
      delay(1000);
      return;
  }
  if (rfid.uid.uidByte[0] == ID[0] &&     //Okunan kart ID'si ile ID değişkeni karşılaştırılır
    rfid.uid.uidByte[1] == ID[1] &&
    rfid.uid.uidByte[2] == ID[2] &&
    rfid.uid.uidByte[3] == ID[3]) {
    DOGRU();         // Okutulan kart doğruysa yeşil LED yanar
    delay(1000);
  } else {         // Okutulan kart yanlışsa bu blok çalışır
    YANLIS();         // Okutulan kart yanlışsa kırmızı LED yanar
    ID_OGREN();        // seri port ekranında kartın ID'si yazılır.
    delay(1000);
  }
  rfid.PICC_HaltA();
}
void BEKLE() {
      digitalWrite(LEDB,HIGH);
      digitalWrite(LEDR,LOW);
      digitalWrite(LEDG,LOW);
}
void DOGRU() {
      digitalWrite(LEDB,LOW);
      digitalWrite(LEDR,LOW);
      digitalWrite(LEDG,HIGH);
          delay(1000);

}
void YANLIS() {
      digitalWrite(LEDB,LOW);
      digitalWrite(LEDR,HIGH);
      digitalWrite(LEDG,LOW);
          delay(1000);

}
void ID_OGREN() {
  Serial.print("ID Numarasi: ");
  for (int sayac = 0; sayac < 4; sayac++) {
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");
  }
  Serial.println("");
}