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