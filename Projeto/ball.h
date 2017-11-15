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