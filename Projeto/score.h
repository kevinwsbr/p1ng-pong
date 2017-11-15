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