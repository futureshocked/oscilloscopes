/*  07. Arduino PWM oscilloscope demo sketch 
 * 
 * Use this sketch to experiment with the measurement of a PWM waveform
 * on an oscilloscope.
 * 
 * Connect CHA of the oscilloscope to the anode of the LED.
 * 
 * Use a potentiometer to control the duty cycle.
 * 
 * Set triggering to Auto, and start the experiment.
 * 
 * Automatically measure duty cycle, width, frequency and period for the PWM waveform.
 * 
 * Turn on the cursor in auto more and use it to highlight each of the measurements.
 * 
 * This sketch was written for Oscilloscopes for Busy People by Peter Dalmaris.
 * Find out more at https://techexplorations.com/courses/oscilloscopes/
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - 5mm LED
 *  - 220 Ohm resistor
 *  - 10 kOhm potentiometer
 *  - A breadboard
 *  - An oscilloscope (of course)
 *  
 *  Libraries
 *  ---------
 *  - NONE
 *
 * Connections
 * -----------
 * LED: cathode to GND, anode to resistor, resistor to pin 9 (PWM capable)
 * Potentiometer: middle pin to A0, one pin to GND, third pin to 5V
 *   
 * 
 * Other information
 * -----------------
 *  -
 *  Created on September 12 2019 by Peter Dalmaris
 * 
 */

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int potentiometer = A0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  brightness = map(analogRead(potentiometer),0,1023,0,255);
  // set the brightness of pin 9:
  analogWrite(led, brightness);
  Serial.println(brightness);
}
