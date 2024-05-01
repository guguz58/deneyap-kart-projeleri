#include <PS2X_lib.h>  //for v1.6
#include <deneyap.h>

#define PS2_DAT        A5  //MISO  19----data
#define PS2_CMD        D9  //MOSI  23----command
#define PS2_SEL        D10  //SS     5 -----attention
#define PS2_CLK        A6  //SLK   18----clock

void ileri() {
  digitalWrite(D3, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D7, HIGH);
  digitalWrite(D8, LOW);
  }

  void stop() {
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D8, LOW);
  digitalWrite(D7, LOW);
  }

  void geri() {
  digitalWrite(D3, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D7, LOW);
  digitalWrite(D8, HIGH);
  }
  void sol() {
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D8, HIGH);
  digitalWrite(D7, LOW);
  }
  void sag() {
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D8, LOW);
  digitalWrite(D7, HIGH);
  }
#define pressures   false
#define rumble      false

PS2X ps2x; // create PS2 Controller Class



//const int sagpwm = 2;      // robot sağ motorlar
//const int sagina = 22;   
//const int saginb = 23;    
//const int solpwm = 3;       // robot sol motorlar
//const int solina = 24;       
//const int solinb = 25;     
//const int altkolpwm = 4;      // robotkol alt kısım motor
//const int altkolina = 26;   
//const int altkolinb = 27;



int error = -1;
byte type = 0;
byte vibrate = 0;
int tryNum = 1;


void setup(){

 Serial.begin(115200);// 115200
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D7, OUTPUT);
  //added delay to give wireless ps2 module some time to startup, before configuring it
  //CHANGES for v1.6 HERE!!! **************PAY ATTENTION*************

  while (error != 0) {
    delay(1000);// 1 second wait
    //setup pins and settings: GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
    error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
    Serial.print("#try config ");
    Serial.println(tryNum);
    tryNum ++;
  }

  Serial.println(ps2x.Analog(1), HEX);
 

  type = ps2x.readType();
  switch(type) {
    case 0:
      Serial.println(" Unknown Controller type found ");
      break;
    case 1:
      Serial.println(" DualShock Controller found ");
      break;
    case 2:
      Serial.println(" GuitarHero Controller found ");
      break;
	  case 3:
      Serial.println(" Wireless Sony DualShock Controller found ");
      break;
   }
}

