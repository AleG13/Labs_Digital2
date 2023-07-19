#include "ReadPin.h"
#include <xc.h>
#include <stdint.h>

int digitalRead(int pin,char port){
    int data;
   switch(port){
      case('B'):
        if(pin == 0){
           data = PORTBbits.RB0; 
        } 
        else if(pin == 1){
           data = PORTBbits.RB1;  
        }
        else if(pin == 2){
           data = PORTBbits.RB2;  
        }
        else if(pin == 3){
           data = PORTBbits.RB3; 
        }
        else if(pin == 4){
           data = PORTBbits.RB4; 
        }
        else if(pin == 5){
           data = PORTBbits.RB5; 
        }
        else if(pin == 6){
           data = PORTBbits.RB6; 
        }
        else if(pin == 7){
           data = PORTBbits.RB7; 
        }
        break;
       
     }
   return data;
 
}