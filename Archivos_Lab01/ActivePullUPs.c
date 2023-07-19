#include "activePullUps.h"
#include <xc.h>
#include <stdint.h>

int ActivePullUps(int pin){
    //CONFIGURACIÓN DE PULL UPS
    OPTION_REGbits.nRBPU = 0;
    switch(pin){
        case(0):
            WPUBbits.WPUB0 = 1;
            IOCBbits.IOCB0 = 1;
            break;
        case(1):
            WPUBbits.WPUB1 = 1;
            IOCBbits.IOCB1 = 1;
            break;
        case(2):
            WPUBbits.WPUB2 = 1;
            IOCBbits.IOCB2 = 1;
            break;
        case(3):
            WPUBbits.WPUB3 = 1;
            IOCBbits.IOCB3 = 1;
            break;
        case(4):
            WPUBbits.WPUB4 = 1;
            IOCBbits.IOCB4 = 1;
            break;
        case(5):
            WPUBbits.WPUB5 = 1;
            IOCBbits.IOCB5 = 1;
            break;
        case(6):
            WPUBbits.WPUB6 = 1;
            IOCBbits.IOCB6 = 1;
            break;
        case(7):
            WPUBbits.WPUB7 = 1;
            IOCBbits.IOCB7 = 1;
            break;
    }
   
    
}