
// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = PUSH1;     // the number of the pushbutton pin
const int buttonPin2 = PUSH2;     // the number of the pushbutton pin
const int ledPin1 =  3;      // the number of the LED pin
const int ledPin2 =  4;      // the number of the LED pin
const int ledPin3 =  5;      // the number of the LED pin
const int ledPin4 =  6;      // the number of the LED pin
const int ledPin5 =  7;      // the number of the LED pin
const int ledPin6 =  8;      // the number of the LED pin
const int ledPin7 =  9;      // the number of the LED pin
const int ledPin8 =  10;      // the number of the LED pin

const int ledPin9 =  11;      // the number of the LED pin
const int ledPin10 =  12;      // the number of the LED pin
const int ledPin11 =  13;      // the number of the LED pin
const int ledPin12 =  14;      // the number of the LED pin
const int ledPin13 =  15;      // the number of the LED pin
const int ledPin14 =  36;      // the number of the LED pin
const int ledPin15 =  37;      // the number of the LED pin
const int ledPin16 =  18;      // the number of the LED pin

const int ledPinR =  RED_LED;      // the number of the LED pin
const int ledPinG =  GREEN_LED;      // the number of the LED pin
const int ledPinB =  BLUE_LED;      // the number of the LED pin
int cont = 0;
int cont2 = 0;
int ganador2 = 0;
int ganador1 = 0;
int ledStateR = LOW;             // ledState used to set the LED
int ledStateB = LOW;             // ledState used to set the LED
int ledStateG = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated


// variables will change:
int buttonState = 0;   
int buttonState2 = 0;  
int bandera = 0;
int bandera2 = 0;
// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)



void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinR, OUTPUT); 
  pinMode(ledPinG, OUTPUT); 
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);        
  pinMode(ledPin1, OUTPUT);  
  pinMode(ledPin2, OUTPUT); 
  pinMode(ledPin3, OUTPUT); 
  pinMode(ledPin4, OUTPUT); 
  pinMode(ledPin5, OUTPUT); 
  pinMode(ledPin6, OUTPUT); 
  pinMode(ledPin7, OUTPUT); 
  pinMode(ledPin8, OUTPUT);   
  pinMode(ledPin9, OUTPUT);  
  pinMode(ledPin10, OUTPUT); 
  pinMode(ledPin11, OUTPUT); 
  pinMode(ledPin12, OUTPUT); 
  pinMode(ledPin13, OUTPUT); 
  pinMode(ledPin14, OUTPUT); 
  pinMode(ledPin15, OUTPUT); 
  pinMode(ledPin16, OUTPUT);      
  pinMode(ledPinR, OUTPUT); 
  pinMode(ledPinG, OUTPUT);    
  pinMode(ledPinB, OUTPUT);
}