void loop() {

  if(type == 1){ //DualShock Controller
    ps2x.read_gamepad(false, vibrate); //read controller and set large motor to spin at 'vibrate' speed

    //will be TRUE as long as button is pressed
    if(ps2x.Button(PSB_START))
      Serial.println("Start is being held");

    if(ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held");

    //will be TRUE as long as button is pressed
    if(ps2x.Button(PSB_PAD_UP)) {
  // kod yaz
      Serial.print("Up held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
    }

    if(ps2x.Button(PSB_PAD_RIGHT)){
                 
      delay(150);                         
      Serial.print("Right held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
    }

    if(ps2x.Button(PSB_PAD_LEFT)){
   // kod yaz
       Serial.print("LEFT held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
    }
    
    if(ps2x.Button(PSB_PAD_DOWN)){
   // kod yaz
        Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
    }
    
if (!ps2x.Button(PSB_PAD_DOWN) && !ps2x.Button(PSB_PAD_UP) && !ps2x.Button(PSB_PAD_RIGHT) && !ps2x.Button(PSB_PAD_LEFT)) {
  } 

  
    vibrate = ps2x.Analog(PSAB_CROSS);  //this will set the large motor vibrate speed based on how hard you press the blue (X) button
    if (ps2x.NewButtonState()) {        //will be TRUE if any button changes state (on to off, or off to on)
      if(ps2x.Button(PSB_L3)){
      // KOMUT YAZ
      
        Serial.println("L3 pressed");
        }
      if(ps2x.Button(PSB_R3)){
      // KOMUT YAZ
      
        Serial.println("R3 pressed");
        }
      if(ps2x.Button(PSB_L2)){
      // KOMUT YAZ
     ileri();
     delay(100);
     stop();
        Serial.println("L2 pressed"); 
        }
      if(ps2x.Button(PSB_R2)){
      // KOMUT YAZ
     
        Serial.println("R2 pressed");
       }  
} 
   //△□○× ************     
  //    if(ps2x.Button(PSB_TRIANGLE))
  //     Serial.println("△ pressed");
  //  if(ps2x.ButtonPressed(PSB_CIRCLE))                                     //will be TRUE if button was JUST pressed
  //    Serial.println("○ just pressed");
   // if(ps2x.NewButtonState(PSB_CROSS))                                        //will be TRUE if button was JUST pressed OR released
   //   Serial.println("× just changed");
   // if(ps2x.ButtonReleased(PSB_SQUARE))                                       //will be TRUE if button was JUST released
   //   Serial.println("□ just released");
///*****************************************


if (ps2x.Analog(PSS_LX) == 128) {
   // analogWrite(altkolpwm,LOW); //ÖRNEK KOD
    //digitalWrite(altkolina,LOW);
   
     stop();
     }
if (ps2x.Analog(PSS_LY) == 128){ 
 //   analogWrite(altkolpwm,LOW); 
   // digitalWrite(altkolina,LOW);
  
     stop();
  }

if (ps2x.Analog(PSS_RY) == 128) {
   // digitalWrite(ustkolinb,LOW);  
} 
    
if (ps2x.Analog(PSS_RX) == 128) {
 //  analogWrite(altkolpwm,LOW); 
}   

//************************
if((ps2x.Analog(PSS_LX) < 126) && ((ps2x.Analog(PSS_LY) >= 126) && (ps2x.Analog(PSS_LY) <= 130))){
   // fspeed = map(ps2x.Analog(PSS_LX), 0, 126, 255, 0);// sol
   /// digitalWrite(sagina,HIGH);
  //  digitalWrite(saginb,LOW);
   // digitalWrite(solina,LOW);
   // digitalWrite(solinb,HIGH);
  //  analogWrite(sagpwm, fspeed);
  //  analogWrite(solpwm, fspeed); 
  sol();
  Serial.println(ps2x.Analog(PSS_LX), DEC); } 
  
else if((ps2x.Analog(PSS_LX) > 130) && ((ps2x.Analog(PSS_LY) >= 126) && (ps2x.Analog(PSS_LY) <= 130))){
 //  fspeed = map(ps2x.Analog(PSS_LX), 130, 255, 0,255); sağ
  // digitalWrite(sagina,LOW);
  // digitalWrite(saginb,HIGH);
  // digitalWrite(solina,HIGH);
  // digitalWrite(solinb,LOW);
  // analogWrite(sagpwm, fspeed);
  // analogWrite(solpwm, fspeed); 
  sag();
   Serial.println(ps2x.Analog(PSS_LX), DEC);  }  
  
else if((ps2x.Analog(PSS_LY) < 126) && ((ps2x.Analog(PSS_LX) >= 126) && (ps2x.Analog(PSS_LX) <= 130))){
 // fspeed = map(ps2x.Analog(PSS_LY), 0,126, 255, 0);// ileri
//  digitalWrite(sagina,HIGH);
 // digitalWrite(saginb,LOW);
 // digitalWrite(solina,HIGH);
 // digitalWrite(solinb,LOW);
  //analogWrite(sagpwm, fspeed);
 // analogWrite(solpwm, fspeed);
  ileri();
   
  Serial.println(ps2x.Analog(PSS_LY), DEC); } 

else if((ps2x.Analog(PSS_LY) > 130) && ((ps2x.Analog(PSS_LX) >= 126) && (ps2x.Analog(PSS_LX) <= 130))){
//  fspeed = map(ps2x.Analog(PSS_LY), 130, 255, 0,255); // geri
 // digitalWrite(sagina,LOW);
 // digitalWrite(saginb,HIGH);
 // digitalWrite(solina,LOW);
 // digitalWrite(solinb,HIGH);
 // analogWrite(sagpwm, fspeed);
 // analogWrite(solpwm, fspeed); 
 geri();
  Serial.println(ps2x.Analog(PSS_LY), DEC);}
 
if((ps2x.Analog(PSS_RY) > 130) && ((ps2x.Analog(PSS_RX) >= 126) && (ps2x.Analog(PSS_RX) <= 130))){
 // fspeed = map(ps2x.Analog(PSS_RY), 130, 255, 0, 100);
 // digitalWrite(altkolina,HIGH);
 // digitalWrite(altkolinb,LOW);
//  analogWrite(altkolpwm, fspeed);
  Serial.println(ps2x.Analog(PSS_RY), DEC);}
 
else  if((ps2x.Analog(PSS_RY) < 126) && ((ps2x.Analog(PSS_RX) >= 126) && (ps2x.Analog(PSS_RX) <= 130))){
 // fspeed = map(ps2x.Analog(PSS_RY), 0,126, 200, 0);
 // digitalWrite(altkolina,LOW);
 // digitalWrite(altkolinb,HIGH);
 // analogWrite(altkolpwm, fspeed);
  Serial.println(ps2x.Analog(PSS_RY), DEC);  }

else if((ps2x.Analog(PSS_RX) < 126) && ((ps2x.Analog(PSS_RY) >= 126) && (ps2x.Analog(PSS_RY) <= 130))){
  //fspeed = map(ps2x.Analog(PSS_RX), 0, 126, 200, 0);
  //  digitalWrite(altkolina,LOW);
  //  digitalWrite(altkolinb,HIGH);
  //  analogWrite(altkolpwm, fspeed);
  Serial.println(ps2x.Analog(PSS_RX), DEC);
  }
   
else if((ps2x.Analog(PSS_RX) > 130) && ((ps2x.Analog(PSS_RY) >= 126) && (ps2x.Analog(PSS_RY) <= 130))){
  // fspeed = map(ps2x.Analog(PSS_RX), 130, 255, 0, 80); 
  // digitalWrite(altkolina,HIGH);
  //  digitalWrite(altkolinb,LOW);
  // analogWrite(altkolpwm, fspeed);
  Serial.println(ps2x.Analog(PSS_RX), DEC);
  
  }



    

  }
  delay(50);
}
