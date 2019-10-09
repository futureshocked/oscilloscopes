/*  06. Ultrasonic distance sensor HC-SR04 demo sketch 
 * 
 * This sketch calculates the distance between the HC-SR04 sensor and
 * an object directly infront of it.
 * 
 * To see the trigger and echo waveforms with your oscilloscope,
 * connect CHA to the trigger and CHB to the echo pins.
 * 
 * Set up edge trigger to CHA, and set it to 1V (or there about).
 * 
 * Try a single sweep and see the waveforms in the display.
 * 
 * Try new sweeps, and each time change the distance of the target
 * from the sensor. The width of the wavefore in CHB should vary,
 * depending on the target distance.
 * 
 * Mesure the width of the waveform in CHB, and confirm it matches
 * the distance of the sensor.
 * 
 * This sketch was written for Oscilloscopes for Busy People by Peter Dalmaris.
 * Find out more at https://techexplorations.com/courses/oscilloscopes/
 * 
 * Original: https://github.com/futureshocked/ArduinoSbS2017/blob/master/_0510_-_Ultrasonic_Distance_Sensor/_0510_-_Ultrasonic_Distance_Sensor.ino
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - HC-SR04 sensor
 *  
 *  Libraries
 *  ---------
 *  - NONE
 *
 * Connections
 * -----------
 *  Break out    |    Arduino Uno
 *  -----------------------------
 *      VCC      |      5V
 *      GND      |      GND
 *      Echo     |      12
 *      Trig     |      13
 *   
 * 
 * Other information
 * -----------------
 *  For information on the ultrasonic transducer: https://en.wikipedia.org/wiki/Ultrasonic_transducer
 *  For information on ultrasounds: https://en.wikipedia.org/wiki/Ultrasound
 *  HC-SR04 datasheet: https://docs.google.com/document/d/1Y-yZnNhMYy7rwhAgyL_pfa39RsB-x2qR4vP8saG73rE
 *  Information about the pulseIn function: https://www.arduino.cc/en/Reference/PulseIn
 *  
 *  Created on September 12 2019 by Peter Dalmaris
 * 
 */

#define trigPin 13
#define echoPin 12

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.print(" cm, ");
    Serial.print(duration);
    Serial.println(" us");
  }
  delay(500);
}