void loop(){


   if(bandera == 0){
   if (ledStateR == HIGH ){
            if(ledStateG == LOW){
            ledStateR = HIGH;
            ledStateG = HIGH;
            delay(3000);
            }
            else{
            ledStateR = LOW;
            ledStateG = HIGH;
            delay(3000); 
            bandera = 1;
            }
    }
    else{
      ledStateR = HIGH;
      ledStateG = LOW;
      delay(3000); 
      }  
   }
 

    // set the LED with the ledState of the variable:
    digitalWrite(ledPinG, ledStateG);
    digitalWrite(ledPinR, ledStateR);
    digitalWrite(ledPinB, ledStateB);
    
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW && bandera2 == 0) {   
      while(digitalRead(buttonPin) == LOW);
      cont = cont + 1;  
  } 
  if (buttonState2 == LOW && bandera2 == 0) {   
      while(digitalRead(buttonPin2) == LOW);
      cont2 = cont2 + 1;  
  } 

  switch(cont){
    case 1:
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin5,LOW);
    digitalWrite(ledPin6,LOW);
    digitalWrite(ledPin7,LOW);
    digitalWrite(ledPin8,LOW);
  
    break;
    case 2:
     digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin5,LOW);
    digitalWrite(ledPin6,LOW);
    digitalWrite(ledPin7,LOW);
    digitalWrite(ledPin8,LOW);
    break;
    case 3:
     digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,HIGH);
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin5,LOW);
    digitalWrite(ledPin6,LOW);
    digitalWrite(ledPin7,LOW);
    digitalWrite(ledPin8,LOW);
    break;
    case 4:
     digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,HIGH);
    digitalWrite(ledPin5,LOW);
    digitalWrite(ledPin6,LOW);
    digitalWrite(ledPin7,LOW);
    digitalWrite(ledPin8,LOW);
    break;
    case 5:
     digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin5,HIGH);
    digitalWrite(ledPin6,LOW);
    digitalWrite(ledPin7,LOW);
    digitalWrite(ledPin8,LOW);
    break;
    case 6:
     digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin5,LOW);
    digitalWrite(ledPin6,HIGH);
    digitalWrite(ledPin7,LOW);
    digitalWrite(ledPin8,LOW);
    break;
    case 7:
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin5,LOW);
    digitalWrite(ledPin6,LOW);
    digitalWrite(ledPin7,HIGH);
    digitalWrite(ledPin8,LOW);
    break;
    case 8:
     digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin5,LOW);
    digitalWrite(ledPin6,LOW);
    digitalWrite(ledPin7,LOW);
    digitalWrite(ledPin8,HIGH);
    ganador1 = 1;
    break;
    
  }
  switch(cont2){
    case 1:
    digitalWrite(ledPin9,HIGH);
    digitalWrite(ledPin10,LOW);
    digitalWrite(ledPin11,LOW);
    digitalWrite(ledPin12,LOW);
    digitalWrite(ledPin13,LOW);
    digitalWrite(ledPin14,LOW);
    digitalWrite(ledPin15,LOW);
    digitalWrite(ledPin16,LOW);
  
    break;
    case 2:
     digitalWrite(ledPin9,LOW);
    digitalWrite(ledPin10,HIGH);
    digitalWrite(ledPin11,LOW);
    digitalWrite(ledPin12,LOW);
    digitalWrite(ledPin13,LOW);
    digitalWrite(ledPin14,LOW);
    digitalWrite(ledPin15,LOW);
    digitalWrite(ledPin16,LOW);
    break;
    case 3:
    digitalWrite(ledPin9,LOW);
    digitalWrite(ledPin10,LOW);
    digitalWrite(ledPin11,HIGH);
    digitalWrite(ledPin12,LOW);
    digitalWrite(ledPin13,LOW);
    digitalWrite(ledPin14,LOW);
    digitalWrite(ledPin15,LOW);
    digitalWrite(ledPin16,LOW);
    break;
    case 4:
    digitalWrite(ledPin9,LOW);
    digitalWrite(ledPin10,LOW);
    digitalWrite(ledPin11,LOW);
    digitalWrite(ledPin12,HIGH);
    digitalWrite(ledPin13,LOW);
    digitalWrite(ledPin14,LOW);
    digitalWrite(ledPin15,LOW);
    digitalWrite(ledPin16,LOW);
    break;
    case 5:
    digitalWrite(ledPin9,LOW);
    digitalWrite(ledPin10,LOW);
    digitalWrite(ledPin11,LOW);
    digitalWrite(ledPin12,LOW);
    digitalWrite(ledPin13,HIGH);
    digitalWrite(ledPin14,LOW);
    digitalWrite(ledPin15,LOW);
    digitalWrite(ledPin16,LOW);
    break;
    case 6:
    digitalWrite(ledPin9,LOW);
    digitalWrite(ledPin10,LOW);
    digitalWrite(ledPin11,LOW);
    digitalWrite(ledPin12,LOW);
    digitalWrite(ledPin13,LOW);
    digitalWrite(ledPin14,HIGH);
    digitalWrite(ledPin15,LOW);
    digitalWrite(ledPin16,LOW);
    break;
    case 7:
    digitalWrite(ledPin9,LOW);
    digitalWrite(ledPin10,LOW);
    digitalWrite(ledPin11,LOW);
    digitalWrite(ledPin12,LOW);
    digitalWrite(ledPin13,LOW);
    digitalWrite(ledPin14,LOW);
    digitalWrite(ledPin15,HIGH);
    digitalWrite(ledPin16,LOW);
    break;
    case 8:
    digitalWrite(ledPin9,LOW);
    digitalWrite(ledPin10,LOW);
    digitalWrite(ledPin11,LOW);
    digitalWrite(ledPin12,LOW);
    digitalWrite(ledPin13,LOW);
    digitalWrite(ledPin14,LOW);
    digitalWrite(ledPin15,LOW);
    digitalWrite(ledPin16,HIGH);
    ganador2 = 1;

    break;
  }
  if(ganador2 == 1){
     ledStateB = HIGH;
     ledStateG = LOW;
     bandera2 = 1;
  }
  if(ganador1 == 1){
     ledStateR = HIGH;
     ledStateG = LOW;
     bandera2 = 1;
  }
  }
