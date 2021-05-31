
            
            
// Cambia marcos de botones ...........................................................
            
            void cambia_marcos(byte cm)
            {
            
                if( cm == 1) 
                  tft.drawRoundRect(1,291,90,28,7,TFT_YELLOW);  else   tft.drawRoundRect(1,291,90,28,7,TFT_BLACK);
                
                if( cm == 2) 
                  tft.drawRoundRect(97,291,90,28,7,TFT_YELLOW);  else  tft.drawRoundRect(97,291,90,28,7,TFT_BLACK);
                
                if( cm == 3)
                   tft.drawRoundRect(194,291,90,28,7,TFT_YELLOW); else  tft.drawRoundRect(194,291,90,28,7,TFT_BLACK);
                
                if( cm == 4) 
                   tft.drawRoundRect(291,291,90,28,7,TFT_YELLOW);  else   tft.drawRoundRect(291,291,90,28,7,TFT_BLACK);
                
                if( cm == 5) 
                   tft.drawRoundRect(388,291,90,28,7,TFT_BLACK); else   tft.drawRoundRect(388,291,90,28,7,TFT_BLUE);   
            }
            
            
            
            
            
            
// Dibuja Texto fijo ...........................................................
            
            void parametros_fijos()
            { 
              
              tft.setFreeFont(FF49);
              tft.setCursor(105,86);
              tft.print(".");
              tft.setCursor(225,86);
              tft.print(".");  
              
              tft.setFreeFont(FF54);
            
              //VFO-A
              tft.fillRect(5,11,60,20,TFT_BLACK);
              tft.setTextColor(TFT_GREEN, TFT_BLACK);
              tft.setCursor(7,27);
              tft.print("vfoA");
             
            
              //VFO-B
              tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
              tft.setCursor(5,225);
              tft.print("vfoB"); 
               
            
// Dibuja Marcos ...........................................................
            
              tft.drawRoundRect(0,0,480,189,10,TFT_DARKCYAN);
              tft.drawRoundRect(0,195,190,89,10,TFT_DARKCYAN);
            
              tft.drawRoundRect(197,195,283,89,10,TFT_DARKCYAN);
              //tft.drawRoundRect(360,197,100,89,10,TFT_DARKCYAN);
            
            
// Dibuja Botones ...........................................................
            
              tft.fillRoundRect(0,290,92,30,7,TFT_DARKCYAN);
              tft.setTextColor(TFT_BLACK, TFT_DARKCYAN); //Pinta la sombra
              tft.setCursor(27,313);
              tft.print("VFO");
              tft.setTextColor(TFT_WHITE, TFT_DARKCYAN);
              tft.setCursor(26,312);
              tft.print("VFO");
            
              
              tft.fillRoundRect(96,290,92,30,7,TFT_DARKCYAN);
              tft.setTextColor(TFT_BLACK, TFT_DARKCYAN); //Pinta la sombra  
              tft.setCursor(105,313);
              tft.print("eEPROM");
              tft.setTextColor(TFT_WHITE, TFT_DARKCYAN); //Pinta la sombra  
              tft.setCursor(104,312);
              tft.print("eEPROM");
              
              tft.fillRoundRect(193,290,92,30,7,TFT_DARKCYAN);
              tft.setTextColor(TFT_BLACK, TFT_DARKCYAN); //Pinta la sombra  
              tft.setCursor(196,313);
              tft.print("swRadio");
              tft.setTextColor(TFT_WHITE, TFT_DARKCYAN); //Pinta la sombra  
              tft.setCursor(196,312);
              tft.print("swRadio");
            
              
              
              tft.fillRoundRect(290,290,92,30,7,TFT_DARKCYAN);
              tft.setTextColor(TFT_BLACK, TFT_DARKCYAN); //Pinta la sombra  
              tft.setCursor(298,313);
              tft.print("Smeter");
              tft.setTextColor(TFT_WHITE, TFT_DARKCYAN); //Pinta la sombra  
              tft.setCursor(298,312);
              tft.print("Smeter");
            
              
              tft.fillRoundRect(387,290,92,30,7,TFT_DARKCYAN);
              tft.setTextColor(TFT_BLACK, TFT_DARKCYAN); //Pinta la sombra  
              tft.setCursor(398,313);
              tft.print("");
              tft.setTextColor(TFT_WHITE, TFT_DARKCYAN); //Pinta la sombra  
              tft.setCursor(398,312);
              tft.print("");
            
            
            
// Dibuja Smeter ........................................................... 
            
              dx = 30; dy = 120;
            
              tft.drawLine(dx, dy ,dx , dy + 15, TFT_WHITE);
              tft.drawLine(dx, dy-1, dx+20, dy-1,TFT_WHITE);
              tft.drawLine(dx, dy , dx+163, dy, TFT_WHITE);
              tft.drawLine(dx+163, dy , dx+276, dy, TFT_RED);
              tft.drawLine(dx, dy+15 , dx+276, dy+15, TFT_WHITE);
            
              for (int i = dx+19; i<(dx+276); i=i+18)
              {
                 if(i<(dx+160))
                 {
                    tft.drawLine(i, dy-4 ,i , dy, TFT_WHITE);
                 }
                 else
                 {
                    tft.drawLine(i, dy-4 ,i , dy, TFT_RED); 
                 }
              }
            
              tft.setTextColor(TFT_WHITE, TFT_BLACK);
              tft.setTextFont(2);
              tft.setCursor(dx-13,dy-15);
              tft.print("S");
              tft.setCursor(dx+16,dy-18);
              tft.print("1");
              tft.setCursor(dx+52,dy-18);
              tft.print("3");
              tft.setCursor(dx+88,dy-18);
              tft.print("5");
              tft.setCursor(dx+124154,dy-18);
              tft.print("7");
              tft.setCursor(dx+160,dy-18);
              tft.print("9");
              
              tft.setTextColor(TFT_RED, TFT_BLACK);
              tft.setCursor(dx+186,dy-18);
              tft.print("+20");
              tft.setCursor(dx+222,dy-18);
              tft.print("+40");
              tft.setCursor(dx+258,dy-18);
              tft.print("+60");
            
            }
