#include "Adafruit_ILI9341.h"
#include "Adafruit_GFX.h"

// konstante, pinovi na Vidi-Xu su uvijek ovakvi
#define TFT_CS 5
#define TFT_DC 21

// napravi varijablu za ekran

Adafruit_ILI9341 TFT = Adafruit_ILI9341(TFT_CS, TFT_DC);

// konstantni pinovi za gumbe
const int ButtonA = 32;

void setup() {
  // setup se ponovi jedanput

  // svaki od gumba definirati pin mode kao INPUT_PULLUP
  pinMode(ButtonA, INPUT_PULLUP);

  Serial.begin(9600); // pokreni serijsku komunikaciju s računalom
  // otvori serial monitor da pregledaš poruke sa ctrl+shift+m

  Serial.println("Pokrenut Vidi-X");

  // inicijalizacija ekrana
  TFT.begin();
  TFT.setRotation(3); // o ovome ovisi gdje je 0, 0 u koordinatnom sustavu na ekranu
  TFT.fillScreen(ILI9341_BLACK);

  // postavke teksta na ekranu
  TFT.setTextColor(ILI9341_BLUE, ILI9341_BLACK); // parametri:  foreground, background
  TFT.setTextSize(5);
  TFT.print("Zdravo, svijete!"); // ispis na ekran
}

void loop() {
  delay(1000);

  if(digitalRead(ButtonA) == LOW){
    TFT.fillScreen(ILI9341_BLACK);
  }

  // loop se ponavlja stalno
  TFT.drawRect(50, 50, 50, 50, ILI9341_BLUE); 
  // parametri za drawRect: x, y, širina, dužina, boja
  // boje možete koristiti formata ILI9341_BLACK, ILI9341_RED, itd.

  TFT.drawPixel(150, 150, ILI9341_WHITE);
}
