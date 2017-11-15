#include "LedControl.h"
#include "pad.h"
#include "pad2.h"
#include "res.h"
#include "score.h"
#include "ball.h"
#include "mpad2.h"
#include "ng1.h"
#include "ng2.h"

int v=random(1,5);
int pont2t=0;
int pont1t=0;
int flag = 1, tab = 0;
int row = 5, column = 5;
int dX = 1, dY = 1;
int yp;
int yp2=3;
int pont1=0,pont2=0;
const int pinoPot = A5;
int leituraA5;
int rdom;
int test;
LedControl lc=LedControl(12,11,10,3);
//LedControl lc=LedControl(11,13,10,3);

void setup()
{
  pinMode(pinoPot, INPUT); 
  Serial.begin(9600); 
  lc.shutdown(0,false);
  lc.shutdown(1,false);
  lc.shutdown(2,false);

  lc.setIntensity(0,7); 
  lc.setIntensity(1,7);
  lc.setIntensity(2,7);

  lc.clearDisplay(0); 
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  randomSeed(analogRead(0));
}



void loop()
{
  drawScore();
  drawPad();
  v=random(0,5);
  Serial.println(v); 
  drawPad2();
  drawBall();
  delay(300);
  movePad2(v);
}