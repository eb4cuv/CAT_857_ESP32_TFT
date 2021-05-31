  /*  radio.lock(true);         // lock the radio's controls
    delay(500);
    radio.lock(false);        // unlock the radio's controls
    delay(500);

  */



//  RxStat = radio.getRxStatus() & 0x20; //Discriminador


      //tft.setFreeFont(FSBI24);
      //tft.drawString(strf, 90,90, GFXFF);       
      
//            Serial.println(as);
//      Serial.println(as1);
//      Serial.println("--");

//      if( as != as1)
//      {
//         tft.fillRect ( as+1,93,7,7,TFT_BLACK);
//      }
//      tft.fillRect ( as-5,93,28,7,TFT_BLACK);
//      tft.fillTriangle ( as+2,98,as+12,98,as+7,93,TFT_GREEN);



/**********************   *******************************/
/*
  byte rigTXMeter[5] = {0x00,0x68,0x00,0x00,0xBB};
  
  for (byte i=0; i<5; i++) {
    Serial2.write(rigTXMeter[i]);
  }   

  unsigned long startTime = millis();
  while (Serial2.available() < 2 && millis() < startTime + 2000) {
    ;
  }
  byte radioReply1 = Serial2.read();
  byte radioReply2 = Serial2.read();
  
  Serial.println(radioReply1);                            
  Serial.println(radioReply2);
  Serial.println("--");
*/




/*  
  byte rigTXMeter[5] = {0x00,0x00,0x00,0x00,0x00};
  rigTXMeter[4] = 0xBD;
  
  //sendCmd(rigTXMeter, 5);
  for (byte i=0; i<5; i++) {
    Serial2.write(rigTXMeter[i]);
  }   

 
  unsigned long startTime = millis();
  while (Serial2.available() < 2 && millis() < startTime + 2000) {
    ;
  }
  byte radioReply1 = Serial2.read();
  byte radioReply2 = Serial2.read();
  
  Serial.println(radioReply1);                            
  Serial.println(radioReply2);
 
*/ 





/*
 for (int jj=1; jj<2000; jj++)
 {
  

  byte iiaa[5] = {0x00,0x00,0x00,0x00,0x00};
  iiaa[4] = 167;
  long timeout = millis();
  long elapsed = 0;

  Serial2.flush();  
  
    for (byte i=0; i<5; i++)
    {
    Serial2.write(iiaa[i]);
    delay(10);
    }
  
  while (Serial2.available() < 1 && elapsed < 300) {
    elapsed = millis() - timeout;
      ;}

  Serial.print(jj);
  Serial.print(" -- ");
  Serial.println( Serial2.read());
 }
  */

 
 
 
 
 
