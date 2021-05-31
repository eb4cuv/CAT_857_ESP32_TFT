
void fft()
/*{
  for (int i = 180; i < 300; i = i + 10)
  {
    tft.drawLine(1, i , 479, i, 0x0007);
  }


  tft.setTextFont(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  // Set text colour to white and background to black

  tft.setCursor(1, 302);
  tft.print("14.140");
  tft.setCursor(420, 302);
  tft.print("14.350");
}  

*/


{

    int frq_fft = 54000;
    
     for (int j = 1; j<200; j++)
     {
        radio.setFreq(frq_fft);
        delay(50);

         adc_r = (analogRead(36)); //V

    
         if(adc_r == 0) adc_r = 1;
         adc_r = int(adc_r / 10);
      
         tft.drawFastVLine(j,450-adc_r, adc_r,TFT_RED);
  
        frq_fft = frq_fft + 700;
     
     }
} 
