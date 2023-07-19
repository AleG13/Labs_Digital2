#include "ConfiPin.h"
#include <xc.h>
#include <stdint.h>

void PinOutput(int pin, char port){
     switch(port){
      case('A'):
        if(pin == 0){
           TRISAbits.TRISA0 = 0;  
        } 
        else if(pin == 1){
           TRISAbits.TRISA1 = 0;  
        }
        else if(pin == 2){
           TRISAbits.TRISA2 = 0;  
        }
        else if(pin == 3){
           TRISAbits.TRISA3 = 0;  
        }
        else if(pin == 4){
           TRISAbits.TRISA4 = 0;  
        }
        else if(pin == 5){
           TRISAbits.TRISA5 = 0;  
        }
        else if(pin == 6){
           TRISAbits.TRISA6 = 0;  
        }
        else if(pin == 7){
           TRISAbits.TRISA7 = 0;  
        }
        else if(pin == 8){
           TRISA = 0;  
        }
        break;
        
        case('D'):
        if(pin == 0){
           TRISDbits.TRISD0 = 0;  
        } 
        else if(pin == 1){
           TRISDbits.TRISD1 = 0;  
        }
        else if(pin == 2){
           TRISDbits.TRISD2 = 0;  
        }
        else if(pin == 3){
           TRISDbits.TRISD3 = 0;  
        }
        else if(pin == 4){
           TRISDbits.TRISD4 = 0;  
        }
        else if(pin == 5){
           TRISDbits.TRISD5 = 0;  
        }
        else if(pin == 6){
           TRISDbits.TRISD6 = 0;  
        }
        else if(pin == 7){
           TRISDbits.TRISD7 = 0;  
        }
        else if(pin == 8){
           TRISD = 0;  
        }
        break;
        
        case('C'):
        if(pin == 0){
           TRISCbits.TRISC0 = 0;  
        } 
        else if(pin == 1){
           TRISCbits.TRISC1 = 0;  
        }
        else if(pin == 2){
           TRISCbits.TRISC2 = 0;  
        }
        else if(pin == 3){
           TRISCbits.TRISC3 = 0;  
        }
        else if(pin == 4){
           TRISCbits.TRISC4 = 0;  
        }
        else if(pin == 5){
           TRISCbits.TRISC5 = 0;  
        }
        else if(pin == 6){
           TRISCbits.TRISC6 = 0;  
        }
        else if(pin == 7){
           TRISCbits.TRISC7 = 0;  
        }
        else if(pin == 8){
           TRISC = 0;  
        }
        break;
       
     }
    
}

void PinInput(int pin, char port){
     switch(port){
      case('B'):
        if(pin == 0){
           TRISBbits.TRISB0 = 1;  
        } 
        else if(pin == 1){
           TRISBbits.TRISB1 = 1;  
        }
        else if(pin == 2){
           TRISBbits.TRISB2 = 1;  
        }
        else if(pin == 3){
           TRISBbits.TRISB3 = 1;  
        }
        else if(pin == 4){
           TRISBbits.TRISB4 = 1;  
        }
        else if(pin == 5){
           TRISBbits.TRISB5 = 1;  
        }
        else if(pin == 6){
           TRISBbits.TRISB6 = 1;  
        }
        else if(pin == 7){
           TRISBbits.TRISB7 = 1;  
        }
        else if(pin == 8){
           TRISB = 1;  
        }
        break;
        
      case('E'):
        if(pin == 0){
           TRISEbits.TRISE0 = 1;  
        } 
        else if(pin == 1){
           TRISEbits.TRISE1 = 1;  
        }
        else if(pin == 2){
           TRISEbits.TRISE2 = 1;  
        }
        else if(pin == 3){
           TRISEbits.TRISE3 = 1;  
        }      
        else if(pin == 4){
           TRISE = 1;  
        }
        break;
       
     }
    
}

