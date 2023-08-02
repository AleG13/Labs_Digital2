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

#define RS RC6
#define EN RC7
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
#include "SPI.h"
#include "LCD.h"
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 8000000
char val_pot;

int vol1, vol2, bandera;
char buffer[5];
char buffer2[5];
char buffer3[5];
char vol1_str[5];
char cen, dec, uni;
char cen2, dec2, uni2;
char cen3, dec3, uni3;
char ADC;
char contador;
char temperatura;
void Division(char y){
    cen = (y / 100);
    dec = ((y % 100) / 10);
    uni = ((y % 100) % 10);
}
void Division2(char y){
    cen2 = (y / 100);
    dec2= ((y % 100) / 10);
    uni2 = ((y % 100) % 10);
}
void Division3(char y){
    cen3 = (y / 100);
    dec3 = ((y % 100) / 10);
    uni3 = ((y % 100) % 10);
}
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
       while(!SSPSTATbits.BF);
       ADC = spiRead();
       __delay_ms(1);
       PORTCbits.RC2 = 1;       //Slave Deselect 
       __delay_ms(25);
       
       PORTCbits.RC1 = 0;       //Slave Select
       __delay_ms(1);
       spiWrite(0);
       while(!SSPSTATbits.BF);
       contador = spiRead();
       __delay_ms(1);
       spiWrite(1);
       while(!SSPSTATbits.BF);
       temperatura = spiRead();
       PORTCbits.RC1 = 1;       //Slave Deselect 
       __delay_ms(25);
     
   
       
        Division(ADC); 
        Lcd_Set(2, 2); 
        sprintf(buffer, "%d", cen);
        Lcd_Write_Str(buffer);
        sprintf(buffer, "%d", dec);
        Lcd_Write_Str(buffer);
        sprintf(buffer, "%d", uni);
        Lcd_Write_Str(buffer);
         __delay_ms(10);
         
        Division2(contador); 
        Lcd_Set(2, 7); 
        sprintf(buffer2, "%d", cen2);
        Lcd_Write_Str(buffer2);
        sprintf(buffer2, "%d", dec2);
        Lcd_Write_Str(buffer2);
        sprintf(buffer2, "%d", uni2);
        Lcd_Write_Str(buffer2);
         __delay_ms(10);
         
        Division3(temperatura); 
        Lcd_Set(2, 12); 
        sprintf(buffer3, "%d", cen3);
        Lcd_Write_Str(buffer3);
        sprintf(buffer3, "%d", dec3);
        Lcd_Write_Str(buffer3);
        sprintf(buffer3, "%d", uni3);
        Lcd_Write_Str(buffer3);
         __delay_ms(10);
       
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
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 0;
    TRISD = 0; 
    TRISB = 0; 
    PORTD = 0;
    PORTCbits.RC2 = 1;
    PORTCbits.RC1 = 1;
    
    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
    Lcd_Init(); 
    Lcd_Clear();
    Lcd_Set(1,1);
    Lcd_Write_Str(" S1   S2   S3");
}