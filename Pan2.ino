

byte rigMem[5] = {0x00,0x00,0x00,0x00,0xBB};
byte mem[512];
byte ah;
byte num_pan_mem = 1;
bool pan_pintada = false;

void pan1_mem()  //----------------------------------------------------------------------------
{
// ··· Borra pantalla
    tft.fillRect(0,0,480,290,TFT_BLACK);

    tft.setCursor(0,20);
    tft.print("01-Ext. Menu:");
    tft.setCursor(160,20);
    ah = mem[0x91] & B01000000;
    if (ah == B01000000) { tft.print("ON"); } else { tft.print("OFF"); }

    tft.setTextColor(TFT_RED, TFT_BLACK);

    tft.setCursor(0,45);
    tft.print("02-144Mhz ARS:");   
    tft.setCursor(160,45);
    ah = mem[0x72] & B01000000;
    if (ah == B01000000) { tft.print("ON"); } else { tft.print("OFF"); }

    tft.setCursor(0,70);
    tft.print("03-430Mhz ARS:");   
    tft.setCursor(160,70);
    ah = mem[0x72] & B00100000;
    if (ah == B00100000) { tft.print("ON"); } else { tft.print("OFF"); }

    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    
    tft.setCursor(0,95);
    tft.print("04-AM/FM Dial:");   
    tft.setCursor(160,95);
    ah = mem[0x72] & B10000000;
    if (ah == B10000000) { tft.print("ON"); } else { tft.print("OFF"); }

    tft.setCursor(0,120);
    tft.print("05-AM Mic Gain:");   
    tft.setCursor(160,120);
    ah = mem[0x7B] & B01111111;
    tft.print(ah);
    
    tft.setCursor(0,145);
    tft.print("06-AM Step:");   
    tft.setCursor(160,145);
    ah = mem[0x12D];
    switch (ah) {
      case B1000000:
         tft.print("2.5 Khz");
      break;
      case B1001000:
         tft.print("5 Khz");
      break;
      case B1010000:
         tft.print("9 Khz");         
      break;
      case B1011000:
         tft.print("10 Khz");         
      break;
      case B1100000:
         tft.print("12 Khz");         
      break;            
      case B1101000:
         tft.print("25 Khz");         
      break;      
    }  
    
tft.setTextColor(TFT_RED, TFT_BLACK);

    tft.setCursor(0,170);
    tft.print("07-APO Time:");   
    tft.setCursor(160,170);
    ah = mem[0x78] & B00000111;
    
    switch (ah)  {
      case 0:
         tft.print("Off");
      break;
      case 1:
         tft.print("1 hora");
      break;
      case 2:
         tft.print("2 horas");         
      break;
      case 3:
         tft.print("3 horas");
      break;
      case 4:
         tft.print("4 horas");
      break;
      case 5:
         tft.print("5 horas");         
      break;
      case 6:
         tft.print("6 horas");         
      break;           
    }

tft.setTextColor(TFT_YELLOW, TFT_BLACK);    
        
    tft.setCursor(0,195);
    tft.print("08-ARTS Beep:");   
    tft.setCursor(160,195);
    ah = mem[0x70] & B11000000;
    switch (ah) {
      case 0:
         tft.print("OFF");
      break;
      case 0x40:
         tft.print("RANGE");
      break;
      case 0x80:
         tft.print("ALL");
      break;
    }  
    
    tft.setCursor(0,220);
    tft.print("09-ARTS ID:");   
    tft.setCursor(160,220);
    ah = mem[0x70] & B00010000;
    if (ah == B00010000) { tft.print("ON"); } else { tft.print("OFF"); }

    tft.setCursor(0,245);
    tft.print("10-ARTS IDW:");   
    tft.setCursor(160,245);
    //ah = mem[0x8C] & B10000000;

tft.setTextColor(TFT_RED, TFT_BLACK);


    tft.setCursor(0,270);
    tft.print("11-BEACON txt:");   
    tft.setCursor(160,270);
    //ah = mem[0x8C] & B10000000;
    
    tft.setCursor(240,20);
    tft.print("12-BEACON Time:");   
    tft.setCursor(420,20);
    ah = mem[0xA6]; 
    tft.print(ah);
           
    tft.setCursor(240,45);
    tft.print("13-BEEP Tone:");   
    tft.setCursor(420,45);
    ah = mem[0x6F]& B00000011;
    switch (ah)  {
      case 0:
         tft.print("440hz");
      break;
      case 1:
         tft.print("880hz");
      break;
      case B10:
         tft.print("1760hz");         
      break;     
    }


    tft.setCursor(240,70);
    tft.print("14-BEEP Vol:");   
    tft.setCursor(420,70);
    ah = mem[0x8F];
    tft.print(ah);


tft.setTextColor(TFT_YELLOW, TFT_BLACK);    

    tft.setCursor(240,95);
    tft.print("15-CAR LSB R:");   
    tft.setCursor(410,95);
    ah = mem[0x84]; 

    if(bitRead(ah,7) == 0)  // Numero positivo
    {
     ah = mem[0x84] & B00011111; tft.print("+");      
    }
    else
    {
       ah = ah -1; ah = ~ah; tft.print("-");        
    }
    tft.print(ah*10); tft.print("Hz");

    

    tft.setCursor(240,120);
    tft.print("16-CAR LSB T:");   
    tft.setCursor(410,120);
    ah = mem[0x86];
    
    if(bitRead(ah,7) == 0)  // Numero positivo
    {
     ah = mem[0x86] & B00011111; tft.print("+");      
    }
    else
    {
       ah = ah -1; ah = ~ah; tft.print("-");        
    }
    tft.print(ah*10); tft.print("Hz");
    

    tft.setCursor(240,145);
    tft.print("17-CAR USB R:");   
    tft.setCursor(410,145);
    ah = mem[0x85];
    
    if(bitRead(ah,7) == 0)  // Numero positivo
    {
     ah = mem[0x85] & B00011111; tft.print("+");       
    }
    else
    {
       ah = ah -1; ah = ~ah; tft.print("-");        
    }
    tft.print(ah*10); tft.print("Hz");
    

    tft.setCursor(240,170);
    tft.print("18-CAR USB T:");   
    tft.setCursor(410,170);
    ah = mem[0x87];
    
    if(bitRead(ah,7) == 0)  // Numero positivo
    {
     ah = mem[0x87] & B00011111; tft.print("+");       
    }
    else
    {
       ah = ah -1; ah = ~ah; tft.print("-");        
    } 
    tft.print(ah*10); tft.print("Hz");
    

tft.setTextColor(TFT_RED, TFT_BLACK);
    

    tft.setCursor(240,195);
    tft.print("19-CAT Rate:");   
    tft.setCursor(430,195);
    //ah = mem[0x8C] & B10000000;

    tft.setCursor(240,220);
    tft.print("20-CAT/LIN/TUN:");   
    tft.setCursor(430,220);
    //ah = mem[0x8C] & B10000000;                    

    tft.setCursor(240,245);
    tft.print("21-Clar/Dial:");   
    tft.setCursor(430,245);
    ah = mem[0x6F] & B00000100;
    if (ah == B00000000) { tft.print("MAIN"); } else { tft.print("SEL"); } 

    pan_pintada = true;
    
}  


