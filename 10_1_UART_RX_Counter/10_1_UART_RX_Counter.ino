/*  11.1. Arduino UART receive integer oscilloscope demo sketch 
 * 
 * Use this sketch to experiment with the decoding of a single  
 * integer in simplex on an oscilloscope.
 * 
 * Connect CH1 of the oscilloscope to pin 0 of the Arduino.
 * Connect CH2 of the oscilloscope to pin 1 of the Arduino.
 * 
 * 
 * This sketch was written for Oscilloscopes for Busy People by Peter Dalmaris.
 * Find out more at https://techexplorations.com/courses/oscilloscopes/
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - An oscilloscope (of course)
 *  
 *  Libraries
 *  ---------
 *  - NONE
 *
 * Connections
 * -----------
 * 
 *   
 * 
 * Other information
 * -----------------
 *  -
 *  Created on September 12 2019 by Peter Dalmaris
 * 
 */
 
int counter = 0;

void setup() {
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
      Serial.println(counter, DEC);
      delay(1000);
      counter++;
}
