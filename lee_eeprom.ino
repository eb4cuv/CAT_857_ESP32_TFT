

/************************************************************
 * 
 * 
 *    Herramientas de diseño
 * 
 *    Lee la eprom completa de la 857.
 * 
 ************************************************************/



int max_mem = 2500;

byte rigGetMem[5] = {0x00,0x55,0x00,0x00,0xBB};
byte smeter_rx;

byte mem_1[2500]; //Creo que la 857 tiene mas de 4k de memoria
byte mem_2[2500];

long timeout = millis();
long elapsed = 0;

void lee_mem()
{

  Serial2.flush();

//--------------------------------------------------------------
  
  Serial.println("Leyendo 1 pasada.");
  
  for (int i=0; i< max_mem; i++) 
  {
    
    long timeout = millis();
    long elapsed = 0;
    Serial2.flush();

    rigGetMem[1] = i & 255;
    rigGetMem[0] =(i >> 8 ) & 255;
    
    sendCmd(rigGetMem, 5);
    
    while (Serial2.available() < 1 && elapsed < 1000)
    {
       elapsed = millis() - timeout;
    ;}

    mem_1[i] = Serial2.read();
    //Serial.println(i);
  }  
    
    Serial.println("leido pasada 1.");
    Serial.println("Cambie parametro. Esperando 10sg.");
    Serial.println();
    Serial.println();
    Serial.println();
    delay(5000);
//-------------------------------------------------------------

  Serial.println("Leyendo 2 pasada.");
  
  for (int i=0; i< max_mem; i++) 
  {

    long timeout = millis();
    long elapsed = 0;
    Serial2.flush();

    rigGetMem[1] = i & 255;
    rigGetMem[0] =(i >> 8 ) & 255;
    
    //rigGetMem[1] = i;
    
    sendCmd(rigGetMem, 5);
    
    while (Serial2.available() < 1 && elapsed < 1000)
    {
       elapsed = millis() - timeout;
    ;}

    mem_2[i] = Serial2.read();
    //Serial.println(i);
  }  
    
  Serial.println("leido pasada 2.");  

//----------------------------------------------------------
  

  for (int i=0; i< max_mem; i++) 
  {

    //Serial.println( i + ": " + mem_1[i] + " -- " + mem_2[i]);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(mem_1[i]);
    
    if( mem_1[i] != mem_2[i])
  {  
     Serial.println("***********************");
     Serial.print(i);
     Serial.print("-");
     Serial.print(i, HEX);  
     Serial.print("--->");
     Serial.print("mem1: ");
     Serial.print(mem_1[i],BIN);
     Serial.print("--");
     Serial.print("mem2: ");
     Serial.println(mem_2[i],BIN);
     
   }  
     
   /*   Serial.print(i);
      Serial.print("----");
      Serial.print(mem_1[i]);
      Serial.print("--");
      Serial.println(mem_2[i]);
    */ 
    
  }

/*---------------------------------------------------*/

/*   
   sendCmd(rigGetMem, 5);
   

   //Serial.println(int(rigGetMem[4]) + "-" + int(rigGetMem[3])); // + "-" + int(rigGetMem[2]) + "-" + int(rigGetMem[1]) + "-" + int(rigGetMem[0])); 
   
   while (Serial2.available() < 1 && elapsed < 1000)
  {
    elapsed = millis() - timeout;
  ;}
  
  smeter_rx = Serial2.read();
  Serial.println(String(smeter_rx,BIN));
*/    
 
} 



void sendCmd(byte cmd[], byte len)
{
  for (byte i=0; i<len; i++) 
  {
    Serial2.write(cmd[i]); 
  }  
   
}  
  