//-------------------------------------------------------------------------------


void pan2_mem()
{
// ··· Borra pantalla
    tft.fillRect(0,0,480,290,TFT_BLACK);
    
 tft.setTextColor(TFT_CYAN, TFT_BLACK);
 
    tft.setCursor(0,20);
    tft.print("22-CW Auto Mode:");   
    tft.setCursor(170,20);
    ah = mem[0x92] & B10000000;
    if (ah == B00000000) { tft.print("OFF"); } else { tft.print("SEL"); }
    
    tft.setCursor(0,45);
    tft.print("23-CW BFO:");   
    tft.setCursor(170,45);
    ah = mem[0x92] & B00000011;

    switch (ah)  {
      case 0:
         tft.print("USB");
      break;
      case 1:
         tft.print("LSB");
      break;
      case B10:
         tft.print("AUTO");         
      break;     
    }


    tft.setCursor(0,70);
    tft.print("24-CW Delay:");   
    tft.setCursor(170,70);   
   
    tft.setCursor(0,95);
    tft.print("25-CW Key Rev:");   
    tft.setCursor(170,95);
    ah = mem[0x6B] & B00000100;
    if (ah == 0) { tft.print("Nor"); } else { tft.print("Rev"); }
    

    tft.setCursor(0,120);
    tft.print("26-CW Paddle:");   
    tft.setCursor(170,120);
    ah = mem[0x7B] & B10000000;
    if (ah == 0) { tft.print("Elekey"); } else { tft.print("Mickey"); }
    
    tft.setCursor(0,145);
    tft.print("27-CW Pitch:");   
    tft.setCursor(170,145);
    ah = mem[0x71] & B00000111;
    switch (ah)  {
      case 0:
         tft.print("400");
      break;
      case 1:
         tft.print("500");
      break;
      case 2:
         tft.print("600");         
      break;     
      case 3:
         tft.print("700");
      break;
      case 4:
         tft.print("800");         
      break;
    }


    tft.setCursor(0,170);
    tft.print("28-CW QSK:");   
    tft.setCursor(170,170);
    ah = mem[0x92] & B00011100;
    switch (ah)  {
      case 0:
         tft.print("10ms");
      break;
      case B100:
         tft.print("15ms");
      break;
      case B1000:
         tft.print("20ms");         
      break;     
      case B1100:
         tft.print("25ms");
      break;
      case B10000:
         tft.print("30ms");         
      break;
    }


    tft.setCursor(0,195);
    tft.print("29-CW Side Tone:");   
    tft.setCursor(170,195);
    ah = mem[0x74] & B01111111;
    tft.print(ah); 
      

    tft.setCursor(0,220);
    tft.print("30-CW Speed:");   
    tft.setCursor(170,220);
    ah = mem[0x75] & B00111111;
    tft.print(ah + 4); tft.print("wpm"); 


    tft.setCursor(0,245);
    tft.print("31-CW Training:");   
    tft.setCursor(170,245);
    ah = mem[0x92] & B01100000;
    switch (ah)  {
      case B00000000:
         tft.print("N:");
      break;
      case B00100000:
         tft.print("A:");
      break;
      case B01000000:
         tft.print("AN:");         
      break;     
    }


    tft.setCursor(0,270);
    tft.print("32-CW Weight:");   
    tft.setCursor(170,270);
    ah = mem[0x72] & B00011111;
    tft.print("1:");
    tft.print(2.5 + (ah/10));
    
    

tft.setTextColor(TFT_YELLOW, TFT_BLACK);

    tft.setCursor(240,20);
    tft.print("33-DCS CODE:");   
    tft.setCursor(410,20);

    tft.setCursor(240,45);
    tft.print("34-DCS INV:");   
    tft.setCursor(410,45);
    ah = mem[0x79] & B11000000;
    switch (ah)  {
      case B00000000:
         tft.print("Tn-Rn");
      break;
      case B01000000:
         tft.print("Tn-Riv");
      break;
      case B10000000:
         tft.print("Tiv-Rn");         
      break;
      case B11000000:
         tft.print("Tiv-Riv");         
      break;
    }

    
    tft.setCursor(240,70);
    tft.print("35-DIAL Step:");   
    tft.setCursor(410,70);
    ah = mem[0x70] & B01000000;
    if (ah == 0) { tft.print("Fine"); } else { tft.print("Coarse"); }
    

    tft.setCursor(240,95);
    tft.print("36-DIG Disp:");   
    tft.setCursor(410,95);

    tft.setCursor(240,120);
    tft.print("37-DIG Gain:");   
    tft.setCursor(410,120);
    ah = mem[0x7D] & B01111111;
    tft.print(ah);    
   

    tft.setCursor(240,145);
    tft.print("38-DIG MOode:");   
    tft.setCursor(410,145);


    tft.setCursor(240,170);
    tft.print("39-DIG Shift:");   
    tft.setCursor(410,170);

    tft.setCursor(240,195);
    tft.print("40-DIG Vox:");   
    tft.setCursor(410,195);




    tft.setCursor(240,220);
    tft.print("41-DISP Color:");   
    tft.setCursor(410,220);

    tft.setCursor(240,245);
    tft.print("42-DISP Contrast:");   
    tft.setCursor(410,245);

    tft.setCursor(240,270);
    tft.print("43-DISP Intensity:");   
    tft.setCursor(410,270);
    


    pan_pintada = true;
  
}



