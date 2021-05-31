/*************************************************************************
 * 
 *  Comienza el Setup del Smeter Analogico                               
 *  
 *  
 *  (1) - Correcion de la señal leida. Variable: senal_corr 
 *        Para que marque lo mismo que la emisora: 1.6
 *         
 *  
 *************************************************************************/


void drawLineaa(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint32_t color)
{

  bool steep = abs(y1 - y0) > abs(x1 - x0);
  
  if (steep) {
    swap_coord(x0, y0);
    swap_coord(x1, y1);
  }

  if (x0 > x1) {
    swap_coord(x0, x1);
    swap_coord(y0, y1);    
  }

  int32_t dx = x1 - x0, dy = abs(y1 - y0);

  int32_t err = dx >> 1, ystep = -1, xs = x0, dlen = 0;

  if (y0 < y1) ystep = 1;

  // Divide entre paso y no paso para una rapida separacion H/V
  if (steep) {
    for (; x0 <= x1; x0++) 
    { 
      dlen++;
      err -= dy;
      if (err < 0) 
      {
        err += dx;
        
        if (dlen == 1)
        {               
          matriz_0_x[numpix_drawlin] = y0; matriz_0_y[numpix_drawlin] = xs;
          numpix_drawlin++;      
        }
              
        else 
        {         
          for (int i = 1; i <= dlen; i++)  
          {
            matriz_0_x[numpix_drawlin] = y0; matriz_0_y[numpix_drawlin] = xs;
            numpix_drawlin++;             
            xs++;
          }
        }        
        dlen = 0;
        y0 += ystep; xs = x0 + 1;
      }
    }
    if (dlen)
    {   
        for (int i = 1; i <= dlen; i++)  //drawFastVLineaa(y0, xs, dlen, color);
        {         
          matriz_0_x[numpix_drawlin] = y0; matriz_0_y[numpix_drawlin] = xs;
          numpix_drawlin++;       
          xs++;   
        }               
    }
} 
  
else        // Horizontal ---------------------------------

  {   
    for (; x0 <= x1; x0++) 
    {
      dlen++;
      err -= dy;
      if (err < 0) 
      {
        err += dx;
      
        if (dlen == 1) 
        {             
          matriz_0_x[numpix_drawlin] = xs; matriz_0_y[numpix_drawlin] = y0; 
          numpix_drawlin++;      
        }
        
        else 
        
        {
          for (int i = 1; i <= dlen; i++)  //drawFastHLineaa(xs, y0, dlen, TFT_WHITE);
          {                      
            matriz_0_x[numpix_drawlin] = xs; matriz_0_y[numpix_drawlin] = y0; 
            numpix_drawlin++;                      
            xs++;            
          }                           
        }
        dlen = 0;
        y0 += ystep; xs = x0 + 1;
      }
    }
    if (dlen)
    {
        for (int i = 1; i <= dlen; i++) //drawFastHLineaa(xs, y0, dlen, color);
        {                                               
            matriz_0_x[numpix_drawlin] = xs; matriz_0_y[numpix_drawlin] = y0; 
            numpix_drawlin++;                       
            xs++;                          
        }                     
    }
  } 
}


/*******************************************************************************
 * 
 *      Inicio Pantalla 4 - Smeter analogico
 *
 *********************************************************************************/

void pantalla_4()
{
  

    cambia_marcos(4); //Cambia el marco del boton
   
   
 //  fex_smeter.drawJpgFile(SPIFFS, "/smeter_original.jpg", 0, 0);
 //  fex_smeter.drawJpgFile(SPIFFS, "/smeter_yaesu.jpg", 0, 0);
     fex_smeter.drawJpgFile(SPIFFS, "/smeter_mod_esp32.jpg", 0, 0);

 
   tft.fillRect(0,235,480,52, TFT_BLACK);
   
   int x = 240, y = 300;
   float senal_corr = 1.28;      //  (1) - Ver comentario al inicio.
   float cada_pixel = 10.83;    //  4095 / 378 pixels de la pantalla = 10.83333
   float smooth = 25;
   float senal_leida = 1;


   while ( touch_y < 290 ) 
   {
      tft.getTouch(&touch_x, &touch_y);
     
      while (senal_leida < smooth)
      {        
           smooth = smooth - 50;                      
           if(smooth < 10) smooth = 30.2;   //Asegura que la aguja no se vaya por debajo de S-0
            
//__________Dibuja la nueva linea
                     
           numpix_drawlin = 0;            
           drawLineaa(x,y,  47 + int((smooth/cada_pixel) / senal_corr) , escala_aguja[int((smooth/cada_pixel) / senal_corr )], TFT_BLACK);
 
           for (int vv = 0; vv <= numpix_drawlin - 65; vv++) 
           {                    
                 tft.drawPixel(matriz_1_x[vv], matriz_1_y[vv],  matriz_l[vv]);          //Borra el punto de la linea anterior
                 tft.drawPixel(matriz_1_x[vv+1], matriz_1_y[vv+1],  matriz_l[vv+1]);    //Borra
                 
                 tft.drawPixel(matriz_1_x[vv+1], matriz_1_y[vv],  matriz_l1[vv]);       //Borra
                 tft.drawPixel(matriz_1_x[vv+2], matriz_1_y[vv+2],  matriz_l1[vv+2]);   //Borra 

                 
                 matriz_l[vv] =  tft.readPixel(matriz_0_x[vv], matriz_0_y[vv]);  //Lee el nuevo valor
                 matriz_l1[vv] =  tft.readPixel(matriz_0_x[vv+1], matriz_0_y[vv]);
                                 
                 tft.drawPixel(matriz_0_x[vv], matriz_0_y[vv], TFT_BLACK);       //Dibuja la linea
                 tft.drawPixel(matriz_0_x[vv+1], matriz_0_y[vv], TFT_BLACK);

                 swap_coord( matriz_1_x[vv] , matriz_0_x[vv] );
                 swap_coord( matriz_1_y[vv] , matriz_0_y[vv] );           
           }


           senal_leida = 0;             
           for (int op = 1; op <= 100 ; op++)  senal_leida = senal_leida + analogRead(36);
           senal_leida = senal_leida/ 100;
                          
       }   
      
       smooth = senal_leida;
       senal_leida = 0;
   
   }
   

/*           String s_meter_freq, strf;
           
          
           vfoA_freq = radio.getFreqMode();
           if( ACT_VFO == 0)  // vfoA = 0,  vfoB = 1 
               s_meter_freq = String(vfoA_freq); else s_meter_freq = String(vfoB_freq);
               
           switch ( s_meter_freq.length()) 
           {
              case  5: strf = "    " + s_meter_freq.substring(0,3) + "." + s_meter_freq.substring(3);
              break;             
              case  6: strf = "  " + s_meter_freq.substring(0,1) + "." + s_meter_freq.substring(1,4) + "." + s_meter_freq.substring(4);
              break;
              case  7: strf = " " + s_meter_freq.substring(0,2) + "." + s_meter_freq.substring(2,5) + "." + s_meter_freq.substring(5);             
              break;
              case  8: strf = s_meter_freq.substring(0,3) + "." + s_meter_freq.substring(3,6) + "." + s_meter_freq.substring(6);    
              break;
            }
    
            
            sprite_vfob.fillRect(210,0,20,60,TFT_BLACK);   //Borra los restos que quedan de la cadena anterior en el sprite
            sprite_vfob.drawString(strf, 0, 0, GFXFF);
            sprite_vfob.pushSprite(150,245);    
  */                      

 
   
 pantalla = 0;    
}    


  

       
