#ifndef ADC.h
#define ADC.h
#include <xc.h>
// Prototipo de las funciones
void adc_init(int channel);
unsigned int adc_read ();
void adc_change_channel(int channe2);
int adc_get_channel();
#endif