//-------------------------------------------------------------------------------


void pan3_mem()
{
// ··· Borra pantalla
    tft.fillRect(0,0,480,290,TFT_BLACK);

    tft.setCursor(0,20);
    tft.print("44-DISP Mode:");   
    tft.setCursor(180,20);
    
    tft.setCursor(0,45);
    tft.print("45-dsp BPF width:");   
    tft.setCursor(180,45);

    tft.setCursor(0,70);
    tft.print("46-dsp HPF cutoff:");   
    tft.setCursor(180,70);   
   
    tft.setCursor(0,95);
    tft.print("47-dsp LPF cutoff:");   
    tft.setCursor(180,95);

    tft.setCursor(0,120);
    tft.print("48-dsp MIC eq:");   
    tft.setCursor(180,120);
    
    tft.setCursor(0,145);
    tft.print("49-dsp NR level:");   
    tft.setCursor(180,145);

    tft.setTextColor(TFT_RED, TFT_BLACK);

    tft.setCursor(0,170);
    tft.print("50-EMERGENCY:");   
    tft.setCursor(180,170);

    tft.setTextColor(TFT_YELLOW, TFT_BLACK);

    tft.setCursor(0,195);
    tft.print("51-FM Mic Gain:");
    ah = mem[124]& B01111111;   
    tft.setCursor(180,195);
    tft.print(ah); 

    
    tft.setCursor(0,220);
    tft.print("52-FM Step:");   
    tft.setCursor(180,220);

    tft.setTextColor(TFT_CYAN, TFT_BLACK);

    tft.setCursor(0,245);
    tft.print("53-Home-->Vfo:");   
    tft.setCursor(180,245);

    tft.setCursor(0,270);
    tft.print("54-Lock Mode:");   
    tft.setCursor(180,270);



    tft.setCursor(240,20);
    tft.print("55-Mem Group:");   
    tft.setCursor(410,20);

    tft.setCursor(240,45);
    tft.print("56-Mem Tag:");   
    tft.setCursor(410,45);

    tft.setCursor(240,70);
    tft.print("57-DM-MEM/VFO:");   
    tft.setCursor(410,70);

    tft.setCursor(240,95);
    tft.print("58-Mic Scan:");   
    tft.setCursor(410,95);

    tft.setCursor(240,120);
    tft.print("59-Mic Sel:");   
    tft.setCursor(410,120);

    tft.setCursor(240,145);
    tft.print("60-MTR Arx Sel:");   
    tft.setCursor(410,145);    

    tft.setCursor(240,170);
    tft.print("61-MTR Atx Sel:");   
    tft.setCursor(410,170);

    tft.setCursor(240,195);
    tft.print("62-MTR Peak Hold:");   
    tft.setCursor(410,195);

    tft.setCursor(240,220);
    tft.print("63-NB Level:");   
    tft.setCursor(410,220);

    tft.setCursor(240,245);
    tft.print("64-OP FILTER 1:");   
    tft.setCursor(410,245);

    tft.setCursor(240,270);
    tft.print("65-PG A:");   
    tft.setCursor(410,270);
    
    pan_pintada = true;
} 


