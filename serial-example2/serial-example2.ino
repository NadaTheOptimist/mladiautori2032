#include "Adafruit_ILI9341.h"

#define dr digitalRead
#define BTN_A 32

Adafruit_ILI9341 TFT = Adafruit_ILI9341(5, 21);

void setup() {
  Serial.begin(9600);
  Serial.print("Ima struje2\n");

  pinMode(BTN_A, INPUT_PULLUP);
}

void loop() {
  String poruka = "BTN_A ";
  if (dr(BTN_A)) {
    poruka += "0";
  }
  else {
    poruka += "1";
  }
  poruka += "\n";
  Serial.print(poruka);
  delay(100);
}
