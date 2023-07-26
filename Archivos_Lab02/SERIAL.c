// Incluir las librer�as
#include <xc.h>
#include "SERIAL.h"


void USART_CONF() {
    // Configuraci�n de los registros para la comunicaci�n USART
    TXSTAbits.SYNC = 0; // Modo as�ncrono 
    TXSTAbits.BRGH = 1;
    BAUDCTLbits.BRG16 = 1;
    SPBRG = 207;
    SPBRGH =0;
    RCSTAbits.SPEN = 1; // Habilita USART
    RCSTAbits.RX9 = 0; // Recepci�n de 8 bits
    RCSTAbits.CREN = 1;
    TXSTAbits.TXEN = 1; // Transmisi�n de 8 bits
}