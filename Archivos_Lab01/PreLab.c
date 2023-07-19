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
#define _XTAL_FREQ 8000000

void main(void){
   // Configuración de los puertos
    TRISB = 0b11111111;  // RB1 como entrada
    TRISA = 0;              // Puerto A como salida
    PORTA = 0;              // Inicializar Puerto A en 0
    
    // Configuración de las resistencias pull-up
    OPTION_REGbits.nRBPU = 0;   // Habilitar resistencias pull-up en Puerto B
    WPUBbits.WPUB6 = 1;         // Habilitar resistencia pull-up en RB0
    WPUBbits.WPUB7 = 1;  
    // Habilitar resistencia pull-up en RB1
    
    // Variables
    uint8_t contador = 0;
    
    // Bucle principal
    while (1) {
        // Incrementar contador si se presiona RB0
        if (PORTBbits.RB6 == 0) {
                while (!PORTBbits.RB6); // Esperar a que se suelte el botón
                contador++;
        }
        
        // Decrementar contador si se presiona RB1
        if (PORTBbits.RB7 == 0) {
           
                while (!PORTBbits.RB7); // Esperar a que se suelte el botón
                contador = contador - 1;
            
        }
        
        // Mostrar contador en Puerto A
        PORTA = contador;
    }
    
    return;
}

