
//****************************************************************************************
//*                                            LOOP                                      *
//****************************************************************************************

void loop()
{

// _______________________________ TOUCH _________________________________

    
   if( tft.getTouch(&touch_x, &touch_y) > 0 )
   {

//··· Si se pulsa el boton de VF0 ···    
      if ((touch_x>=1) && (touch_x<=96) && (touch_y>=290)  && (pantalla != 1)) 
         {
            pantalla = 1;
         }

//··· Si se pulsa el boton de eEPROM ···      
      if ((touch_x>=100) && (touch_x<=196) && (touch_y>=290) && (pantalla != 2)) //(touch_y<=320)) 
         {
            pantalla = 2;
         }

//··· Si se pulsa el boton de swRadio ···
      if ((touch_x>=200) && (touch_x<=296) && (touch_y>=290) && (pantalla != 3)) //(touch_y<=320)) 
         {
            pantalla = 3;
         }

//··· Si se pulsa el boton Smeter ···
      if ((touch_x>=300) && (touch_x<=396) && (touch_y>=290) && (pantalla != 4)) //(touch_y<=320)) 
         {
            pantalla = 4; 
         }        

//··· Si se pulsa el boton 5 ···
      if ((touch_x>=400) && (touch_x<=396) && (touch_y>=290) && (touch_y<=320)) 
         {
            pantalla = 5;
         } 
   
      }

        

/*   if ((touch_x>=380) && (touch_x<=420) && (touch_y>=120) && (touch_y<=145))  //IPO
   {
     touch_x = 0;
     
     if( bitRead(att_ipo,5) == true)            // mem ipo 328
     {
        tft.setTextColor(TFT_DARKGREY1, TFT_BLACK);
        tft.setCursor(383,140);
        tft.print("IPO");

        bitWrite(att_ipo,5,0);

       byte cmd[5] = {0x01,0x48,0x00,0x00,0xbc};  //eeprom write
       
       for (byte i=0; i<5; i++) {
          Serial2.write(cmd[i]);
       }
       //delay(10);
       Serial2.write(att_ipo); 
        
     }     
   }   
*/ 

   
//____________________ Pantalla 1 - VFO's ____________________________________
   
if(pantalla == 1) 
{
  touch_y = 0;
  old_qrg_vfoA = 0;
  init_params();
  pantalla_1();
}  

//_____________________Pantalla 2 - Parametros de la Eeprom __________________

if(pantalla == 2)
{ 
   touch_y = 0;
   old_qrg_vfoA = 0;
   pantalla_2();
}

//____________________ Pantalla 3 - Radio de Onda corta ______________________

if(pantalla == 3)
{ 
   touch_y = 0;
   old_qrg_vfoA = 0;
   pantalla_3();
}

//____________________ Pantalla 4 - S-meter  ______________________

if(pantalla == 4)
{ 
   touch_y = 0;
   old_qrg_vfoA = 0;
   pantalla_4();
}







}
