#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)
// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#include <stdint.h>
#include "interup.h"
#include "activePullUps.h"
#include "ConfiPin.h"
#include "ReadPin.h"
#include "ADC.h"

#define _XTAL_FREQ 8000000
uint8_t contador_bin = 0;
uint8_t contador_adc = 0;

void __interrupt() isr (void){
     if(INTCONbits.RBIF){
         if(digitalRead(6,'B') == 0){
             while(digitalRead(6,'B') == 0);
             contador_bin ++;
         }
         else if(digitalRead(7,'B') == 0){
             while(digitalRead(7,'B') == 0);
             contador_bin = contador_bin - 1;
         }
         INTCONbits.RBIF = 0;
    }
    if (PIR1bits.ADIF == 1){
           
         //PORTA = adc_read();
           
       PIR1bits.ADIF  = 0; 
    }

} 
void main(void){
   // CONFIGURACIÓN DE PINES
    ANSEL = 0;
    ANSELbits.ANS0 = 1;
    PinInput(0,'E');
   
    PinOutput(8,'A');  
    PinInput(7,'B');
    PinInput(6,'B');
               
    //CONFIGURACIÓN DE PULL UPS
    ActivePullUps(6);
    ActivePullUps(7);
    
    //CONFIGURACION DE OSCILADOS
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.SCS = 1; 
    //CONFIGURACION DE INTERRUPCIONES
    ActiveInterrup();
    

    //CONFIGURACION ADC
    adc_init(5);
    
     
    // Bucle principal
    while (1) {
        
         __delay_ms(10);
         ADCON0bits.GO = 1;
         PORTA = contador_bin;
    }
    
    return;
}

