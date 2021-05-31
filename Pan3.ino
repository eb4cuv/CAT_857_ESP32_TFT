

int pos_aguja;


void pantalla_3()
{
   timerAlarmDisable(ti_0);

   tft.fillRect(0,0,480,290,TFT_BLACK);
   dial_oc1.pushSprite(0,65);


//Cambia marco de boton

    cambia_marcos(3);   


//________________ Pinta el logo ________________________________________

  tft.setFreeFont(FF59);
  tft.setTextColor(TFT_LIGHTGREY);
  //tft.fillRoundRect(20,8,200,52,20, 0x9000);
  //tft.drawRoundRect(20,8,200,52,20, 0xDE4B);
  
  tft.setCursor(30,43);
  tft.print("ViddyX Radio");

  tft.drawRect(0,41,20,2, 0xDE4B); 
  tft.drawRect(220,41,100,2, 0xDE4B);
  tft.drawRect(403,41,80,2, 0xDE4B);


//old_qrg = 0; //················ Fuerza a pintar la aguja la primera vez que se llama a la rutina


//while( (touch_x>=1) && (touch_x<=196) && (touch_x>= 296) && (touch_y < 290) )
 


while ( touch_y < 290 ) 
{
   tft.getTouch(&touch_x, &touch_y);

   vfoA_freq = radio.getFreqMode();
   
   if( vfoA_freq != old_qrg_vfoA )             // Si la frecuencia no ha cambiado
        {                                 // no se hace nada         
         old_qrg_vfoA = vfoA_freq;
         int old_pos_aguja = pos_aguja;
                      
         switch( vfoA_freq )
         {
            case 53000 ... 171000 :
              {
                 pos_aguja = round((vfoA_freq - 53000) * 0.004067797) - 11;
                 break;
              }
            case 230000 ... 506000 :
              {
                 pos_aguja = round((vfoA_freq - 230000) * 0.00173913) - 11;
                 break;
              }             
            case 590000 ... 620000 :  
              {
                 pos_aguja = round((vfoA_freq - 590000) * 0.016) - 11;
                 break;
              }              
            case 719000 ... 760000 :  
              {
                 pos_aguja = round((vfoA_freq - 719000) * 0.011707317 -11); //0.0192) - 11;
                 break;
              }  
            case 920000 ... 990000 :  
              {
                 pos_aguja = round((vfoA_freq - 920000) * 0.006857143) -11;
                 break;
              }
            case 1160000 ... 1210000 :  
              {
                 pos_aguja = round((vfoA_freq - 1160000) * 0.0096) -11;
                 break;
              }                                 
         }

//______________ Para que en los movimientos rapidos de la aguja no deje rastro,
//______________ se pinta el fondo del dial anterior sin la aguja.

         if( (pos_aguja > old_pos_aguja + 10) | (pos_aguja < old_pos_aguja - 10))
         {
           for (int po= old_pos_aguja; po< old_pos_aguja + 23; po++)
           {
               for (int bc=0; bc< 237; bc++) 
               {
                   bn = dial_oc1.readPixel(po,bc);
                   aguja_dial.drawPixel((po - old_pos_aguja) ,bc,bn);
               }   
           }
           aguja_dial.pushSprite(old_pos_aguja,65);
         }

         
//_______________ Coge datos del sprite principal en memoria y copialos al sprite de la aguja

           for (int po= pos_aguja; po< pos_aguja + 23; po++)
           {
               for (int bc=0; bc< 237; bc++) 
               {
                   bn = dial_oc1.readPixel(po,bc);
                   aguja_dial.drawPixel((po - pos_aguja) ,bc,bn);
               }   
           }

//_______________ Dibuja la aguja
            int po=11;
               //   aguja_dial.drawFastVLine(po-3,211,8,TFT_RED);
               //aguja_dial.drawFastVLine(po-2,190,13,TFT_RED);
               
               // aguja_dial.drawFastVLine(po-2,10,210,TFT_RED);
               aguja_dial.drawFastVLine(po-1,10,210,TFT_RED);
               aguja_dial.drawFastVLine(po,10,210,TFT_RED);
               aguja_dial.drawFastVLine(po+1,10,210,TFT_RED);
               //aguja_dial.drawFastVLine(po+2,10,221,TFT_DARKGREY);
              
               //aguja_dial.drawFastVLine(po+2,190,13,TFT_RED);
               //   aguja_dial.drawFastVLine(po+3,211,8,TFT_RED);

               aguja_dial.pushSprite(pos_aguja,65);
                       
       // ···································································
      
            //tft.setCursor(0,0);
            //tft.print(pos_aguja+10);
        }

//_________________ Ojo Magico ______________________________________________

     float s_ojo = ( (analogRead(36)) / 370);   

     ojo_magico.fillCircle(31,31,28, TFT_GREEN );
                      
     int x = 31, y = 31, r = 27;
          
     float start_angle = 0.4 + (s_ojo / 10), end_angle = 2.8 - (s_ojo / 10);           
     for (float i = start_angle; i < end_angle; i = i + 0.01)  // 0.05)
     {
         ojo_magico.drawLine(x,y, x + cos(i) * r , y + sin(i) * r, 0x01C0); //0x0380);
     }

     start_angle = 3.6 + (s_ojo / 10) , end_angle = 5.8 - (s_ojo / 10);           
     for (float i = start_angle; i < end_angle; i = i + 0.01) // 0.05)
     {
        ojo_magico.drawLine(x,y, x + cos(i) * r , y + sin(i) * r, 0x01C0); //0x0380);
     }
            
     ojo_magico.drawCircle(x,y,31, 0xDE4B);
     ojo_magico.drawCircle(x,y,30, 0xDE4B);
     ojo_magico.drawCircle(x,y,29, TFT_BLACK);// 0xDE4B);            
     ojo_magico.drawCircle(x,y,28, TFT_BLACK);
     ojo_magico.drawCircle(x,y,27, TFT_BLACK);
     ojo_magico.drawCircle(x,y,26, TFT_BLACK);
     ojo_magico.fillCircle(x,y,15, TFT_BLACK);

     ojo_magico.pushSprite(330,0);             
}



timerAlarmEnable(ti_0);

pantalla = 0;

}
