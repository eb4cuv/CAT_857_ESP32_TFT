
// Dibuja Modo ...........................................................
              
              void dibuja_modo_x1()
              {
                    switch (modo_t)
                    {
                     case 0: tft.print("LSB");
                      break;
                     case 1: tft.print("USB");
                      break;
                     case 2: tft.print(" CW ");
                      break;
                     case 3: tft.print("CWR");
                      break;
                     case 4: tft.print(" AM");
                      break;
                     case 6: tft.print("WFM");
                      break;
                     case 8: tft.print(" FM");
                      break;
                     case 136: tft.print("FMN");
                      break; 
                     case 10: tft.print("DIG");
                      break;
                     case 12: tft.print("PKT");
                      break;  
                    } 
              }
              
              void dibuja_modo()
              {     
                    
                    tft.setFreeFont(FF54);
                    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
                         
                    if( ACT_VFO == 0)
                    {    
                      tft.fillRect(80,11,60,20,TFT_BLACK);
                      tft.setCursor(80,30);
                      modo_t = vfoA_modo;
                      dibuja_modo_x1();
              
                      tft.fillRect(110,208,60,20,TFT_BLACK);
                      tft.setCursor(120,225);
                      modo_t = vfoB_modo;
                      dibuja_modo_x1();   
                    }
                    else
                    {
                      tft.fillRect(80,11,60,20,TFT_BLACK);
                      tft.setCursor(80,30);
                      modo_t = vfoB_modo;
                      dibuja_modo_x1();
              
                      tft.fillRect(110,208,60,20,TFT_BLACK);
                      tft.setCursor(120,225);
                      modo_t = vfoA_modo;
                      dibuja_modo_x1(); 
                     
                    }                    
              } 
