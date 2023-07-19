#include "ADC.h"
#include "display.h"
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

int diplay = 0b00000000;
int izquierda;
int derecha;

int obtener_valores(unsigned int adc_val, int val){
    derecha = adc_val & 0x0f;
    izquierda =  (adc_val >> 4) & 0x0F;
    
    if (val == 0){
    switch(izquierda){
        case(0):
            diplay = 0b01000000;
            break;
        case(1):
            diplay = 0b01111001;
            break;
        case(2):
            diplay = 0b00100100;
            break;
        case(3):
            diplay = 0b00100100;
            break;
        case(4):
            diplay = 0b00011001;
            break;
        case(5):
            diplay = 0b00010010;
            break;
        case(6):
            diplay = 0b00000010;
            break;
        case(7):
            diplay = 0b01111000;
            break;
        case(8):
            diplay = 0b00000000;
            break;
        case(9):
            diplay = 0b00010000;
            break;
        case(10):
            diplay = 0b00001000;
            break;
        case(11):
            diplay = 0b00000011;
            break;
        case(12):
            diplay = 0b01000110;
            break;
        case(13):
            diplay = 0b00100001;
            break;
        case(14):
            diplay = 0b00000110;
            break;
        case(15):
            diplay = 0b00001110;
            break;
    
    }
    }
    if (val == 1){
    switch(derecha){
        case(0):
            diplay = 0b01000000;
            break;
        case(1):
            diplay = 0b01111001;
            break;
        case(2):
            diplay = 0b00100100;
            break;
        case(3):
            diplay = 0b00100100;
            break;
        case(4):
            diplay = 0b00011001;
            break;
        case(5):
            diplay = 0b00010010;
            break;
        case(6):
            diplay = 0b00000010;
            break;
        case(7):
            diplay = 0b01111000;
            break;
        case(8):
            diplay = 0b00000000;
            break;
        case(9):
            diplay = 0b00010000;
            break;
        case(10):
            diplay = 0b00001000;
            break;
        case(11):
            diplay = 0b00000011;
            break;
        case(12):
            diplay = 0b01000110;
            break;
        case(13):
            diplay = 0b00100001;
            break;
        case(14):
            diplay = 0b00000110;
            break;
        case(15):
            diplay = 0b00001110;
            break;
    
    }
    }

   return diplay;
}