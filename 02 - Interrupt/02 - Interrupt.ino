/*   02 - Interupt
 *   
 *   It changes led blink speed when pressing a button.
 *   
 *   It requires a button attached to pin 2 and a led attached to pin 13
 * 
 *   By Chiccodb00 - 26 march 2018
 */

/* PINs DEFINITION */
const byte led = 13;
const byte interruptPin = 2;
/* BLINK SPEED DEFINITION */
const int fastBlinkSpeed = 500;
const int slowBlinkSpeed = 1000;
volatile boolean blinkFast = false;                                          //If true it blinks faster - Change by interrupt
/* TIME AND PIN STATUS TRACKING */
long timeChange = 0;
boolean ledStatus = false;

void setup() {
  /* SET PINs TO INPUT OR OUTPUT */
  pinMode(led, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), changeSpeed, RISING); //Attach interrupt to call the changeSpeed method when value is changing
}

void loop() {
  //This is a way to avoid using the delays
  if(timeChange <= millis()){
    //Invert the led status and turn it on or off based on ledStatus variable
    ledStatus = !ledStatus;
    digitalWrite(led, ledStatus);
    if(blinkFast) timeChange = millis() + fastBlinkSpeed;
    else          timeChange = millis() + slowBlinkSpeed;
  }
}

// Method called by interrupt for change blink speed
void changeSpeed(){
  blinkFast = !blinkFast;
}

