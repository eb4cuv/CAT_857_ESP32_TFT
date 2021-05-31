/*************************************************************************
 * 
 *  Comienza el Setup del Smeter Analogico                               *
 *  
 *************************************************************************/


void drawLineaa(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint32_t color)
{

  int32_t ww;



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

  // Split into steep and not steep for FastH/V separation
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
          //tft.drawPixel(aguja_actual_x[numpix_drawlin], aguja_actual_y[numpix_drawlin], matriz[numpix_drawlin]);
          
          matriz_0_x[numpix_drawlin] = y0; matriz_0_y[numpix_drawlin] = xs;
          //matriz[numpix_drawlin] = tft.readPixel(y0, xs); //matriz_1[numpix_drawlin] = tft.readPixel(y0 + 1, xs);

          //tft.drawPixel(y0,xs,TFT_RED); //aguja_smeter.pushSprite(y0,xs);
          //  tft.drawPixel(y0+1,xs,TFT_BLACK);
         
          numpix_drawlin++;      
        }
              
        else 
        {         
          for (int i = 1; i <= dlen; i++)  
          {
        
            //tft.drawPixel(aguja_actual_x[numpix_drawlin], aguja_actual_y[numpix_drawlin], matriz[numpix_drawlin]);

            
            matriz_0_x[numpix_drawlin] = y0; matriz_0_y[numpix_drawlin] = xs;
            //matriz[numpix_drawlin] = tft.readPixel(y0, xs); //matriz_1[numpix_drawlin] = tft.readPixel(y0 + 1, xs);

                     
            // tft.drawPixel(y0,xs,TFT_BLACK); //aguja_smeter.pushSprite(y0,xs);
             //  tft.drawPixel(y0+1,xs,TFT_RED);
    
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
              
          //tft.drawPixel(aguja_actual_x[numpix_drawlin], aguja_actual_y[numpix_drawlin], matriz[numpix_drawlin]);
          
          matriz_0_x[numpix_drawlin] = y0; matriz_0_y[numpix_drawlin] = xs;
          //matriz[numpix_drawlin] = tft.readPixel(y0, xs); //matriz_1[numpix_drawlin] = tft.readPixel(y0 + 1, xs);

          //tft.drawPixel(y0,xs,TFT_GREEN); //aguja_smeter.pushSprite(y0,xs);
          // tft.drawPixel(y0+1,xs,TFT_BLUE);
   
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
     //     tft.drawPixel(matriz_0_x[numpix_drawlin], matriz_0_y[numpix_drawlin], matriz_0[numpix_drawlin]);
          
          matriz_0_x[numpix_drawlin] = xs; matriz_0_y[numpix_drawlin] = y0; 
     //     matriz_0[numpix_drawlin] = tft.readPixel(xs, y0); //matriz_1[numpix_drawlin] = tft.readPixel(xs + 1, y0);
          
     //     tft.drawPixel(xs,y0,TFT_WHITE); //aguja_smeter.pushSprite(y0,xs); 
          // tft.drawPixel(xs+1,y0,TFT_WHITE);
    
          numpix_drawlin++;      
        }
        
        else 
        
        {
          for (int i = 1; i <= dlen; i++)  //drawFastHLineaa(xs, y0, dlen, TFT_WHITE);
          {                      
      //      tft.drawPixel(matriz_0_x[numpix_drawlin], matriz_0_y[numpix_drawlin], matriz_0[numpix_drawlin]);
           
            
            matriz_0_x[numpix_drawlin] = xs; matriz_0_y[numpix_drawlin] = y0; 
      //      matriz_0[numpix_drawlin] = tft.readPixel(xs, y0); //matriz_1[numpix_drawlin] = tft.readPixel(xs + 1, y0);

      //      tft.drawPixel(xs,y0,TFT_WHITE); //aguja_smeter.pushSprite(y0,xs); 
            // tft.drawPixel(xs,y0+1,TFT_LIGTHBLUE);
  
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
      //      tft.drawPixel(matriz_0_x[numpix_drawlin], matriz_0_y[numpix_drawlin], matriz_0[numpix_drawlin]);
            
            matriz_0_x[numpix_drawlin] = xs; matriz_0_y[numpix_drawlin] = y0; 
        //    matriz_0[numpix_drawlin] = tft.readPixel(xs, y0); //matriz_1[numpix_drawlin] = tft.readPixel(xs + 1, y0); 

      //      tft.drawPixel(xs,y0,TFT_WHITE); //aguja_smeter.pushSprite(y0,xs); 
            // tft.drawPixel(xs,y0+1,TFT_BLACK);
     
            numpix_drawlin++;                       
            xs++;                          
        }                     
    }
  } 
}


