#include "Adafruit_ILI9341.h"

Adafruit_ILI9341 TFT = Adafruit_ILI9341(5, 21);

void setup() {
  Serial.begin(9600);
  TFT.begin();
  TFT.setRotation(3);
  TFT.fillScreen(ILI9341_WHITE);
  TFT.setTextColor(ILI9341_BLACK);

  Serial.print("Ima struje\n");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readString();
    TFT.print(input);
  }
}