void pan4_mem()
{
// ··· Borra pantalla
    tft.fillRect(0,0,480,290,TFT_BLACK);

    tft.setCursor(0,20);
    tft.print("66-PG B:");   
    tft.setCursor(180,20);
    
    tft.setCursor(0,45);
    tft.print("67-PG C:");   
    tft.setCursor(180,45);

    tft.setCursor(0,70);
    tft.print("68-PG ACC:");   
    tft.setCursor(180,70);   
   
    tft.setCursor(0,95);
    tft.print("69-PG P1:");   
    tft.setCursor(180,95);

    tft.setCursor(0,120);
    tft.print("70-PG P2:");   
    tft.setCursor(180,120);
    
    tft.setCursor(0,145);
    tft.print("71-PKT 1200:");   
    tft.setCursor(180,145);

    tft.setCursor(0,170);
    tft.print("72-PKT 9600:");   
    tft.setCursor(180,170);

    tft.setCursor(0,195);
    tft.print("73-PKT RATE:");   
    tft.setCursor(180,195);

    tft.setCursor(0,220);
    tft.print("74-PROC LEVEL:");   
    tft.setCursor(180,220);

    tft.setCursor(0,245);
    tft.print("75-RF POWER SET:");   
    tft.setCursor(180,245);

    tft.setCursor(0,270);
    tft.print("76-RPT SHIFT:");   
    tft.setCursor(180,270);



    tft.setCursor(240,20);
    tft.print("77-SCAN MODE:");   
    tft.setCursor(410,20);

    tft.setCursor(240,45);
    tft.print("78-SCAN RESUME:");   
    tft.setCursor(410,45);

    tft.setCursor(240,70);
    tft.print("79-SPLIT TONE:");   
    tft.setCursor(410,70);

    tft.setCursor(240,95);
    tft.print("80-SQL/RF GAIN:");   
    tft.setCursor(410,95);

    tft.setCursor(240,120);
    tft.print("81-SSB MIC GAIN:");   
    tft.setCursor(410,120);

    tft.setCursor(240,145);
    tft.print("82-SSB STEP:");   
    tft.setCursor(410,145);    

    tft.setCursor(240,170);
    tft.print("83-TONE FREQ:");   
    tft.setCursor(410,170);

    tft.setCursor(240,195);
    tft.print("84-TOT TIME:");   
    tft.setCursor(410,195);

    tft.setCursor(240,220);
    tft.print("85-TUNER/ATAS:");   
    tft.setCursor(410,220);

    tft.setCursor(240,245);
    tft.print("86-TX IF FILTER:");   
    tft.setCursor(410,245);

    tft.setCursor(240,270);
    tft.print("87-VOX DELAY:");   
    tft.setCursor(410,270);
    
    pan_pintada = true;
}       

