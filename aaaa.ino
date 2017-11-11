#include "LedControl.h"

int v=random(2,7);
int pont2t=0;
int pont1t=0;
int flag = 1, tab = 0;
int row = 5, column = 5;
int dX = 1, dY = 1;
int yp;
int yp2=2;
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
  
  yp = analogRead(pinoPot); 
  yp=map(yp,0,512,0,5);
  Serial.print(leituraA5);
  //Serial.println(yp); 
  //Serial.println(pont2);
  //Serial.println(pont2t);
  lc.setLed(0,7,yp,true);
  lc.setLed(0,7,yp+1,true);
  lc.setLed(0,7,yp+2,true);
}

void drawPad2()
{

  lc.setLed(1,0,yp2,true);
  lc.setLed(1,0,yp2+1,true);
  lc.setLed(1,0,yp2+2,true);
}

void clearMatrix(int pad){
  for (int col = 7; col >= 0; col--)
    {
      for (int row = 0; row < 8; row++)
      {
        if(col == 7)
        {
          if(row != pad || row != pad+1 || row != pad+2)
          {
           lc.setLed(0,col,row,false);  
          }
        }else
        {
          lc.setLed(0,col,row,false);
        }
        
      }
    }
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
    //if (row == 8 && dX == -1 ) {pont2++; newgame();}
    if (row == 7 && dX == -1 ) {dX = 1;}
    /*if (row == 6 && dX == -1)
    {
      if (dY==1)
      {
        if((column==yp || column==yp+1 || column==yp+2)) {dX=1;} 
      }
      else
      {
         if((column==yp || column==yp+1 || column==yp+2)) {dX=1;} 
      }
    }*/
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
  
    //if (row == 0 && dX == 1 ) {dX = -1;}
    if (row == 8 && dX == -1 ) {tab = 0; row = 0; flag *= -1;}
    if (row == -1 && dX == 1) {pont1++; newgame2();}
    if (row == 1 && dX == 1)
    {
      ra(v); 
       if (dY==1)
      {
        if((column==yp2 || column==yp2+1 || column==yp2+2)) { dX=-1;} 
      }
      else
      {
         if((column==yp2 || column==yp2+1 || column==yp2+2)) { dX=-1;} 
      }
    }
  //  if (row == 0 && dX == 1 && column == yp2+3 && dY==1) {dX=-1;} 
    if (column == 0 && dY == -1 ) {dY = 1;}
    if (column == 7 && dY == 1 ) {dY = -1;}
  }
  delay(100);
  lc.clearDisplay(0);
  //clearMatrix(yp);
  lc.clearDisplay(1);
  lc.setLed(tab, row, column, true);
}

void movePad2(int column)
{/*
  if(column<4 && yp2>1 && dY==-1)
  {
    yp2--;
  }
  if (column>=4 && yp2+2<6 && dX==1)
  {
    yp2++;
  }
  delay(0);*/
  if( dX == 1)
  {
    if(column>0)
    {
      yp2 = column-1;
    }
    
  }
  //delay(200);
}

void ra(int v)
{
  rdom=random(v);
  if(rdom==0 || rdom == 1 && (row!=1 || row!=0 || row!=2))
  {
    movePad2(column-1);
  }
  //delay(150);
}

void newgame()
{
  pont2t++;
  lc.clearDisplay(0);
  row = 0;
  column= 5;
  dX*=-1;
  //delay(500);
  pont2=0;
  lc.clearDisplay(1);
}

void newgame2()
{
  pont1t++;
  lc.clearDisplay(0);
  row = 5;
  column= 0;
  dX*=-1;
  //delay(500);
  pont1=0;
  lc.clearDisplay(1);
}

void loop()
{
  drawBall();
  drawScore();
  //drawPad();
  v=random(2,6);
  Serial.println(v); 
  ra(v);
  drawPad2();
  //restart();
  
  
  
  
  
////////////////////RANDOM


/*long randNumber;

void setup(){
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
}

void loop() {
  // print a random number from 0 to 299
  randNumber = random(300);
  Serial.println(randNumber);

  // print a random number from 10 to 19
  randNumber = random(10, 20);
  Serial.println(randNumber);

  delay(50);
}
  
  
  
  //movePad2();    
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
