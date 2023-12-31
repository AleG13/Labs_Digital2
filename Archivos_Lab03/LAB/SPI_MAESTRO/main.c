// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#include <stdint.h>
#include "SPI.h"

#define _XTAL_FREQ 8000000

void setup(void);
void main(void) {
    setup();
    //*************************************************************************
    // Loop infinito
    //*************************************************************************
    while(1){
        
       PORTCbits.RC2 = 0;       //Slave Select
       __delay_ms(1);
       spiWrite(PORTB);
       PORTD = spiRead();
       __delay_ms(1);
       PORTCbits.RC2 = 1;       //Slave Deselect 
       __delay_ms(25);
       
       
       PORTCbits.RC1 = 0;       //Slave Select
       __delay_ms(1);
       spiWrite(PORTB);
       PORTB = spiRead();
       __delay_ms(1);
       PORTCbits.RC1 = 1;       //Slave Deselect 
       __delay_ms(25);
       PORTA --;
    }
    return;
}
//*****************************************************************************
// Funci?n de Inicializaci?n
//*****************************************************************************
void setup(void){
    OSCCONbits.IRCF = 0b111;  // Configurar la frecuencia del oscilador interno a 8MHz
    OSCCONbits.SCS = 0b10;    // Utilizar el oscilador interno para el sistema
    
    ANSEL = 0;
    ANSELH = 0;
    TRISC2 = 0;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;
    TRISD = 0; 
    TRISB = 0; 
    PORTD = 0;
    PORTCbits.RC2 = 1;
    PORTCbits.RC1 = 1;
    
    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);

}