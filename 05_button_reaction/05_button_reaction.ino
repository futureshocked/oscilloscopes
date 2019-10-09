/*  05. Arduino button oscilloscope demo sketch 
 * 
 * Use this sketch to see a button press as a waveform event in the
 * oscilloscope.
 * 
 * Connect CHA of the oscilloscope to the button signal pin.
 * 
 * Connect CHB to the anode of an LED.
 * 
 * Set the scope to 5us time scale and 200mV voltage scale.
 * 
 * Set triggering to Edge, downslope (because we use the internal
 * pull-up resistor), and start the experiment.
 * 
 * There is not much to measure in this experiment, but you can see 
 * how the LED wavefore goes to HIGH after the button is pressed and the
 * down-slope edge is detected.
 * 
 * You can measure how long it takes for the Arduino to turn on
 * the LED. Use the horizontal cursors for this. 
 * 
 * Notice how the reaction time of the arduino varies, around 8us.
 * 
 * 
 * This sketch was written for Oscilloscopes for Busy People by Peter Dalmaris. 
 * Find out more at https://techexplorations.com/courses/oscilloscopes/
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - 5mm LED
 *  - 220 Ohm resistor
 *  - Momentary button
 *  - A breadboard
 *  - An oscilloscope (of course)
 *  
 *  Libraries
 *  ---------
 *  - NONE
 *
 * Connections
 * -----------
 * LED: cathode to GND, anode to resistor, resistor to pin 13
 * Button: One pin to Arduino pin 2, second pin to GND. Use the Arduino
 * internal pull-up resistor to save an external resistor.
 *   
 * 
 * Other information
 * -----------------
 *  -
 *  Created on September 16 2019 by Peter Dalmaris
 * 
 */
 
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);       // turn on pullup resistor
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
