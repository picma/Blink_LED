/*
 * File:   BlinkLed.c
 * Author: Picma Co-founder Bruno Figueiredo
 *
 * Created on 6 de Fevereiro de 2017, 16:53
 */

#include <p24fxxxx.h>
 
_CONFIG1(    JTAGEN_OFF &       //JTAG port is disabled
             GCP_OFF &          //GSP Memory Code Protection OFF
             GWRP_OFF &         //GCC Flash Write Protection OFF
                    //
             FWDTEN_OFF &       //Watchdog Timer OFF
             ICS_PGx1)          //debug over PGD1 and PGC1
 
_CONFIG2(    FNOSC_FRCPLL &     //Internal FRC with PLL
             OSCIOFNC_ON &      //RA3 is clk out (fosc/2)
             POSCMOD_NONE &     //Primary oscillator disabled
             I2C1SEL_PRI)       //Use default SCL1/SDA1 pins
 
 
#pragma code
 
int main(void)
{
   unsigned long i;         //a 32 bit variable to use as a timer
 
   CLKDIVbits.RCDIV0=0;     //clock divider to 0
   AD1PCFG = 0xFFFF;        // Default all pins to digital
   OSCCONbits.SOSCEN=0;     //Disables the secondary oscilator
 
   TRISAbits.TRISA1 = 0;    //sets the Mode LED pin RA1 as output
   LATAbits.LATA1 = 0;      //turns LED off
 
//////////////////////////////////////////////////////////////////
///FOREVER LOOP///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
    
      while(1)
    {
      LATAbits.LATA1 = ~LATAbits.LATA1; //toggles the MODE LED
      i =0xFFFFF;                       //sets i to 1048575
      while (i--);                      //delay function
    }                                   //decrements i until 0  
     
}