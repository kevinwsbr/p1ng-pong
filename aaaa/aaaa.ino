#include "LedControl.h"

int pont2t=0;
int flag = 1, tab = 0;
int row = 5, column = 5;
int dX = 1, dY = 1;
int yp;
int pont1=0,pont2=0;
const int pinoPot = A5; //PINO ANALÓGICO UTILIZADO PELO POTENCIÔMETRO
int leituraA5; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NA PORTA ANALÓGICA
LedControl lc=LedControl(12,11,10,3);
//LedControl lc=LedControl(11,13,10,3);

void setup()
{
   pinMode(pinoPot, INPUT); //DEFINE A PORTA COMO ENTRADA
  Serial.begin(9600); //INICIALIZA A SERIAL
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
  
  yp = analogRead(pinoPot); //LÊ O VALOR NA PORTA ANALÓGICA (VALOR LIDO EM BITS QUE VAI DE 0 A 1023 BITS)
  yp=map(yp,100,1023,0,5);
  Serial.print(leituraA5); //IMPRIME NA SERIAL O VALOR LIDO NA PORTA ANALÓGICA
  Serial.println(yp); //IMPRIME O TEXTO NA SERIAL
  Serial.println(pont2);
  Serial.println(pont2t);
  //delay(100); //INTERVALO DE 100 MILISSEGUNDOS
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
    lc.setLed(2,pont2t,1,true);
    if(i==5) 
    {

      break;
    }
    
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
    if (row == 0 && dX == 1 ) {tab = 1; row = 7; flag *= -1;}
    if (row == 8 && dX == -1 ) {pont2++; newgame();}
    if (row == 6 && dX == -1 && ( column==yp || column==yp+1 || column==yp+2 )) {dX=1;} 
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
    if (row == 7 && dX == -1 ) {tab = 0; row = 0; flag *= -1;}
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
  //lc.setLed(tab, row, column, true);
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
