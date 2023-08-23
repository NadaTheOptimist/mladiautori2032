#include <Adafruit_ILI9341.h>
#include <Adafruit_GFX.h>

Adafruit_ILI9341 TFT = Adafruit_ILI9341(5, 21);

//screen size
const int W = 320;
const int H = 240;

//variables
double x = 0;
double y = 0;
double sizeX = 10;
double sizeY = 10;
double velocityX = 0;
double velocityY = 0;
double mass = 1;
double prevX = 0;
double prevY = 0;
double airFriction = 0.05;

double inputStrenght = 5;
double timeLastPhysicsUpdate = 0;

void updatePhysics() {
  double timeCurrent = millis();
  double dt = timeCurrent - timeLastPhysicsUpdate;
  timeLastPhysicsUpdate = timeCurrent;
  dt = dt / 1000; //to seconds

  prevX = x;
  prevY = y;

  x += velocityX * dt;
  y += velocityY * dt;

  velocityX *= 1 - airFriction;
  velocityY *= 1 - airFriction;

  return;
}

void updateInputs() {
  //up&down
  int inputX = analogRead(34);
  int inputY = analogRead(35);
  
  if (inputX) {
    if (inputX > 4000) { //up
      velocityX -= inputStrenght;
    }
    else { //down
      velocityX += inputStrenght;
    }
  }
  /*else { //not pressed
    
  }*/

  //left&right
  if (inputY) {
    if (inputY > 4000) { //left
      velocityY -= inputStrenght;
    }
    else { //right
      velocityY += inputStrenght;
    }
  }
  /*else { //not pressed
    
  }*/
}

void setup() {
  TFT.begin();
  TFT.setRotation(3);
  TFT.fillScreen(ILI9341_BLACK);

  pinMode(2, OUTPUT);
}

void loop() {
  updateInputs();
  updatePhysics();
  
  TFT.fillRect(prevX, prevY, sizeX, sizeY, ILI9341_BLACK);
  TFT.fillRect(x, y, sizeX, sizeY, ILI9341_WHITE);
  delay(10);
}
