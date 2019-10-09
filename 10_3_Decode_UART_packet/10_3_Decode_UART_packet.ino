/*  11.3. Arduino UART receive/transmit a packet and decode with an oscilloscope demo sketch 
 * 
 * Use this sketch to experiment with the decoding of a multi-byte packet
 * that is received and transmitted by an Arduino on an oscilloscope.
 * 
 * Use in tandem with the matching Processing sketch
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

void setup() {
  // initialize serial:
  Serial.begin(9600);

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next byte in the incoming serial stream:
    byte a_byte = Serial.read();

    // print the byte:
    Serial.write(a_byte);
  }
}
