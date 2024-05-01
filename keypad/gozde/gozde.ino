#include <deneyap.h>
#include <Keypad.h>

String sifre = "";
const int satir = 4;
const int sutun = 3;
bool state = false;
char tuslar[satir][sutun] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte satir_pinleri[satir] = { D9, MI, DA1, D10 };
byte sutun_pinleri[sutun] = { SD, SC, MC };

Keypad keypad = Keypad(makeKeymap(tuslar), satir_pinleri, sutun_pinleri, satir, sutun);

void setup() {
  pinMode(D3, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  sifre = String(sifre) + String(keypad.getKey());
  if (sifre == "1453") {
    //sifre = "";
    state = false;
    //delay(1000);
  }
  if (digitalRead(D4) && sifre == "1453") {
    state = false;
  } else if (digitalRead(D4) && sifre != "1453") {
    state = true;
  } else if (!digitalRead(D4) && sifre == "1453")
    state = false;

  int maxLen = 0;
  maxLen = sifre.length();
  char aa = sifre[(maxLen - 1)];
  //Serial.println(String(aa));
  if (aa == '#') {
    delay(80);
    sifre = "";
  }

  Serial.println(sifre);
  digitalWrite(D3, state);
  delay(60);
}
