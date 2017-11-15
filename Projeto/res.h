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