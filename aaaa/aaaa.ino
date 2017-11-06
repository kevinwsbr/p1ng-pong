#include "LedControl.h"

int pont2t=0;
int flag = 1, tab = 0;
int row = 5, column = 5;
int dX = 1, dY = 1;
int yp;
int pont1=0,pont2=0;
const int pinoPot = A5;
int leituraA5; 
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
}

void drawPad()
{
  
  yp = analogRead(pinoPot); 
  yp=map(yp,100,1023,0,5);
  Serial.print(leituraA5); 
  Serial.println(yp); 
  Serial.println(pont2);
  Serial.println(pont2t);
  lc.setLed(0,7,yp,true);
  lc.setLed(0,7,yp+1,true);
  lc.setLed(0,7,yp+2,true);
}

void drawScore()
{
  int i;
  int row;
  for (row = 0; row < 8; row++)
  {
    lc.setLed(2,7,row,true);
  }


  for(i=0;i<pont2t;i++)
  {
     if (pont2t>5) break;
    lc.setLed(2,pont2t,1,true);
  }
  for (int col = 7, row = 0; col >= 0; col--)
  {
    //col % 2 == 0 ? row = 3 : row = 4;
    //lc.setLed(2,col,row,true);
    lc.setLed(2,col,3,true);
    lc.setLed(2,col,4,true);
  }
}

void drawBall()
{
  if(flag == 1){
    if(dX == 1)
    {
      row--;
    }
    else
    {
      row++;
    }
  
    if(dY == 1)
    {
      column++;
    }
    else
    {
      column--;
    }
  
    //if (row == 0 && dX == 1 ) {dX = -1;}
    if (row == -1 && dX == 1 ) {tab = 1; row = 7; flag *= -1;}
    if (row == 8 && dX == -1 ) {pont2++; newgame();}
    if (row == 7 && dX == -1 && (column==yp || column==yp+1 || column==yp+2)) {dX=1;} 
    if (column == 0 && dY == -1 ) {dY = 1;}
    if (column == 7 && dY == 1 ) {dY = -1;}
  }else if(flag == -1)
  {
    if(dX == 1)
    {
      row--;
    }
    else
    {
      row++;
    }
  
    if(dY == 1)
    {
      column++;
    }
    else
    {
      column--;
    }
  
    if (row == 0 && dX == 1 ) {dX = -1;}
    if (row == 8 && dX == -1 ) {tab = 0; row = 0; flag *= -1;}
    if (column == 0 && dY == -1 ) {dY = 1;}
    if (column == 7 && dY == 1 ) {dY = -1;}
  }
  delay(100);
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.setLed(tab, row, column, true);
}

void newgame()
{
  pont2t++;
  lc.clearDisplay(0);
  row = 0;
  column= 5;
  pont2=0;
  lc.clearDisplay(1);
}

void loop()
{
  drawBall();
  drawScore();
  drawPad();  
  /*for (int l = 0; l < 3; l++)
  {
    for (int col = 7; col >= 0; col--)
    {
      for (int row = 0; row < 8; row++)
      {
        lc.setLed(l,col,row,true);
        delay(25);
      }
    }
  }

  for (int l = 0; l < 3; l++)
  {
    for (int col = 7; col >= 0; col--)
    {
      for (int row = 0; row < 8; row++)
      {
        lc.setLed(l,col,row,false);
        delay(25);
      }
    }
  }*/
}
