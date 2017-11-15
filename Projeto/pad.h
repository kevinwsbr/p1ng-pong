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