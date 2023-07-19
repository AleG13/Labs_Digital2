#include "ADC.h"
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

void adc_init(int channel){
    PIR1bits.ADIF = 0;
    PIE1bits.ADIE = 1;
    ADCON0bits.ADCS = 0b10;
    ADCON0bits.CHS = channel;
    __delay_ms(1);
    ADCON1bits.ADFM = 1;
    ADCON1bits.VCFG0 = 0;
    ADCON1bits.VCFG1 = 0;
    ADCON0bits.ADON = 1;
    PIR1bits.ADIF = 0;
}
unsigned int adc_read() {  
    return (ADRESL);  
}
void adc_change_channel(int channe2){
    ADCON0bits.CHS = channe2;
}
int adc_get_channel(){
    return ADCON0bits.CHS;
}