


void pantalla_1()
{ 
  
        tft.setFreeFont(FF54);

// ···Cambia de botones ·································

         //Cambia_botones();
 /*        tft.setTextColor(TFT_BLACK, TFT_DARKCYAN);
         tft.setCursor(26,312);
         tft.print("VFO");
       

         tft.setTextColor(TFT_WHITE, TFT_DARKCYAN);
         tft.setCursor(104,312);
         tft.print("eEPROM");
  */


// ··· Borra pantalla ····································
         tft.fillRect(0,0,480,290,TFT_BLACK);


/***************************************************
         Dibuja la cuadricula para el diseño 
/***************************************************/
 #ifdef cuadricula_on
 
       for( int prud = 0;  prud < 24; prud++)
        {
          tft.drawFastVLine(prud * 20, 0, 320 ,TFT_DARKGREY);  
        }
      
        for( int prud = 0;  prud < 16; prud++)
        {
          tft.drawFastHLine(0 , prud * 20, 480 ,TFT_DARKGREY);   
        }
#endif        
  
       

// ··· Lee VFO's ········································· 

        if( ACT_VFO != 0) // Asegura que el VFO activo sea el A
        { 
           radio.switchVFO(); 
        }
    
         vfoA_freq = radio.getFreqMode();
         vfoA_modo = radio.getMode();
         radio.switchVFO();
         
         vfoB_freq = radio.getFreqMode();
         vfoB_modo = radio.getMode();
         radio.switchVFO();
                 
         dibuja_VFOs();
         dibuja_modo();
          
                       

 // ··· Dibuja el resto de parametros ····················
         init_params();
         parametros_fijos();
         cambia_marcos(1);



while( (touch_y < 290) )
{      
   
   tft.getTouch(&touch_x, &touch_y);

/*   Serial.println(touch_x);
   Serial.println(touch_y);
   Serial.println(tft.getTouch(&touch_x, &touch_y));
   Serial.println("----");
*/

    
   //····························· Frecuencia y modo ····································

          if( radio.getActiveVFO() != act_vfo_old )     // ¿ Hay cambio de VFO ?
          {
            
            old_qrg_vfoA = 0;                           // Fuerza a repintar los VFO si hay cambio de A a B
            old_qrg_vfoB = 0;
            ACT_VFO = radio.getActiveVFO();
            act_vfo_old = ACT_VFO;

            

            if(  ACT_VFO == 0)              // Cambia la etiqueta de los VFO's
            { 
                 tft.fillRect(5,11,60,20,TFT_BLACK);
                 tft.setTextColor(TFT_GREEN, TFT_BLACK);
                 tft.setCursor(7,27);
                 tft.print("vfoA");
                 
                 tft.fillRect(5,210,60,20,TFT_BLACK);
                 tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
                 tft.setCursor(5,225);
                 tft.print("vfoB");           
            }
            else
            {
                 tft.fillRect(5,11,60,20,TFT_BLACK);
                 tft.setTextColor(TFT_GREEN, TFT_BLACK);
                 tft.setCursor(7,27);
                 tft.print("vfoB");
                 
                 tft.fillRect(5,210,60,20,TFT_BLACK);
                 tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
                 tft.setCursor(5,225);
                 tft.print("vfoA");
            }


            timerAlarmDisable(ti_0);
            dibuja_modo();           
            timerAlarmEnable(ti_0); 
                      
          }
          

          if( ACT_VFO == 0)                     // ¿ El VFO activo es el A ?
          {          
             vfoA_freq = radio.getFreqMode();
              if( vfoA_freq != old_qrg_vfoA )   // Si la frecuencia no ha cambiado
              {                                 // no se hace nada
                   timerAlarmDisable(ti_0);
                   dibuja_VFOs();
                   timerAlarmEnable(ti_0);

                 //Serial.println("vfoa");
              }
          }
          else                                  // El VFO activo es el B
          {
             vfoB_freq = radio.getFreqMode();
              if( vfoB_freq != old_qrg_vfoB )   // Si la frecuencia no ha cambiado
              {                                 // no se hace nada
                   timerAlarmDisable(ti_0);  
                   dibuja_VFOs();
                   timerAlarmEnable(ti_0);

                 //Serial.println("vfob");
              }
          }
  
                                       
        
//····························· Lee y dibuja Smeter ··································
           adc_r = 0;
           for (byte mm = 1;  mm < 5; mm++)   
              { adc_r = (analogRead(36)) + adc_r;}
        
           adc_r = int(adc_r / 5);
           if(adc_r == 0) adc_r = 1;
        
           if( adc_r != adc_bk )
           {
              adc_r = adc_r / 17;
         
              for (sm_b = dx+2; sm_b <  adc_r + 32; sm_b = sm_b + 6)
              {
                if (sm_b < 190)
                   { tft.fillRect(sm_b, dy+2 , 5, 11, TFT_BLUE);}
                else
                   { tft.fillRect(sm_b, dy+2 , 5, 11, TFT_RED); }
              }
              tft.fillRect(sm_b, dy+2, (dx+280) - sm_b, 11, TFT_BLACK);
              adc_r = adc_bk;
           }

       
 
//==========================================================================================
//             Codigo que se ejecuta si hay una interrupcion por softwarwe 
//==========================================================================================

  if( soft_irq == true )
  {

    
           
//······················································································
//                                      BANDA
//······················································································

   bfa = radio.get_mem_param(108) & B00001111;
   switch (bfa)
   {
      case 0: band_freq_a = 160;
      break;
      case 1: band_freq_a = 80;
      break;
      case 3: band_freq_a = 40;
      break;
      case 4: band_freq_a = 30;
      break;
      case 5: band_freq_a = 20;
      break;
      case 6: band_freq_a = 17;
      break;
      case 7: band_freq_a = 15;
      break;
      case 8: band_freq_a = 12;
      break;
      case 9: band_freq_a = 10;
      break;
      case 10: band_freq_a = 6;
      break;
      case 11: band_freq_a = 5;  //FM
      break;
      case 12: band_freq_a = 4;  //AIR
      break;
      case 13: band_freq_a = 2;
      break;
      case 14: band_freq_a = 1;  //UHF
      break;    
      case 15: band_freq_a = 0;  //MW
      break;          
    }

//······················································································
//                                      MODO
//······················································································
 
    modo_xt = radio.getMode();
    if(( ACT_VFO == 0) && (modo_xt != vfoA_modo))
    { 
       vfoA_modo = modo_xt;
       dibuja_modo();
    }

    if(( ACT_VFO == 1) && (modo_xt != vfoB_modo))
    {
       vfoB_modo = modo_xt;
       dibuja_modo();
          
    }
    
           

//······················································································
//                                      AGC on/off
//······················································································
   agc_on_off = radio.get_mem_param(168);
   if( agc_on_off_bk != agc_on_off)
   { 
      agc_on_off_bk = agc_on_off;
      nb_agc_bk = 255;               //Con esto forzamos a repintar el AGC cuando pase de off a on
   }
 
// ··················································································
// ·                               NB, AGC, if-Shift (106)                          ·
// ··················································································
   nb_agc = radio.get_mem_param(106);     // 0x6A -- NB,AGC
   if( nb_agc != nb_agc_bk)
   {
      nb_agc_bk = nb_agc;
   
      tft.setFreeFont(FF54);  
      if( bitRead(nb_agc,5) == true)     // ..........Lee NB  
      { tft.setTextColor(TFT_GREEN, TFT_BLACK); }
          else { tft.setTextColor(TFT_DARKGREY1, TFT_BLACK); }
      tft.setCursor(345,170);
      tft.print("NB");    
          
      if( bitRead(nb_agc,4) == true)     // ..........Lee if_shift  
      { tft.setTextColor(TFT_GREEN, TFT_BLACK); }
          else { tft.setTextColor(TFT_DARKGREY1, TFT_BLACK); }
      tft.setCursor(270, 30);
      tft.print("IF-sh");
           
      tft.setTextColor(TFT_ORANGE, TFT_BLACK);
      tft.fillRect(236,151,70,25,TFT_BLACK);
      tft.setCursor(240,170);

      if( bitRead(agc_on_off, 5) == true) //Si el AGC esta a ON
      { 
         nb_agc = nb_agc & 3;
         switch (nb_agc)
         {
          case 0: tft.print("AGC-A");
           break;
          case 1: tft.print("AGC-F");
           break;
          case 2: tft.print("AGC-S");
           break;
         }  
       }
       else  // Si el AGC esta a off
       {
          tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
          //tft.drawRoundRect(239,149,67,28,5,TFT_RED);
          tft.print(" AGC "); 
       }
   }

// ··················································································
//                                Medidor (107)                                     ·
// ··················································································   
    met_st = radio.get_mem_param(107) & B00000011; 
    if( met_st != met_st_bk)
    {
       met_st_bk = met_st;

       tft.setTextFont(2);
       tft.setTextColor(TFT_WHITE, TFT_BLACK);
       tft.setCursor(dx-23,dy+17);
       switch (met_st)
       {
          case 0: tft.print("PWR ");
          break;
          case 1: tft.print("ALC ");
          break;
          case 2: tft.print("SWR ");
          break;
          case 3: tft.print("MOD ");
          break;
       }     
      
    }
    
// ··················································································
//                           Dibuja el filtro DSP
// ··················································································
    dibuja_dsp();
    

// ··················································································
//                              SPLIT (141) 
// ··················································································    
    spl_st = radio.get_mem_param(141);
    if( spl_st != spl_st_bk )
    {
      spl_st_bk = spl_st;
      
      if( bitRead(spl_st,7) == true)     // ..........Lee SPLIT
      { tft.fillRoundRect(150,150,80,27,5,TFT_RED); 
        tft.setTextColor(TFT_WHITE, TFT_RED);
      }
       else 
      { tft.fillRoundRect(150,150,80,27,5,TFT_BLACK);
        tft.setTextColor(TFT_DARKGREY1, TFT_BLACK); 
      }
      
      tft.setFreeFont(FF54);    
      tft.setCursor(160,170);
      tft.print("SPLIT");    
    }
    
    
// ··················································································    
//                         Filtros ATT, IPO (160)
// ··················································································    
    switch (band_freq_a)
    {     
      case 160: att_ipo = radio.get_mem_param(188);  
      break;
      case 80: att_ipo = radio.get_mem_param(216);
      break;      
      case 40: att_ipo = radio.get_mem_param(272);
      break;      
      case 30: att_ipo = radio.get_mem_param(300);
      break;      
      case 20: att_ipo = radio.get_mem_param(328);  // Mem = 328 - ATT, IPO  para 20m
      break;
      case 17: att_ipo = radio.get_mem_param(356);
      break;      
      case 15: att_ipo = radio.get_mem_param(384);
      break;      
      case 12: att_ipo = radio.get_mem_param(412);
      break;
      case 10: att_ipo = radio.get_mem_param(440);
      break;      
      case 6:  att_ipo = radio.get_mem_param(468);
      break;      
    }
    
    if( att_ipo_bk != att_ipo)
    {    
      att_ipo_bk = att_ipo;

      tft.setFreeFont(FF54);
      if( bitRead(att_ipo,4) == true) { tft.setTextColor(TFT_GREEN, TFT_BLACK); }
         else { tft.setTextColor(TFT_DARKGREY1, TFT_BLACK); };
      tft.setCursor(435,170);
      tft.print("ATT");
    
      if( bitRead(att_ipo,5) == true) { tft.setTextColor(TFT_GREEN, TFT_BLACK); }
         else { tft.setTextColor(TFT_DARKGREY1, TFT_BLACK); };
      tft.setCursor(383,170);
      tft.print("IPO");
    }  

    
    // ·························· Filtros DSP, DNR, DBF (168) ····························
    dsp_fil = radio.get_mem_param(168);   // bit 0 --> DNF
    if( dsp_fil_bk != dsp_fil)            // bit 1 --> DNR 
    {                                     // bit 2 --> DBF
       dsp_fil_bk = dsp_fil;              // bit 3 --> DBF
       
      tft.setFreeFont(FF54); 
      if( bitRead(dsp_fil,0) == true) { tft.setTextColor(TFT_GREEN, TFT_BLACK); }
         else { tft.setTextColor(TFT_DARKGREY1, TFT_BLACK); };
      tft.setCursor(345,30);
      tft.print("DNF");

      if( bitRead(dsp_fil,1) == true) { tft.setTextColor(TFT_GREEN, TFT_BLACK); }
         else { tft.setTextColor(TFT_DARKGREY1, TFT_BLACK); };
      tft.setCursor(395,30);
      tft.print("DNR-16");
    }


    //··························· Tipo de medidor de Señal "de abajo" ··························

    
     mtr_arx = radio.get_mem_param(165);// & B0000111;


    // ·························· NAR, RPT Offset (551) ········································
    rpt_off_NAR = radio.get_mem_param(551) & B11001000;             // bit 7 = 1 = +RPT

    if( rpt_off_NAR_bk != rpt_off_NAR)
    {                                                               // bit 6 = 1 = -RPT 
       rpt_off_NAR_bk = rpt_off_NAR;                                // bit 7 y 6 = 0 = SIMPLEX
                                                                    // bit 3 = 1 = NAR a ON --> FMN      
                                                                    // El NAR esta gestionado en el modulo MODE
                                                                    // y genera el numero 136 cuando se selecciona NAR
       rpt_off_NAR = rpt_off_NAR >> 6 ;                             
       tft.fillRect(28,150,55,25,TFT_BLACK);
       tft.setCursor(30,170);
       switch (rpt_off_NAR)
       {
       case 1: {
                 tft.setTextColor(TFT_GREEN, TFT_BLACK);
                 tft.print("-RPT");
                 break;
               }
    
       case 2: {
                 tft.setTextColor(TFT_GREEN, TFT_BLACK);
                 tft.print("+RPT");
                 break;
               }
    
       case 0: {
                 tft.setTextColor(TFT_DARKGREY1, TFT_BLACK);
                 tft.print(" RPT");
                 break;
               }
       }
    }

// ··················································································
//                                   Potencia
// ··················································································    
             
   switch (band_freq_a)
   {
      case 10 ... 160 : {  
                          pwr_hf = radio.get_mem_param(155) & B01111111;
                          if( pwr_hf_bk != pwr_hf )
                             {
                                pwr_hf_bk = pwr_hf;
                                tft.fillRect(138,10,100,25,TFT_BLACK);
                                tft.setTextColor(TFT_GREEN, TFT_BLACK);
                                tft.setCursor(140,30);
                                tft.print("Pwr:");
                                tft.print(pwr_hf);      
                             }
                        }
                        break;
                        
      case 6:           {
                           pwr_6m = radio.get_mem_param(170) & B01111111;
                        
                           if( pwr_6m != pwr_6m_bk )
                           {
                              pwr_6m_bk = pwr_6m;
                              tft.fillRect(138,10,100,25,TFT_BLACK);
                              tft.setTextColor(TFT_GREEN, TFT_BLACK);
                              tft.setCursor(140,30);
                              tft.print("Pwr:");
                              tft.print(pwr_6m);   
                           }
                        }
                        break;

     default:           { tft.fillRect(138,10,100,25,TFT_BLACK); }  
                        break;
                        
   }


    
// ··················································································
//                                   RX STATUS 
// ··················································································
    
/*    rx_stat = radio.getRxStatus() & B00100000 ; //Dicriminador 0=Centered 1=off-Center
    //Serial.println(rx_stat);

    if( rx_stat == 0 && modo == 8)   // modo= 8 es FM
    {
         tft.drawCircle(60,30,10,TFT_GREEN);
    }
    else
    {
         tft.drawCircle(60,30,10,TFT_RED);   
    }
*/
    
// ···········································································
/*
    rit = radio.get_mem_param(106);
    atc = radio.get_mem_param(169);
*/

  
       soft_irq = false;
    }
}


   pantalla = 0;

    
} //_________________________ Fin de Pantanlla 1 _____________________________
