/*

     Para añadir nuevas fuentes se debe hacer lo siguiente:

     - Añadir a Free_Fonts.h ubicado en el mismo directorio que este Skecht  el nombre de la nueva fuente:
        ejemplo: #define FF52 &unispace_bold_italic15pt7b
                 y mas abajo: #define FF52 1

     - Añadir el fichero de la fuente ya convertido a .h con un convertidor (por ejemplo el truetype2gfx)
       al directorio de libreria TFT_eSPI-master/Fonts/GFXFF

     - Añadir al fichero gfxfont.h el nombre de la fuente:
        ejemplo: #include <Fonts/GFXFF/unispace_bold_italic15pt7b.h> //FF52

     - Para usarla  en el sketch:
         #include "Free_Fonts.h"

         sprite_vfoa.drawString(strf,0,0,GFXFF);


     -- Eeprom de la FT857: https://www.yo3ggx.ro/ft8x7ee/eeprom.html


     Para poder dibujar la frecuencia con esos tipos de fuentes, se crea un bitmap en memoria del ancho y alto de
     los digitos que se pueden representar. Cuando se sabe la frecuencia, se pinta en el bitmap en modo "offline"
     y posteriormente se dibuja en pantalla ese bitmap.




     Para mayor rapidez en el cambio y presentacion de la frecuencia, el programa en el loop principal
     lee continuamente frecuencia y  smeter unicamente.
     Se programa una interrupcion cada 300ms que chequea si hay alguna otra tecla pulsada.
     De esa forma, la mayor parte del tiempo se emplea para la frecuencia y el s-meter

*/



#include "esp32-hal-cpu.h"   //Serial.println(getCpuFrequencyMhz());

#include "FT857D_ESP32.h"     // the file FT857D.h has a lot of documentation which I've added to make using the library easier
#include <TFT_eSPI.h> // Hardware-specific library
#include <TFT_eFEX.h> // Extension graphics functions library
#include <SPI.h>
#include <EEPROM.h>

#include "SPIFFS.h"

#include "Free_Fonts.h"

//#include "Server.hpp"

#define DAC1 25

#define TFT_DARKGREY1   0x2104



#define cuadricula_off        //Implementado en Pan1
#define diseno_lee_eprom_off  //Implementado en SETUP



//_____________________________________________________



hw_timer_t * ti_0 = NULL;
hw_timer_t * ti_1 = NULL;

FT857D radio;

TFT_eSPI tft = TFT_eSPI();       


TFT_eSprite sprite_vfob = TFT_eSprite(&tft);          // Definicion de Sprites
TFT_eSprite sprite_dial = TFT_eSprite(&tft);

TFT_eSprite sprite_0 = TFT_eSprite(&tft);
TFT_eSprite sprite_1 = TFT_eSprite(&tft);
TFT_eSprite sprite_2 = TFT_eSprite(&tft);
TFT_eSprite sprite_3 = TFT_eSprite(&tft);
TFT_eSprite sprite_4 = TFT_eSprite(&tft);        
TFT_eSprite sprite_5 = TFT_eSprite(&tft);
TFT_eSprite sprite_6 = TFT_eSprite(&tft);
TFT_eSprite sprite_7 = TFT_eSprite(&tft);

TFT_eSprite dial_oc1 = TFT_eSprite(&tft);
TFT_eSprite aguja_dial = TFT_eSprite(&tft);
TFT_eSprite ojo_magico = TFT_eSprite(&tft);

//TFT_eSprite aguja_smeter = TFT_eSprite(&tft);


TFT_eFEX fex_smeter = TFT_eFEX(&tft);
TFT_eFEX fex_presentacion = TFT_eFEX(&tft);  



//_____________________________________________________

int dx, dy;

int fftval, sm_b;

long adc_r, adc_bk;                // ADC

byte vfoA_modo, vfoB_modo = 13;    // modo de la radio
byte modo_t, modo_xt;

byte band_freq_a, bfa;             // Banda de frecuencias
long vfoA_freq, vfoB_freq;         // Frecuencia de cada VFO
long old_qrg_vfoA, old_qrg_vfoB;

byte ACT_VFO, act_vfo_old = 0 ;    // VFO activo