/*******************************************************************************
 * 
 *      Con s_meter = 0 el radio es de 270
 *      con s_meter = 7.7 el radio es de 240   0,256666667
 *      Rango 0-18
 *
 *********************************************************************************/





void pantalla_4()
{
  
   fex_smeter.drawJpgFile(SPIFFS, "/smeter_original.jpg", 0, 0);
   tft.fillRect(0,235,480,52, TFT_BLACK);


//   tft.drawFastHLine(0,60,200,TFT_BLACK);
//   tft.drawFastVLine(50,60,200,TFT_BLACK);
//   tft.drawFastVLine(200,60,178,TFT_BLACK);
           
    int x = 244, y = 300, r = 240;

    smeter_signal_ana = ( (analogRead(36)) / 370);  //7.85 es el valor central correspondiente al S-9

    s_meter_bak = smeter_signal_ana;

    smeter_signal_ana = (7.85 / 9) * smeter_signal_ana;

    if( smeter_signal_ana > 7.85) {r = r + (smeter_signal_ana / 30);} else {r = r - (smeter_signal_ana / 30);}
       

    //float start_angle = 3.93 + (s_meter / 10) , end_angle = 3.94 + (s_meter / 10);
    float i = 3.93 + (smeter_signal_ana / 10);  //start_angle; 


    numpix_drawlin = 0;  
    drawLineaa(x,y, x + cos(i) * r , y + sin(i) * r, TFT_BLACK); //0x01C0); //0x0380);
    

               
               
                 


/*
    for (int pol = 1; pol <= 1000000; pol++)  //----------------------------------------------------------------------------------------
    {

//__________Lee la señal
      
        smeter_signal_ana = 0;
        for (int mm = 1;  mm < 10; mm++)   
            { smeter_signal_ana = (analogRead(36)) + smeter_signal_ana;}
        smeter_signal_ana = (int(smeter_signal_ana / 10)) / 370.0;
            
        smeter_signal_ana = (7.85 / 9) * smeter_signal_ana;
        //if( s_meter > 7.85) {r = r + (s_meter / 30);} else {r = r - (s_meter / 30);}


        float pok;
        if (s_meter_bak > smeter_signal_ana) 
             pok = s_meter_bak - smeter_signal_ana;                
        else pok = smeter_signal_ana - s_meter_bak;       
        if(pok > 0.1)                              //para evitar el parpadeo, si la señal es la misma que la anterior, ni se borra ni se pinta
        {
                    
           
//___________Borra la aguja anterior

           Serial.println(numpix_drawlin);
           for (int vv = 0; vv <= numpix_drawlin; vv++)    //numpix_drawlin = longitud en pixel de la aguja              
           {                              
              tft.drawPixel(matriz_x[vv], matriz_y[vv], matriz[vv]); 
              tft.drawPixel( (matriz_x[vv]) + 1, matriz_y[vv], matriz_1[vv]);
              tft.drawPixel( (matriz_x[vv]) + 2, matriz_y[vv], matriz_2[vv]);
            //  tft.drawPixel( (matriz_x[vv]) + 3, matriz_y[vv], matriz_3[vv]);            
           }
               
//__________Dibuja la nueva linea

           numpix_drawlin = 0;  
           float ivv = 3.93 + (smeter_signal_ana / 10);  //start_angle;
           drawLineaa(x,y, x + cos(ivv) * r , y + sin(ivv) * r, TFT_BLACK); //0x01C0); //0x0380);

           s_meter_bak = smeter_signal_ana;
 
         }

    }


*/
 



   float smooth = 2;
   float senal_leida = 1;
   //float senal_leida_bak = 3;

   while ( touch_y < 290 ) //while (smooth != 100)
   {
      tft.getTouch(&touch_x, &touch_y);
     
      while (senal_leida < smooth)
      {


           smooth = smooth - 0.15;


//___________Borra la aguja anterior

/*           for (int vv = 0; vv <= numpix_drawlin - 65 ; vv++)                  
           {                              
              tft.drawPixel(aguja_actual_x[vv], aguja_actual_y[vv], matriz[vv]); 
             // tft.drawPixel( (aguja_actual_x[vv]) + 1, aguja_actual_y[vv], matriz_1[vv]);           
           }
*/     

 /*          if( numpix_drawlin < numpix_drawlin_bak)
           {
               for (int vv = numpix_drawlin; vv <= numpix_drawlin_bak; vv++)
               {
                  tft.drawPixel(aguja_actual_x[vv], aguja_actual_y[vv], matriz[vv]);
               }                  
           }  
           numpix_drawlin_bak = numpix_drawlin;
 */      
             

//__________Dibuja la nueva linea

           numpix_drawlin = 0;  
           float ivv = 3.93 + (smooth / 10);  //start_angle;
           drawLineaa(x,y, x + cos(ivv) * r , y + sin(ivv) * r, TFT_BLACK); //0x01C0); //0x0380);  //Coge Coordenadas nueva linea

                    
           for (int vv = 0; vv <= 120; vv++) 
           {
             tft.drawPixel(matriz_1_x[vv], matriz_1_y[vv],  matriz_1[vv]);  //Borra la linea con los datos guardados
                        
             matriz_1_x[vv] = matriz_0_x[vv];                               //Intercambia coordenadas de los puntos
             matriz_1_y[vv] = matriz_0_y[vv];
             
             matriz_1[vv] =  tft.readPixel(matriz_1_x[vv], matriz_1_y[vv]);  //Guarda el color del pixel actual

             tft.drawPixel(matriz_1_x[vv], matriz_1_y[vv], TFT_BLACK);       //Dibuja la linea
           }

//__________Lee señal
               
           senal_leida = 0;
           for (int mm = 1;  mm < 10; mm++)   
               { senal_leida = (analogRead(36)) + senal_leida;}               
           senal_leida = (int(senal_leida / 10)) / 471.0;                   
           if(senal_leida < 0.1) senal_leida = 0.1;
           //if( s_meter > 7.85) {r = r + (s_meter / 30);} else {r = r - (s_meter / 30);}               
           
       
        
 /*       
        s_meter_bak = senal_leida;
        float ooo;
        while (senal_leida == s_meter_bak)                              
        {
    
           senal_leida = 0;
           for (int mm = 1;  mm < 10; mm++)   
               { senal_leida = (analogRead(36)) + senal_leida;}
          
          // senal_leida = (int(senal_leida / 10)) / 370.0;           
           //senal_leida = (7.85 / 9) * senal_leida;
           senal_leida = (int(senal_leida / 10)) / 471;  
           

          if(senal_leida > s_meter_bak) ooo = senal_leida - s_meter_bak;
                       else (ooo = s_meter_bak - senal_leida);
          if( ooo < 0.1 ) senal_leida = s_meter_bak;           
           //if( s_meter > 7.85) {r = r + (s_meter / 30);} else {r = r - (s_meter / 30);}               
         }
   */  
   }
      
         smooth = senal_leida;
         senal_leida = 0;

   }
     
   
 pantalla = 0;    
}    


  

       
