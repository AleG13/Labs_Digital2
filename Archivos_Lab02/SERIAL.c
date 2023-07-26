// Incluir las librerías
#include <xc.h>
#include "SERIAL.h"


void USART_CONF() {
    // Configuración de los registros para la comunicación USART
    TXSTAbits.SYNC = 0; // Modo asíncrono 
    TXSTAbits.BRGH = 1;
    BAUDCTLbits.BRG16 = 1;
    SPBRG = 207;
    SPBRGH =0;
    RCSTAbits.SPEN = 1; // Habilita USART
    RCSTAbits.RX9 = 0; // Recepción de 8 bits
    RCSTAbits.CREN = 1;
    TXSTAbits.TXEN = 1; // Transmisión de 8 bits
}