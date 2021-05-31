  
              
/*************************************************************************************              
*               
*                                Dibuja el filtro DSP  
*  
**************************************************************************************/
 
    int fil_x = 360;
    int fil_y = 60;
    bool chg_dsp = 0; 

                
    void dibuja_dsp()
    {

       if( radio.getMode() == 2 )  // modo 2 = CW
       {
          
          dsp_bpf = radio.get_mem_param(147) & B00001100 ; //Mem = 0x93-->147 dsp_BPF
          if( dsp_bpf_bk != dsp_bpf)
          {          
             dsp_bpf_bk = dsp_bpf;
             dsp_bpf = dsp_bpf >> 2;
             
             tft.fillRect(340,40,139,80,TFT_BLACK);                           // Borra el espacio de dibujo     
             tft.fillRoundRect(408 - ((dsp_bpf * 10) + 5) , fil_y ,           // Dibuja el rectangulo del filtro
                              ((dsp_bpf * 10) + 5) * 2 , 36 , 5 , 0x7321);   
             tft.drawRoundRect((408 - ((dsp_bpf * 10) + 5)) + 1 , fil_y +1 ,  // Dibuja el marco del filtro
                              (((dsp_bpf * 10) + 5) * 2) -2 , 35 , 5 , TFT_BLACK);    

             tft.drawRoundRect(408 - ((dsp_bpf * 10) + 5) , fil_y ,           // Dibuja el rectangulo del filtro
                              ((dsp_bpf * 10) + 5) * 2 , 36 , 5 , TFT_YELLOW);                              

                              
             tft.fillRect( 350, fil_y + 33, 116, 3,TFT_DARKGREY);            // Dibuja la linea gris inferior

             tft.setTextFont(2);                                             // Ahora escribe los textos
             tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
             tft.setCursor(365,fil_y - 18);
             tft.print(" CW BP Filter");
          
             tft.setTextColor(TFT_YELLOW, TFT_BLACK);
             tft.setCursor(370,fil_y + 38);
             
             tft.print( "--[ ");
             switch (dsp_bpf)
             {
                case B0: tft.print("60 hz");
                break;
                case B01: tft.print("120 hz");
                break;
                case B10: tft.print("240 hz");
                break;
             }
             tft.print(" ]--");                         
          }   
       }
                
       else      // Si no es modo CW dibuja el filtro normal
                
       { 
          dsp_hpf = radio.get_mem_param(148) & B00011111 ; //Mem = 0x94-->148 dsp_HPF
          dsp_lpf = radio.get_mem_param(149) & B00001111 ; //Mem = 0x95-->149 dsp_LPF
          dsp_dbf = radio.get_mem_param(168) & B00001100 ; //Mem = 168 --> DBF on/off
              
          if( dsp_hpf_bk != dsp_hpf | dsp_lpf_bk != dsp_lpf | dsp_dbf_bk != dsp_dbf)            
          {                                    
                      
            
             dsp_hpf_bk = dsp_hpf;
             dsp_lpf_bk = dsp_lpf;
             dsp_dbf_bk = dsp_dbf;
                     
             switch (dsp_hpf)
             {
                case 0: hpf = 1000;
                break;
                case 1: hpf = 1160;      
                break; 
                case 12: hpf = 2940;
                break;
                case 13: hpf = 3100;
                break;
                case 14: hpf = 3260;
                break;
                case 15: hpf = 3420;
                break;
                case 16: hpf = 3580;
                break;
                case 17: hpf = 3740;
                break;
                case 18: hpf = 3900;
                break;
                case 19: hpf = 4060;
                break;
                case 20: hpf = 4230;
                break;
                case 21: hpf = 4390;
                break;
                case 22: hpf = 4550;
                break;
                case 23: hpf = 4710;
                break;
                case 24: hpf = 4870;
                break;
                case 25: hpf = 5030;
                break;
                case 26: hpf = 5190;
                break;
                case 27: hpf = 5390;
                break;
                case 28: hpf = 5520;
                break;
                case 29: hpf = 5680;
                break;
                case 30: hpf = 5840;
                break;
                case 31: hpf = 6000;
                break;                                                                                               
             }
              
              
                    switch (dsp_lpf)
                    {
                       case 0: lpf = 100;
                       break;
                       case 1: lpf = 160;
                       break;         
                       case 2: lpf = 220;
                       break;
                       case 3: lpf = 280;
                       break;
                       case 4: lpf = 340;
                       break;
                       case 5: lpf = 400;
                       break;         
                       case 6: lpf = 460;
                       break;
                       case 7: lpf = 520;
                       break;
                       case 8: lpf = 580;
                       break;
                       case 9: lpf = 640;
                       break;         
                       case 10: lpf = 700;
                       break;
                       case 11: lpf = 760;
                       break;         
                       case 12: lpf = 820;
                       break;
                       case 13: lpf = 880;
                       break;         
                       case 14: lpf = 940;
                       break;
                       case 15: lpf = 1000;
                       break;
                    }  
              
              
              
              
// Dibuja Filtro pasabanda ...........................................................

              
                  // ··· Dibuja lineas laterales
                  tft.fillRect(340,40,139,80,TFT_BLACK);                  // Borra el espacio de dibujo
                  tft.drawFastVLine(359,fil_y + 12,21,TFT_YELLOW);
                  tft.drawFastVLine(360,fil_y + 12,21,TFT_YELLOW);
                  tft.drawFastVLine(455,fil_y + 12,21,TFT_YELLOW);
                  tft.drawFastVLine(456,fil_y + 12,21,TFT_YELLOW);
                      
                  tft.setTextFont(2);
                  tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
                  tft.setCursor(340,fil_y - 18);
                  tft.print("100hz           6Khz");
              
                  if( dsp_dbf == 0 )   // ··· DSP OFF ················
                     { tft.drawRoundRect(360 , fil_y , 94 + 2, 36 , 5 , 0x7321);
                       tft.setTextColor(TFT_YELLOW, TFT_BLACK);
                       tft.setCursor(360,fil_y + 38);  //-18        
                       tft.print("   DSP OFF    ");
                     }
                  else                 // ··· DSP ON
                     { tft.fillRoundRect(360 + (dsp_lpf * 2) , fil_y , (32 + (dsp_hpf * 2)) - (dsp_lpf * 2) + 2, 36 , 5 , 0x7321);
                     /*  tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
                       tft.setCursor(350,fil_y - 18);
                       tft.print(lpf);
                       tft.print(" <-----> ");
                       tft.print(hpf); */
                       tft.setTextColor(TFT_YELLOW, TFT_BLACK);
                       tft.setCursor(360,fil_y + 38);  //-18       
                       tft.print("--[ ");
                       tft.print(hpf - lpf);
                       tft.print(" hz ]--");
                     }
                            
                  tft.fillRect( 350, fil_y + 33, 116, 3,TFT_DARKGREY);
                 }
                }         
              }