void pan5_mem()
{
// ··· Borra pantalla
    tft.fillRect(0,0,480,290,TFT_BLACK);

    tft.setCursor(0,20);
    tft.print("88-VOX GAIN:");   
    tft.setCursor(180,20);
    
    tft.setCursor(0,45);
    tft.print("89-XVTR A FREQ:");   
    tft.setCursor(180,45);

    tft.setCursor(0,70);
    tft.print("90-XVTR B FREQ:");   
    tft.setCursor(180,70);   
   
    tft.setCursor(0,95);
    tft.print("91-XVTR SEL:");   
    tft.setCursor(180,95);



    tft.setCursor(240,20);
    tft.print("CPU Freq: ");
    tft.print(getCpuFrequencyMhz());   
    tft.println(" Mhz.");

    tft.setCursor(240,45);
    tft.print("XTAL Freq: ");
    tft.print(getXtalFrequencyMhz());   
    tft.println(" Mhz.");


    tft.setCursor(240,70);
    tft.print("APB Freq: ");
    tft.print(getApbFrequency() / 1000000);
    tft.println(" Mhz.");   

    
    pan_pintada = true;
}    




/************************************************************
 *  Pantalla_2()
 ************************************************************/
void pantalla_2()
{


   
//_________ Cambia de botones _________________________________
/*      tft.setTextColor(TFT_BLACK, TFT_DARKCYAN);
      tft.setCursor(104,312);
      tft.print("eEPROM");

      tft.setTextColor(TFT_WHITE, TFT_DARKCYAN);
      tft.setCursor(26,312);
      tft.print("VFO");
*/

  cambia_marcos(2);



// ··· Borra la pantalla
    tft.fillRect(0,0,480,290,TFT_BLACK);
    tft.setFreeFont(FF46);

//__________ Lee la memoria ___________________________________
    tft.setCursor(150,160);
    tft.setTextColor(TFT_GREEN);
    tft.print("Reading Memory");

    for (int i=0; i<512; i++) 
    {  
       long tio = millis();
       long elap = 0;
       Serial2.flush();

      rigMem[1] = i & 255;
      rigMem[0] =(i >> 8 ) & 255;

/*    Serial.print(i & 255, BIN);
    Serial.print("-->");
    Serial.println(((i >> 8) & 255), BIN);
*/    
       sendCmd(rigMem, 5);
    
       while (Serial2.available() < 1 && elap < 1000)
       {
          elap = millis() - tio;
       ;}
       mem[i] = Serial2.read();

     /*  Serial.print(i);
       Serial.print(": ");
       Serial.println(mem[i],BIN);
      */ 
    }


   

//__________ Presenta la memoria en pantalla  ____________________________

 
    tft.setFreeFont(FSS9);
    

    
    while ( touch_y < 290 ) 
    {    
      
      if (pan_pintada == false)
      {
         switch (num_pan_mem)
         {
            case 1: pan1_mem();
            break;
            case 2: pan2_mem();
            break;
            case 3: pan3_mem();
            break;
            case 4: pan4_mem();
            break;
            case 5: pan5_mem();
            break;
         }
      }
      
      tft.getTouch(&touch_x, &touch_y);

      if( touch_x > 300)
      {
        num_pan_mem++;
        pan_pintada = false;
        touch_x = 0;
      }
      
      if( num_pan_mem == 6) num_pan_mem = 1;      
    } 
    pan_pintada = false;               

/*    
    ah = mem[104]& B00000001;
    if (ah == 0) { tft.print("vfo: A"); } else { tft.print("vfo: B"); }


//_______________________________________ POWER _________________________________    

    tft.drawRoundRect(400,10,80,100,5,TFT_WHITE);

    tft.setCursor(410,15);
    tft.print("Power");
       
    ah = mem[155]& B01111111; //power hf
    tft.setCursor(10,40);
    tft.print("hf:  "); tft.print(ah);

    ah = mem[170]& B01111111; //power 6m
    tft.setCursor(10,65);
    tft.print("6m: "); tft.print(ah);
    
    ah = mem[171]& B01111111; //power vhf
    tft.setCursor(10,90);
    tft.print("vhf: "); tft.print(ah);

    ah = mem[172]& B01111111; //power uhf
    tft.setCursor(10,115);
    tft.print("uhf: "); tft.print(ah);
//_______________________________________MIC GAIN______________________________

    ah = mem[122]& B01111111; //b7 = mic_scan - b0..6 = ssb_mic_gain
    tft.setCursor(10,145);
    tft.print("ssb: "); tft.print(ah);

    ah = mem[123]& B01111111; //b7 = cw_paddle - b0..6 = am_mic_gain
    tft.setCursor(10,170);
    tft.print("am: "); tft.print(ah);
   
//_____________________________________________________________________________

*/
 

   pantalla = 0;
     
}
