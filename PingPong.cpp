#include "LedControl.h"
#include "Player.h"
#include "Ball.h"

#define BALL_SPEED 100

const int paddlePin = A5;

Ball ball(5, 5, 1, 1);
Player playerOne(0,3);
Player playerTwo(0,3);

int v=random(1,5);
bool hasWinner = false;

int pinRead, rdom;
LedControl matrix=LedControl(12,11,10,3);

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(paddlePin, INPUT); 
  Serial.begin(9600); 
  for (int i = 0; i < 3; ++i)
  {
    matrix.shutdown(i,false);
    matrix.setIntensity(i,7); 
    matrix.clearDisplay(i); 
  }
  randomSeed(analogRead(0));
}

void playImperialMarch()
{
  
}

void drawRightPad()
{
  matrix.setLed(0,0,playerOne.getPosition(),false);
  matrix.setLed(0,0,playerOne.getPosition()+1,false);
  matrix.setLed(0,0,playerOne.getPosition()-1,false);
  playerOne.setPosition(analogRead(paddlePin)); 
  playerOne.setPosition(map(playerOne.getPosition(),0,256,6,1));
  if( playerOne.getPosition() > 6 ) playerOne.setPosition(6);
  if( playerOne.getPosition() < 1 ) playerOne.setPosition(1);
  Serial.print(pinRead);
  matrix.setLed(0,0,playerOne.getPosition(),true);
  matrix.setLed(0,0,playerOne.getPosition()+1,true);
  matrix.setLed(0,0,playerOne.getPosition()-1,true);
}

void drawLeftPad()
{
  for( int i = -1 ; i < 2 ; ++i )
    matrix.setLed(1,7,playerTwo.getPosition()-i,true);
}

void drawScore()
{
  for (int i = 0; i < 8; ++i)
  {
    matrix.setLed(2, 0, i, true);
  }

  for (int col = 7; col >= 0; col--)
  {
    matrix.setLed(2,col,3,true);
    matrix.setLed(2,col,4,true);
  }

}

void updateScore()
{
  int i, j;
  
    for(j=0;j<playerOne.getScore();j++)
    {
       if (playerOne.getScore()>=5) hasWinner = true;
      matrix.setLed(2,playerOne.getScore()+1,6,true);
    }
  for(i=0;i<playerTwo.getScore();i++)
    {
       if (playerTwo.getScore()>=5)
       {
       hasWinner = true;
       delay(200);
       }
      matrix.setLed(2,playerTwo.getScore()+1,1,true);
    }

}

void drawBall()
{
  matrix.setLed( ball.getX()/8 , ball.getX()%8, ball.getY(), false);
  ball.setX(ball.getX()+ball.getHeadingX());
  ball.setY(ball.getY()+ball.getHeadingY());

  if( ball.getY() == 7 || ball.getY() == 0 ){
    
    ball.invertHeadingY();
   //digitalWrite(8, LOW);
  } 

  if( ball.getX() == 1 and ball.getHeadingX() == -1 ){
    if( abs(ball.getY()+ball.getHeadingY()-playerOne.getPosition()) <= 1 ){
      //digitalWrite(8, HIGH);
      ball.invertHeadingX();
      //digitalWrite(8, LOW);
    }
  }
  if( ball.getX() == 14 and ball.getHeadingX() == 1 ){
    if( abs(ball.getY()+ball.getHeadingY()-playerTwo.getPosition()) <= 1 ){
      //digitalWrite(8, HIGH);
      ball.invertHeadingX();
      //digitalWrite(8, LOW);
    }
  }
  if( ball.getX() == -1 ) roundOver(1);
  if( ball.getX() == 16 ) roundOver(2);  
  matrix.setLed( ball.getX()/8 , ball.getX()%8, ball.getY(), true);
}

void moveLeftPad(int v)
{
  rdom = random(v);
  matrix.setLed(1,7,playerTwo.getPosition()+1,false);
  matrix.setLed(1,7,playerTwo.getPosition()-1,false);
  if( rdom <= 1 ){
    if( playerTwo.getPosition() > ball.getY()+ball.getHeadingY() and playerTwo.getPosition() > 1 ) 
      playerTwo.setPosition(playerTwo.getPosition()-1);
    if( playerTwo.getPosition() < ball.getY()+ball.getHeadingY() and playerTwo.getPosition() < 6 )
      playerTwo.setPosition(playerTwo.getPosition()+1);
  }
}

