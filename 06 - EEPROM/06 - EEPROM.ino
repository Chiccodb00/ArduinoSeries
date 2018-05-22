/* 06 - EEPROM
 *  
 * It show some capabilities of the EEPROM library.
 * 
 * It reads and write some data to the EEPROM
 * Please note, that the write method is not used to preserve EEPROM life
 * 
 * by Chiccodb00 - 21 may 2018
 */

#include <EEPROM.h>

void setup(){
  //Nothing to setup
}

void loop(){
  //Read the first byte of the EEPROM
  byte firstByte = EEPROM.read(0);
  //Update the first byte with the value "C"
  EEPROM.update(0,'C');
  //EEPROM.write(0,'C'); //Same using the write method
  //Wait a second
  delay(1000);
}

