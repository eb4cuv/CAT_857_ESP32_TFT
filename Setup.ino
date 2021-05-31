
//****************************************************************************************
//*                                           SETUP                                      *
//****************************************************************************************


void setup()
{



/*************************************************************************
 *  Pinta la Presentacion                               
 *************************************************************************/
  

  tft.init();
  radio.begin(38400);
  //Serial.begin(115200);
  Serial.begin(921600);

  delay(500);
  tft.fillScreen(TFT_WHITE);
  tft.setRotation(3);

  SPIFFS.begin();
  fex_presentacion.drawJpgFile(SPIFFS, "/presentacion.jpg", 0, 0);


 

/*************************************************************************
 *  Sprites
 *************************************************************************/  
  
  sprite_0.setColorDepth(8);       
  sprite_0.createSprite(34, 52);   
  sprite_0.fillSprite(TFT_BLACK);
  sprite_0.setFreeFont(FF49);
  sprite_0.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
  
  sprite_1.setColorDepth(8);        
  sprite_1.createSprite(34, 52);   
  sprite_1.fillSprite(TFT_BLACK);
  sprite_1.setFreeFont(FF49);
  sprite_1.setTextColor(TFT_LIGHTGREY, TFT_BLACK);

  sprite_2.setColorDepth(8);       
  sprite_2.createSprite(34, 52);   
  sprite_2.fillSprite(TFT_BLACK);
  sprite_2.setFreeFont(FF49);
  sprite_2.setTextColor(TFT_LIGHTGREY, TFT_BLACK);

  sprite_3.setColorDepth(8);       
  sprite_3.createSprite(34, 52);   
  sprite_3.fillSprite(TFT_BLACK);
  sprite_3.setFreeFont(FF49);
  sprite_3.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
  
  sprite_4.setColorDepth(8);       
  sprite_4.createSprite(34, 52);   
  sprite_4.fillSprite(TFT_BLACK);
  sprite_4.setFreeFont(FF49);
  sprite_4.setTextColor(TFT_LIGHTGREY, TFT_BLACK);

  sprite_5.setColorDepth(8);       
  sprite_5.createSprite(34, 52);   
  sprite_5.fillSprite(TFT_BLACK);
  sprite_5.setFreeFont(FF49);
  sprite_5.setTextColor(TFT_LIGHTGREY, TFT_BLACK);

  sprite_6.setColorDepth(8);       
  sprite_6.createSprite(34, 52);   
  sprite_6.fillSprite(TFT_BLACK);
  sprite_6.setFreeFont(FF49);
  sprite_6.setTextColor(TFT_LIGHTGREY, TFT_BLACK);      

  sprite_7.setColorDepth(8);       
  sprite_7.createSprite(34, 52);   
  sprite_7.fillSprite(TFT_BLACK);
  sprite_7.setFreeFont(FF49);
  sprite_7.setTextColor(TFT_LIGHTGREY, TFT_BLACK);

  sprite_vfob.setColorDepth(1);      // Set depth to 1 to halve RAM use
  sprite_vfob.createSprite(170, 38); //bitmap:  W=170 --- H=38
  sprite_vfob.fillSprite(TFT_BLACK);
  sprite_vfob.setFreeFont(FF53);
  sprite_vfob.setTextColor(TFT_DARKGREY, TFT_BLACK);

 
/*************************************************************************
 *  Comienza el Setup del receptor de OC                                 *  
 *************************************************************************/

//______ Define Sprites __________________________________________________

  aguja_dial.setColorDepth(8);
  aguja_dial.createSprite(23, 217);   
  aguja_dial.fillSprite(TFT_BLACK);

  ojo_magico.setColorDepth(8);
  ojo_magico.createSprite(64, 64);
  ojo_magico.fillSprite(TFT_BLACK);
  
  dial_oc1.setColorDepth(8);   
  dial_oc1.createSprite(480, 217);   
  dial_oc1.fillSprite(TFT_BLACK);
  dial_oc1.setTextColor(0xDE4B, TFT_BLACK);
 
  
//____________ Dibuja OM ________________________________________________

  dial_oc1.setTextFont(4);
  dial_oc1.setCursor(8,15);
  dial_oc1.print("585");
  dial_oc1.setCursor(90,15);
  dial_oc1.print("800");
  dial_oc1.setCursor(155,15);
  dial_oc1.print("954");
  dial_oc1.setCursor(250,15);
  dial_oc1.print("1200");
  dial_oc1.setCursor(400,15);
  dial_oc1.print("1600");

  dial_oc1.drawFastHLine(0,46,480,0xDE4B);
  dial_oc1.fillRect(0,50,480,4,0xDE4B);
  for (int bc=0; bc< 48; bc++) { dial_oc1.drawFastVLine(bc*10 ,42 ,4 ,0xDE4B); }


//___________ Dial bandas tropicales ************  2300 ... 5060 ________
dial_oc1.fillRect(0,90,480,2,0xDE4B);
dial_oc1.setTextFont(2);
dial_oc1.setCursor(35,70);
dial_oc1.print("120m");
dial_oc1.setCursor(124,70);
dial_oc1.print("90m");
dial_oc1.setCursor(298,70);
dial_oc1.print("75m");
dial_oc1.setCursor(393,70);
dial_oc1.print("60m");

dial_oc1.setTextFont(2);
dial_oc1.setCursor(210,67);
dial_oc1.print("BERLIN");

dial_oc1.setTextFont(4);
dial_oc1.setCursor(77,64);
dial_oc1.print("2.8");
dial_oc1.setCursor(339,64);
dial_oc1.print("4.2");

dial_oc1.fillRect(5,79,27,4,0x9000); //0x0664);
dial_oc1.fillRect(155,79,34,4,0x9000); //0x0664);
dial_oc1.fillRect(277,79,18,4,0x9000); //0x0664);
dial_oc1.fillRect(425,79,40,4,0x9000);  //0x0664);

//___________ Dial 49m ___________________________________________________
dial_oc1.fillRect(0,130,480,2,0xDE4B);

dial_oc1.setTextFont(2);
dial_oc1.setCursor(60,110);
dial_oc1.print("LONDON");
dial_oc1.setCursor(220,110);
dial_oc1.print("BUCAREST");
dial_oc1.fillRect(123,119,48,4,0x0664); //0xDE4B);
dial_oc1.setCursor(178,112);
dial_oc1.print("50m");

dial_oc1.fillRect(345,119,38,4,0x0664);
dial_oc1.setCursor(388,112);
dial_oc1.print("49m");

dial_oc1.setTextFont(4);
dial_oc1.setCursor(10,104);
dial_oc1.print("5.9");
//dial_oc1.setCursor(150,74);
//dial_oc1.print("6.0");
dial_oc1.setCursor(300,104);
dial_oc1.print("6.1");
dial_oc1.setCursor(430,104);
dial_oc1.print("6.2");


//___________ Dial 41m ___________________________________________________
dial_oc1.fillRect(0,170,480,2,0xDE4B);

dial_oc1.setTextFont(4);
dial_oc1.setCursor(25,144);
dial_oc1.print("7.23");
dial_oc1.setCursor(170,144);
dial_oc1.print("7.3");
dial_oc1.setCursor(370,144);
dial_oc1.print("7.5");

dial_oc1.setTextFont(2);
dial_oc1.fillRect(223,158,18,4,0x0664);
dial_oc1.setCursor(245,151);
dial_oc1.print("41m");
dial_oc1.setCursor(100,147);
dial_oc1.print("PARIS");
dial_oc1.setCursor(290,147);
dial_oc1.print("ISTAMBUL");
dial_oc1.setCursor(430,147);
dial_oc1.print("BERN");

//___________ Dial 31m __________________________________________________

dial_oc1.fillRect(0,210,480,2,0xDE4B);

dial_oc1.setTextFont(4);
dial_oc1.setCursor(10,184);
dial_oc1.print("9.2");
dial_oc1.setCursor(250,184);
dial_oc1.print("9.6");
dial_oc1.setCursor(430,184);
dial_oc1.print("9.9");

dial_oc1.setTextFont(2);
dial_oc1.setCursor(70,190);
dial_oc1.print("32m");
dial_oc1.fillRect(100,197,40,4,0x9000); //0x0664);
dial_oc1.fillRect(300,197,58,4,0x9000); //0x0664);
dial_oc1.setCursor(368,190);
dial_oc1.print("31m");

dial_oc1.setCursor(160,189);
dial_oc1.print("CINCINNATI");



/*************************************************************************
 *  Interrupciones                                 *  
 *************************************************************************/
 
//································· Int. por software ·········································
  ti_0 = timerBegin(0, 80, true);                // Timer 0, Prescaler a 80 y True significa cuenta hacia arriba
  timerAttachInterrupt(ti_0, &onTimer_0, true);  //1 tick take 1/(80MHZ/80) = 1us
  timerAlarmWrite(ti_0, 200000, true);
  timerAlarmEnable(ti_0);

//································· Int. por hardware ········································· 
//  pinMode(22, INPUT_PULLUP);
//  attachInterrupt(digitalPinToInterrupt(22), irq_touch, RISING);



/*************************************************************************
 *  Touchscreen                                  
 *************************************************************************/
//······························· Calibracion del touchScreen ······································
/*  uint16_t calData[5]; //You need 6 values, right?
 
  tft.calibrateTouch( calData, TFT_MAGENTA, TFT_BLACK, 20); // Runs a test that has you touch the corners of the screen
  tft.setTouch(calData);
   
  for (uint8_t i = 0; i < 5; i++)
  {
    Serial.print(calData[i]);
    if (i < 4) Serial.print(", ");
  }
*/

  uint16_t calData[5] = {279,3630,274,3526,1};
  tft.setTouch(calData);
  



/*************************************************************************
 *  Incializa ADC, VFO...                             
 *************************************************************************/

  analogSetCycles(60);
  analogSetPinAttenuation(36, ADC_11db);


  // ····· Asegura que el vfo activo al inicio sea el "A"

  if( radio.getActiveVFO() != 0) // 
  { 
    radio.switchVFO();
    ACT_VFO = 0;  
  }

  pantalla = 1;
  
  delay(1000);
  tft.fillScreen(TFT_BLACK);


  

/********************************
 *  Herramientas para el diseño
 ********************************   

/*
   dacWrite(DAC1, 100);    
   fft();  
*/

#ifdef diseno_lee_eprom_on   //  Lee la Eeprom completa
  delay(1000);
  lee_mem();
#endif  



  

}
