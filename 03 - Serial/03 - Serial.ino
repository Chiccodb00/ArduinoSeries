/*   03 - Serial
 *   
 *   It changes led state when reciving serial data
 *   
 *   It requires a button attached to pin 2 and a led attached to pin 13
 * 
 *   Valid serial commands:
 *   ON      -> Turn Led ON
 *   OFF     -> Turn Led OFF
 *   DISABLE -> Disable serial
 *   
 *   Serial can return:
 *   CLICK!  -> When the button is pressed 
 *   By Chiccodb00 - 02 april 2018
 */

/* PINs DEFINITION */
const byte led = 13;
const byte interruptPin = 2;
/* SERIAL CONSTANTS */
const long serialBaud = 9600;
bool serialConnected = false;

void setup() {
  /* SET PINs TO INPUT OR OUTPUT */
  pinMode(led, OUTPUT);
  pinMode(interruptPin, INPUT);
  /* ATTACH INTERRUPT */
  attachInterrupt(digitalPinToInterrupt(interruptPin), buttonPressed, RISING); //Attach interrupt to call the buttonPressed method when value is changing
  /* INTIALIZE SERIAL */
  Serial.begin(serialBaud);
  serialConnected = true;
}

void loop() {
  // Receive data
  String receivedData = "";
  while(Serial.available() > 0){
    // Read in a loop because Serial.read read only one char at a time
    receivedData.concat((char)Serial.read());
  }
  // Convert String to const char
  const char* receivedChar = receivedData.c_str();
  if(strcmp(receivedChar, "ON")==0){            // Check if the command is "ON"
    digitalWrite(led, HIGH);
  }else if(strcmp(receivedChar, "OFF")==0){     // Check if the command is "OFF"
    digitalWrite(led, LOW);
  }else if(strcmp(receivedChar, "DISABLE")==0){ // Check if the command is "DISABLE"
    Serial.end();
    serialConnected = false;
  }
  // Wait for 10 ms for safety
  delay(10);
}

// Method called by interrupt
void buttonPressed(){
  if(serialConnected){
    Serial.println("CLICK!");
  }
}

