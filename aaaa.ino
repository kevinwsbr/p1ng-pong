#include "LedControl.h"

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

void drawPad()
{
  lc.setLed(0,0,yp,false);
  lc.setLed(0,0,yp+1,false);
  lc.setLed(0,0,yp-1,false);
  yp = analogRead(pinoPot); 
  yp = map(yp,0,256,1,6);
  if( yp > 6 ) yp = 6;
  if( yp < 1 ) yp = 1;
  Serial.print(leituraA5);
  lc.setLed(0,0,yp,true);
  lc.setLed(0,0,yp+1,true);
  lc.setLed(0,0,yp-1,true);
}

void drawPad2()
{
  for( int i = -1 ; i < 2 ; ++i )
    lc.setLed(1,7,yp2-i,true);
}


void restart()
{
  if(pont2t >= 5)
    {
      for(int i = 0; i<3;i++)
      {
        for (int l = 0; l < 3; l++)
      {
        for (int col = 7; col >= 0; col--)
        {
          for (int row = 0; row < 8; row++)
          {
            lc.setLed(0,col,row,true);
            lc.setLed(1,col,row,true);
          }
        }
      }
  delay(25);
    for (int l = 0; l < 3; l++)
    {
      for (int col = 7; col >= 0; col--)
      {
        for (int row = 0; row < 8; row++)
        {
          lc.setLed(0,col,row,false);
          lc.setLed(1,col,row,false);
        }
      }
    }
      }
      delay(2000);
      newgame();
    }
    else if(pont1t >= 5)
  {
      for(int i = 0; i<3;i++)
      {
        for (int l = 0; l < 3; l++)
      {
        for (int col = 7; col >= 0; col--)
        {
          for (int row = 0; row < 8; row++)
          {
            lc.setLed(0,col,row,true);
            lc.setLed(1,col,row,true);
          }
        }
      }
  delay(25);
    for (int l = 0; l < 3; l++)
    {
      for (int col = 7; col >= 0; col--)
      {
        for (int row = 0; row < 8; row++)
        {
          lc.setLed(0,col,row,false);
          lc.setLed(1,col,row,false);
        }
      }
    }
      }
      delay(2000);
      newgame2();
  }
}


void drawScore()
{
  int i;
  int j;
  int k;
  int l;
  int row;
  for (row = 0; row < 8; row++)
  {
    lc.setLed(2,7,row,true);
  }
  
  for(j=0;j<pont1t;j++)
  {
     if (pont1t>5) break;
    lc.setLed(2,pont1t,6,true);
  }

  for(i=0;i<pont2t;i++)
  {
     if (pont2t>5)
     {
      /*for(k=0;k<8;k++)
      {
        for(j=0;j<8;j++)
        {
          lc.setLed(0,k,j,true);
          lc.setLed(1,k,j,true);
          lc.setLed(2,k,j,true); 
        }
      }
      break;  
     }  */
     break;
     }
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
  lc.setLed( row/8 , row%8, column, false);
  row += dX;
  column += dY;
  // Column variável responsável pela movimento horizontal
  if( column == 7 || column == 0 ){
    dY *= -1;
  } 

  if( row == 1 and dX == -1 ){
    if( abs(column+dY-yp) <= 1 ) dX *= -1;
  }
  if( row == 14 and dX == 1 ){
    if( abs(column+dY-yp2) <= 1 ) dX *= -1;
  }
  if( row == -1 ) newgame();
  if( row == 16 ) newgame2();  
  lc.setLed( row/8 , row%8, column, true);
}

void movePad2(int v)
{
  rdom = random(v);
  lc.setLed(1,7,yp2+1,false);
  lc.setLed(1,7,yp2-1,false);
  if( rdom <= 1 ){
    if( yp2 > column+dY and yp2 > 1 ) 
      yp2--;
    if( yp2 < column+dY and yp2 < 6 )
      yp2++;  
  }
}

void newgame()
{
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  pont2t++;
  row = 1;
  column= yp;
  dX*=-1;
}

void newgame2()
{
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  pont1t++;
  row = 14;
  column= yp2;
  dX*=-1;
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
