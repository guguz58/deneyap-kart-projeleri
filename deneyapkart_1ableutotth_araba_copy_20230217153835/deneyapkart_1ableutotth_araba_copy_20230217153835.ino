#include "deneyap.h"
#include "BluetoothSerial.h"
BluetoothSerial SerialBT; 

const int sagileri  = D12;  
const int saggeri  = D13;  
const int solileri  = D14; 
const int solgeri  = D15; 

int deger; 

void setup() {

    SerialBT.begin("HyperWhellchair"); 
    pinMode(sagileri, OUTPUT);
    pinMode(saggeri, OUTPUT);
    pinMode(solileri, OUTPUT);
    pinMode(solgeri, OUTPUT);
}
 
void loop() {

    if(SerialBT.available()){     
      deger = SerialBT.read();  
    }
  /***********************İleri****************************/
    if (deger == 'F') {
      digitalWrite(sagileri, 1); 
      digitalWrite(saggeri, 0);
      digitalWrite(solileri, 1);      
      digitalWrite(solgeri, 0); 
    }
  /***********************Geri****************************/
    else if (deger == 'B') {
      digitalWrite(sagileri, 0);   
      digitalWrite(saggeri, 1); 
      digitalWrite(solileri, 0);   
      digitalWrite(solgeri, 1); 
    }
  /***************************Sol*****************************/
    else if (deger == 'L') {
      digitalWrite(sagileri, 1);   
      digitalWrite(saggeri, 0); 
      digitalWrite(solileri, 0); 
      digitalWrite(solgeri, 1); 
    }
  /***************************Sağ*****************************/
    else if (deger == 'R') {
      digitalWrite(sagileri, 0);   
      digitalWrite(saggeri, 1); 
      digitalWrite(solileri,1);   
      digitalWrite(solgeri, 0);     
    }
  /************************Stop*****************************/
    else if (deger == 'S'){
        digitalWrite(sagileri, 0);  
        digitalWrite(saggeri, 0); 
        digitalWrite(solileri, 0);  
        digitalWrite(solgeri, 0);
    }  
}
