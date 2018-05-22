/*
 04 - LCD
 
 It shows some of the capabities of the Liquid Crystal library

 Circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * By Chiccodb00 - 28 April 2018
 */

// Import the Liquid Crystal Library
#include <LiquidCrystal.h>

// Initialize the display
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6 ,d7);

void setup() {
  // Set the display size
  lcd.begin(16, 2);
}

void loop() {
  /*
   * Startup message:
   */
  lcd.clear();                  //Clear display
  lcd.print("Welcome to the");  //Print the first row
  lcd.setCursor(0,1);           //Set the cursor at the beginning of the second row
  lcd.print("LCD Demo!");       //Print the second row
  delay(3000);                  //Wait 3 seconds
  /*
   * Cursor example
   */
  lcd.clear();                  //Clear display
  lcd.home();                   //Set the cursor to the upper left corner of the display
  lcd.print("cursor()");        //Print the first row
  lcd.setCursor(0,1);           //Set the cursor at the beginning of the second row
  lcd.print("2 sec wait");      //Print the second row
  lcd.cursor();                 //Display cursor
  delay(2000);                  //Wait 2 seconds
  lcd.clear();                  //Clear display
  lcd.home();                   //Set the cursor to the upper left corner of the display
  lcd.print("noCursor()");      //Print the first row
  lcd.setCursor(0,1);           //Set the cursor at the beginning of the second row
  lcd.print("2 sec wait");      //Print the second row
  lcd.noCursor();               //Hide cursor
  delay(2000);                  //Wait 2 seconds
  /*
   * Blink example
   */
  lcd.clear();                  //Clear display
  lcd.home();                   //Set the cursor to the upper left corner of the display
  lcd.print("Blink()");         //Print the first row
  lcd.setCursor(0,1);           //Set the cursor at the beginning of the second row
  lcd.print("2 sec wait");      //Print the second row
  lcd.blink();                  //Start blinking
  delay(2000);                  //Wait 2 seconds
  lcd.clear();                  //Clear display
  lcd.home();                   //Set the cursor to the upper left corner of the display
  lcd.print("noBlink()");      //Print the first row
  lcd.setCursor(0,1);           //Set the cursor at the beginning of the second row
  lcd.print("2 sec wait");      //Print the second row
  lcd.noBlink();                //Stop blinking
  delay(2000);                  //Wait 2 seconds
  /*
   * Show/hide display example
   */
  lcd.clear();                  //Clear display
  lcd.home();                   //Set the cursor to the upper left corner of the display
  lcd.print("noDisplay()");     //Print the first row
  lcd.setCursor(0,1);           //Set the cursor at the beginning of the second row
  lcd.print("in 2 sec");        //Print the second row
  delay(2000);                  //Wait 2 seconds
  lcd.noDisplay();              //Hide display
  delay(2000);                  //Wait 2 seconds
  lcd.clear();                  //Clear display
  lcd.home();                   //Set the cursor to the upper left corner of the display
  lcd.print("display()");       //Print the first row
  lcd.setCursor(0,1);           //Set the cursor at the beginning of the second row
  lcd.print("2 sec wait");      //Print the second row
  lcd.display();                //Show display
  delay(2000);                  //Wait 2 seconds
  /*
   * Clear display example
   */
  lcd.clear();                  //Clear display
  lcd.home();                   //Set the cursor to the upper left corner of the display
  lcd.print("clear()");         //Print the first row
  lcd.setCursor(0,1);           //Set the cursor at the beginning of the second row
  lcd.print("in 2 sec");        //Print the second row
  delay(2000);                  //Wait 2 seconds
  lcd.clear();                  //Clear display
  delay(2000);                  //Wait 2 seconds
}
