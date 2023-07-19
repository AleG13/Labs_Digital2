#include "interup.h"
#include <xc.h>
#include <stdint.h>

void ActiveInterrup(void){
    // Configurar interrupciones externas en el puerto B
    INTCONbits.GIE = 1;
    INTCONbits.RBIE = 1;
    INTCONbits.PEIE = 1; 
}