void winAnimation()
{
  for(int k = 0; k < 3; k++){
   // digitalWrite(8, HIGH);
    delay(100);
  for(int j = 0; j < 8; j++){
     for(int i = 0; i < 8; i++)
     {
      if(j%2 == 0){
        if(i%2 == 0){
          matrix.setLed(0, i, j, true);
          matrix.setLed(1, i, j, true);
          //matrix.setLed(2, i, j, true); 
        }
        else
        {
          matrix.setLed(0, i, j+1, true); 
          matrix.setLed(1, i, j+1, true);
          //matrix.setLed(2, i, j+1, true);
        }
      }
     }
  }

  for(int j = 0; j < 8; j++){
     for(int i = 0; i < 8; i++)
     {
      if(j%2 == 0){
        if(i%2 == 0){
          matrix.setLed(0, i, j, false);
          matrix.setLed(1, i, j, false);
          //matrix.setLed(2, i, j, false); 
        }
        else
        {
          matrix.setLed(0, i, j+1, false); 
          matrix.setLed(1, i, j+1, false);
        //  matrix.setLed(2, i, j+1, false);
        }
      }
     }
  }

  for(int j = 0; j < 8; j++){
     for(int i = 0; i < 8; i++)
     {
      if(j%2 == 0){
        if(i%2 == 0){
          matrix.setLed(0, i, j+1, true);
          matrix.setLed(1, i, j+1, true);
          //matrix.setLed(2, i, j+1, true); 
        }
        else
        {
          matrix.setLed(0, i, j, true); 
          matrix.setLed(1, i, j, true);
         // matrix.setLed(2, i, j, true);
        }
      }
     }
  }

  for(int i = 0; i < 8; i++){
     for(int j = 0; j < 8; j++)
     {
      if(j%2 == 0){
        if(i%2 == 0){
          matrix.setLed(0, i, j+1, false);
          matrix.setLed(1, i, j+1, false);
          //matrix.setLed(2, i, j+1, false); 
        }
        else
        {
          matrix.setLed(0, i, j, false); 
          matrix.setLed(1, i, j, false);
          //matrix.setLed(2, i, j, false);
        }
      }
     }
  }
  digitalWrite(8, LOW);
  }
}

void roundOver(int player)
{
  matrix.clearDisplay(0);
  matrix.clearDisplay(1);
  winAnimation();
  switch(player)
  {
    case 1:
      playerOne.incrementScore();
      ball.setX(2);
      ball.setY(3);
      break;
    case 2:
      playerTwo.incrementScore();
      ball.setX(13);
      ball.setY(4);
      break;
  }
  ball.invertHeadingX();
  ball.invertHeadingY();
}

void newGame()
{
  drawScore();

  while(!hasWinner)
  {
    newTurn();
    //delay(700);
  }
  restartGame();
  
}

void newTurn()
{
  updateScore();
  drawRightPad();
  v=random(0,5);
  Serial.println(v); 
  drawLeftPad();
  drawBall();
  delay(BALL_SPEED);
  moveLeftPad(v);
}

void endAnimation()
{
  int k = 0, l = 0;
  for(int j = 7; j >= 0; j--)
  {
    for(int i = 0; i<24;i++){
    if(i<8){
      matrix.setLed(0, i, j, true);
      delay(5);
      }
      else if(i > 8 and i <= 16){
        matrix.setLed(1, k, j, true);
        delay(5);
        k++;
      }
      else{
        matrix.setLed(2, l, j, true);
        delay(5);
        l++;
      } 
    }
    k = 0, l = 0;
  }
  matrix.clearDisplay(0);
  matrix.clearDisplay(1);
  matrix.clearDisplay(2);
  delay(200);
  
}

void restartGame()
{
  delay(500);
  matrix.clearDisplay(0);
  matrix.clearDisplay(1);
  matrix.clearDisplay(2);
  endAnimation();
  hasWinner = false;
  playerOne.setScore(0);
  playerTwo.setScore(0);
  ball.setX(8);
  ball.setY(4);
  ball.setHeadingY(1);
  ball.setHeadingX(1);
  newGame(); 
}

void loop()
{
  newGame();
}