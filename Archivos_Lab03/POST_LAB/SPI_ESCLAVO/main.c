#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)
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

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

//*****************************************************************************
// Definici?n e importaci?n de librer?as
//*****************************************************************************
#include <xc.h>
#include <stdint.h>
#include "SPI.h"
#include "ADC.h"
//*****************************************************************************
// Definici?n de variables
//*****************************************************************************
#define _XTAL_FREQ 8000000

int adc_val = 0;
int contador;
int bandera = 0;
//*****************************************************************************
// Definici?n de funciones para que se puedan colocar despu?s del main de lo 
// contrario hay que colocarlos todas las funciones antes del main
//*****************************************************************************
void setup(void);
//*****************************************************************************
// C?digo de Interrupci?n 
//*****************************************************************************
void __interrupt() isr(void){
    
  
     
   if(SSPIF == 1){
       PORTD = spiRead();
       if(PORTD == 0){
        spiWrite(adc_val);
       }
       else if(PORTD == 1){
        spiWrite(contador);  
       }
        SSPIF = 0;
    }
    
    if (PIR1bits.ADIF){
        if (ADCON0bits.CHS == 5){
            adc_val = ADRESH; 
        }
        PIR1bits.ADIF = 0; 
    }
}
//*****************************************************************************
// C?digo Principal
//*****************************************************************************
void main(void) {
    setup();
    
    while(1){
       ADC_IF();
        if(!PORTBbits.RB7){
            while(!PORTBbits.RB7);
           contador ++;
        }
       else if(!PORTBbits.RB5){
            while(!PORTBbits.RB5);
            contador = contador - 1;
        }
            
    }
    return;
}
//*****************************************************************************
// Funci?n de Inicializaci?n
//*****************************************************************************
void setup(void){
    ANSEL = 0;
    ANSELH = 0;
    
    TRISB = 1;
    TRISD = 0;
    TRISA = 0;
    OSCCONbits.IRCF = 0b111;  // Configurar la frecuencia del oscilador interno a 8MHz
    OSCCONbits.SCS = 0b10;    // Utilizar el oscilador interno para el sistema
    PORTD = 0;
    PORTA = 0;
    
    ADC_CONF(8); 
    //CONFIGURACIÓN DE PULL UPS
    OPTION_REGbits.nRBPU = 0;
    WPUBbits.WPUB7 = 1;
    IOCBbits.IOCB7 = 1;
    WPUBbits.WPUB5 = 1;
    IOCBbits.IOCB5 = 1;
    
    INTCONbits.PEIE = 1; 
    PIE1bits.ADIE = 1; 
    ADCON0bits.GO = 0; 
    
    INTCONbits.GIE = 1;         // Habilitamos interrupciones
    INTCONbits.PEIE = 1;        // Habilitamos interrupciones PEIE
    PIR1bits.SSPIF = 0;         // Borramos bandera interrupci?n MSSP
    PIE1bits.SSPIE = 1;         // Habilitamos interrupci?n MSSP
    TRISAbits.TRISA5 = 1;       // Slave Select
    INTCONbits.RBIE = 1;
    INTCONbits.RBIF = 0;
    spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);

}