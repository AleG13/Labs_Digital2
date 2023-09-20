
const int ledPinR =  RED_LED;      // the number of the LED pin
const int ledPinG =  GREEN_LED;      // the number of the LED pin

// Variables will change:
int ledStateR = LOW;             // ledState used to set the LED
int ledStateB = LOW;             // ledState used to set the LED
int ledStateG = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
const int buttonPin = PUSH2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;   

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPinR, OUTPUT); 
  pinMode(ledPinG, OUTPUT); 
    pinMode(buttonPin, INPUT_PULLUP);     
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.
 buttonState = digitalRead(buttonPin);
  // check to see if it's time to blink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED.
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledStateR == HIGH){
            if(ledStateG == LOW){
            ledStateR = HIGH;
            ledStateG = HIGH;
            delay(3000);
            }
            else{
            ledStateR = LOW;
            ledStateG = HIGH;
            delay(3000); 
            }
    }
    else{
      ledStateR = HIGH;
      ledStateG = LOW;
      delay(3000); 
      }
    

    // set the LED with the ledState of the variable:
    digitalWrite(ledPinG, ledStateG);
    digitalWrite(ledPinR, ledStateR);
    
   
  
    
  }
}
