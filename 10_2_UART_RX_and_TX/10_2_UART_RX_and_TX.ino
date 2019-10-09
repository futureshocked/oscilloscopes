/*  11.2. Arduino UART receive/transmit ASCII characted and decode with an oscilloscope demo sketch 
 * 
 * Use this sketch to experiment with the decoding of an ASCII character
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

byte incomingByte = 0; // for incoming serial data

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600,SERIAL_8N1);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    Serial.write(incomingByte); // This is the data we'll send to the PC. We'll include it in a single packet.
//    Serial.write(0x0A); // Use hex 0A as the packet end. This can be picked up by the Rigol.
                        // Alternative packet end bytes are 0x20 (space), 0x0D (CR), 0x0A (LF), FF, and 0x00 (NULL)
  }
}
