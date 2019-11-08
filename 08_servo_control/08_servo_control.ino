/*  08. Arduino servo control oscilloscope demo sketch 
 * 
 * Use this sketch to experiment with the measurement of a PWM waveform
 * used to control a servo motor on an oscilloscope.
 * 
 * Connect CH1 of the oscilloscope to pin 9 that controls the servo.
 * 
 * Use a potentiometer to control the duty cycle and therefore the position of the
 * servo.
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
 *  - 10 kOhm potentiometer
 *  - A mini servo motor
 *  - A breadboard
 *  - An oscilloscope (of course)
 *  
 *  Libraries
 *  ---------
 *  - NONE
 *
 * Connections
 * -----------
 * Servo: brown to GND, orange to 5V, yellow to 9.
 * Potentiometer: middle pin to A0, one pin to GND, third pin to 5V
 *   
 * 
 * Other information
 * -----------------
 *  -
 *  Created on September 12 2019 by Peter Dalmaris
 * 
 */

#include <Servo.h> 
Servo myservo1;

int servo_pin = 9;
int pos = 0;    // variable to store the servo position 
int potentiometer = A0;

void setup() {
  myservo1.attach(servo_pin);
  
}

void loop() {
  pos = map(analogRead(potentiometer),0,1023,0,180);
  myservo1.write(pos);
}
