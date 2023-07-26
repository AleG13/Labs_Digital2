#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
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
#define _XTAL_FREQ 8000000


#define RS RC4
#define EN RC5
#define D0 RD0
#define D1 RD1
#define D2 RD2
#define D3 RD3
#define D4 RD4
#define D5 RB5
#define D6 RD6
#define D7 RD7

#include <xc.h>
#include <stdint.h>
#include "LCD.h" 
#include "ADC.h" 
#include "SERIAL.h" 
#include <stdio.h>
#include <stdlib.h>

// Variables globales
char val_pot;
char frec; 
char tr, rc;
char contador;
int vol1, vol2, bandera;
char buffer[5];
char vol1_str[5];
char cen, dec, uni;

void UART_write(char *word){
    while (*word != '\0'){
        while(!TXSTAbits.TRMT);
        TXREG = (*word);
        word++;
    }
    return;
}


void Division(char y){
    cen = (y / 100);
    dec = ((y % 100) / 10);
    uni = ((y % 100) % 10);
}


void __interrupt() isr(void){
   
    if (PIR1bits.ADIF){
        if (ADCON0bits.CHS == 5){
            val_pot = ADRESH; 
        }
        PIR1bits.ADIF = 0; 
    }
    
    // Rutina de interrupción del USART 
    if (PIR1bits.RCIF){
        if (RCREG == '+'){
            contador++; // Incrementar el valor del contador al recibir el carácter '+'
        }
        else if (RCREG == '-'){
            contador = contador - 1; // Decrementar el valor del contador al recibir el carácter '-'
        }
        else if (RCREG == 'p'){
            bandera = 1; // Activar una bandera para mostrar el valor del pot por USART
        }
        PIR1bits.RCIF = 0; // Limpiar la bandera de interrupción del USART
    }
    
    return;
}

void main(void) {
    ANSEL = 1; 
    ANSELH = 0; 
   
    TRISE = 1;
    TRISC = 0x80; 
    TRISD = 0; 
    
    OSCCONbits.IRCF = 0B111;
    OSCCONbits.OSTS = 0;
    OSCCONbits.SCS = 1;
    
    ADC_CONF(8); 
    USART_CONF(); 
    
    INTCONbits.PEIE = 1; 
    PIE1bits.ADIE = 1; 
    PIE1bits.RCIE = 1; 
    ADCON0bits.GO = 0; 
    Lcd_Init(); 
    PIR1bits.RCIF = 0; 
    
   
    Lcd_Clear();
    Lcd_Set(1,1);
    Lcd_Write_Str("POT     CONT");
    INTCONbits.GIE = 1; 
    
    while(1){
        // LOOP
        ADC_IF(); 
        vol1 = (val_pot * 1.961); 
        cen = vol1/100; 
        sprintf(vol1_str, "%d.%d", cen, (vol1 % 100)); 
        
        Division(contador);      
        Lcd_Set(2, 1); 
        Lcd_Write_Str(vol1_str);
        Lcd_Write_Str("V");
        __delay_ms(10);
        Lcd_Set(2, 10); 
        sprintf(buffer, "%d", cen);
        Lcd_Write_Str(buffer);
        sprintf(buffer, "%d", dec);
        Lcd_Write_Str(buffer);
        sprintf(buffer, "%d", uni);
        Lcd_Write_Str(buffer);
         __delay_ms(10);
        
        if (bandera == 1){
            bandera = 0;
            UART_write("\r \0"); 
            sprintf(buffer, "%.2dV  ", vol1); 
            UART_write("VOLTAJE: ");
            UART_write(buffer); 
            UART_write("\r \0"); 
      }
}
}