byte dnf, dnr, dbf, rit, atc ;
byte att, ipo, att_ipo, nb_agc ;
byte nb_agc_bk, dsp_fil_bk, att_ipo_bk = 250;
byte agc_on_off_bk, agc_on_off;

int hpf, lpf;
byte dsp_hpf, dsp_lpf, dsp_fil  = 0;
byte dsp_hpf_bk, dsp_lpf_bk;
byte dsp_dbf_bk, dsp_dbf ;
byte dsp_bpf_bk, dsp_bpf;

byte pwr_hf, pwr_6m;
byte pwr_hf_bk, pwr_6m_bk;

byte met_st, met_st_bk, spl_st, spl_st_bk = 250;
byte rpt_off_NAR, rpt_off_NAR_bk;

byte mtr_arx;


uint16_t touch_x = 0, touch_y = 0; // Para cargar las coordenadas del touch

byte pantalla = 1;


//--------------------------------------------------------------                         
uint16_t matriz_l [240];         //Variables del Smeter analogico
uint16_t matriz_l1 [240];

unsigned matriz_0_x[400];       //Coordenadas de la aguja actual
unsigned matriz_0_y[240];    
unsigned matriz_1_x [400];      //Coordenadas de la aguja anterior
unsigned matriz_1_y [240];

 
//---------------------------------------------------------------
uint16_t numpix_drawlin; 
float smeter_signal_ana, s_meter_bak;


//--------------------------------------------------------------
int cw_pb = round(70 * 1.25);   //Variables del plan de bandas
int dig_pb = round(31 * 1.25);
int tdm_pb = round(249 * 1.25);

//--------------------------------------------------------------

uint16_t bn;

volatile bool soft_irq ;


/************************************************************
 * 
 *   Coordenadas de la aguja del smeter 'ICOM'
 *   inicio izquierda: 47,101
 *   
 ************************************************************/   
 byte escala_aguja [] = 
 {   
    101,100,100,99,99,98,98,97,97,96,
    96,95,95,95,94,94,93,93,92,92,92,
    91,91,90,90,90,89,89,88,88,88,87,
    87,86,86,86,85,85,85,84,84,84,83,
    83,83,82,82,82,81,81,81,80,80,80,
    80,79,79,79,78,78,78,77,77,77,77,
    76,76,76,76,75,75,75,75,74,74,74,
    74,73,73,73,73,72,72,72,72,71,71,
    71,71,71,70,70,70,70,70,69,69,69,
    69,69,68,68,68,68,68,68,67,67,67,
    67,67,67,66,66,66,66,66,66,65,65,
    65,65,65,65,65,65,64,64,64,64,64,
    64,64,64,63,63,63,63,63,63,63,63,
    63,62,62,62,62,62,62,62,62,62,62,
    62,62,61,61,61,61,61,61,61,61,61,
    61,61,61,61,61,61,61,61,60,60,60,
    60,60,60,60,60,60,60,60,60,60,60,
    60,60,60,60,60,60,60,60,60,60,60,
    60,60,60,60,60,60,60,60,60,60,60,
    60,60,60,60,60,60,60,60,60,61,61,
    61,61,61,61,61,61,61,61,61,61,61,
    61,61,61,61,62,62,62,62,62,62,62,
    62,62,62,62,62,63,63,63,63,63,63,
    63,63,63,64,64,64,64,64,64,64,64,
    65,65,65,65,65,65,65,65,66,66,66,
    66,66,66,67,67,67,67,67,67,68,68,
    68,68,68,68,69,69,69,69,69,70,70,
    70,70,70,71,71,71,71,71,72,72,72,
    72,73,73,73,73,74,74,74,74,75,75,
    75,75,76,76,76,76,77,77,77,77,78,
    78,78,79,79,79,80,80,80,80,81,81,
    81,82,82,82,83,83,83,84,84,84,85,
    85,85,86,86,86,87,87,88,88,88,89,
    89,90,90,90,91,91,92,92,92,93,93,
    94,94,95,95,95,96,96,97,97,98,98,
    99,99,100,100,101,101
  
  };



//TFT_eSPI_Button button[1];

//================== Interrupcion por soft cada 300ms ===================================
void IRAM_ATTR onTimer_0()
{
  soft_irq = true;
}


/*
  //======================== Interrupcion por hard para leer el touchscreen =============================
  void IRAM_ATTR irq_touch()
  {
    touch_presed = true;
  }
*/
