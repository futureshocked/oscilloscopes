/*  11. Arduino with BME280 I2C example sketch
 * 
 * Use this sketch to experiment with the decoding of I2C communication on an oscilloscope.
 * 
 * Connect CH1 of the oscilloscope to SCL.
 * Connect CH2 of the oscilloscope to SDA.
 * 
 * 
 * This sketch was written for Oscilloscopes for Busy People by Peter Dalmaris.
 * Find out more at https://techexplorations.com/courses/oscilloscopes/
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - BME280 sensor
 *  - A breadboard
 *  - An oscilloscope (of course)
 *  
 *  Libraries
 *  ---------
 *  - BlueDot_BME280.h
 *  - Wire.h
 *
 * Connections
 * -----------
 * BME280: SDA (sensor) to SDA (Arduino), SCL (sensor) to SCL (Arduino), Vin to 5V, GND to GND
 *   
 * 
 * Other information
 * -----------------
 *  -
 *  Created on September 12 2019 by Peter Dalmaris
 * 
 */

#include <Wire.h>
#include "BlueDot_BME280.h"

BlueDot_BME280 bme;                                     //Object for Sensor

int bmeDetected = 0;                                    //Checks if Sensor is available


void setup() {
  Serial.begin(9600);
  Serial.println(F("Basic Weather Station"));

  //*********************************************************************
  //*************BASIC SETUP - SAFE TO IGNORE****************************

  //This program is set for the I2C mode

  bme.parameter.communication = 0;                    //I2C communication for Sensor



  //*********************************************************************
  //*************BASIC SETUP - SAFE TO IGNORE****************************

  //Set the I2C address of your breakout board

  bme.parameter.I2CAddress = 0x76;                    //I2C Address for Sensor



  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************

  //Now choose on which mode your device will run
  //On doubt, just leave on normal mode, that's the default value

  //0b00:     In sleep mode no measurements are performed, but power consumption is at a minimum
  //0b01:     In forced mode a single measured is performed and the device returns automatically to sleep mode
  //0b11:     In normal mode the sensor measures continually (default value)

  bme.parameter.sensorMode = 0b11;                    //Setup Sensor mode for Sensor



  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************

  //Great! Now set up the internal IIR Filter
  //The IIR (Infinite Impulse Response) filter suppresses high frequency fluctuations
  //In short, a high factor value means less noise, but measurements are also less responsive
  //You can play with these values and check the results!
  //In doubt just leave on default

  //0b000:      factor 0 (filter off)
  //0b001:      factor 2
  //0b010:      factor 4
  //0b011:      factor 8
  //0b100:      factor 16 (default value)

  bme.parameter.IIRfilter = 0b100;                   //IIR Filter for Sensor



  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************

  //Next you'll define the oversampling factor for the humidity measurements
  //Again, higher values mean less noise, but slower responses
  //If you don't want to measure humidity, set the oversampling to zero

  //0b000:      factor 0 (Disable humidity measurement)
  //0b001:      factor 1
  //0b010:      factor 2
  //0b011:      factor 4
  //0b100:      factor 8
  //0b101:      factor 16 (default value)

  bme.parameter.humidOversampling = 0b101;            //Humidity Oversampling for Sensor



  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************

  //Now define the oversampling factor for the temperature measurements
  //You know now, higher values lead to less noise but slower measurements

  //0b000:      factor 0 (Disable temperature measurement)
  //0b001:      factor 1
  //0b010:      factor 2
  //0b011:      factor 4
  //0b100:      factor 8
  //0b101:      factor 16 (default value)

  bme.parameter.tempOversampling = 0b101;              //Temperature Oversampling for Sensor



  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************

  //Finally, define the oversampling factor for the pressure measurements
  //For altitude measurements a higher factor provides more stable values
  //On doubt, just leave it on default

  //0b000:      factor 0 (Disable pressure measurement)
  //0b001:      factor 1
  //0b010:      factor 2
  //0b011:      factor 4
  //0b100:      factor 8
  //0b101:      factor 16 (default value)

  bme.parameter.pressOversampling = 0b101;             //Pressure Oversampling for Sensor

  //

  //*********************************************************************
  //*************ADVANCED SETUP IS OVER - LET'S CHECK THE CHIP ID!*******

  if (bme.init() != 0x60)
  {
    Serial.println(F("Ops! Second BME280 Sensor not found!"));
    bmeDetected = 0;
  }

  else
  {
    Serial.println(F("Second BME280 Sensor detected!"));
    bmeDetected = 1;
  }

  if (bmeDetected == 0)
  {
    Serial.println();
    Serial.println();
    Serial.println(F("Troubleshooting Guide"));
    Serial.println(F("*************************************************************"));
    Serial.println(F("1. Let's check the basics: Are the VCC and GND pins connected correctly? If the BME280 is getting really hot, then the wires are crossed."));
    Serial.println();
    Serial.println(F("2. Did you connect the SDI pin from your BME280 to the SDA line from the Arduino?"));
    Serial.println();
    Serial.println(F("3. And did you connect the SCK pin from the BME280 to the SCL line from your Arduino?"));
    Serial.println();
    Serial.println(F("4. One of your sensors should be using the alternative I2C Address(0x76). Did you remember to connect the SDO pin to GND?"));
    Serial.println();
    Serial.println(F("5. The other sensor should be using the default I2C Address (0x77. Did you remember to leave the SDO pin unconnected?"));

    Serial.println();

    while (1);
  }

  Serial.println();
  Serial.println();

}

void loop() {

  if (bmeDetected)
  {
    // Read the temperature registers
//    Serial.print(F("Temperature Sensor (Reg. FA, FB, FC) [°C]:\t\t"));
//    Serial.println(bme.readTempC());

    // Read the humidity registers
        Serial.print(F("Humidity Sensor (Reg. FD, FE) [%]:\t\t\t"));
        Serial.println(bme.readHumidity());
  }

  else
  {
    Serial.print(F("Temperature Sensor [°C]:\t\t"));
    Serial.println(F("Null"));
    Serial.print(F("Humidity Sensor  [%]:\t\t\t"));
    Serial.println(F("Null"));
  }

  Serial.println();
  Serial.println();

  delay(1000);


}
