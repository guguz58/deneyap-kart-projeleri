#include "WiFi.h"
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include "DHT.h"

#include <deneyap.h>


#define WLAN_SSID       "Superbox_Wifi_Farabi"
#define WLAN_PASS       "sivasfarabi"
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "guguz58"
#define AIO_KEY         "aio_EMyB17THLiEe5wLEuczg7j7vjApc"
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish nem = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/nem");
Adafruit_MQTT_Publish sicaklik = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sicaklik");

DHT dht(D0,DHT11);


void MQTT_connect() {
  int8_t ret;
  if (mqtt.connected())
  {
    return;
  }

  Serial.print("Bulut sistemine baglaniliyor... ");
  uint8_t count = 3;

  while ((ret = mqtt.connect()) != 0)
  {
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("3 saniye icinde tekrar baglanti denemesi gerceklesecek...");
    mqtt.disconnect();
    delay(5000);
    count = count - 1 ;

    if (count == 0)
    {
      esp_restart();
    }
  }

  Serial.println("Bulut sistemine baglanildi!");
}

void setup() {
  Serial.print(WLAN_SSID);
 Serial.println(" kablosuz agina baglaniliyor");
 WiFi.begin(WLAN_SSID, WLAN_PASS);
 while (WiFi.status() != WL_CONNECTED)
 {
   delay(500);
   Serial.print(".");
 }
 Serial.println();
 Serial.println("Kablosuz aga baglanildi!");
 Serial.print("IP adresi: ");
 Serial.println(WiFi.localIP());

  Serial.begin(115200);

 // mqtt.subscribe(&nem);
  //mqtt.subscribe(&sicaklik);
  dht.begin();

  //  (char*) nem.lastread;
 // (char*) sicaklik.lastread;

}

void loop() {
  MQTT_connect();
  int  nemoku = dht.readHumidity();
int  sicaklikoku = dht.readTemperature();
    delay(1000);
    nem.publish(nemoku);
    sicaklik.publish(sicaklikoku);

}