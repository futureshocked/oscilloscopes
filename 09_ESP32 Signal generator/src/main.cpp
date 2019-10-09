// With this program, you can use the ESP32 as an ultra-low cost signal generator.
// To learn more, see https://techexplorations.com/courses/oscilloscopes/

#include <Arduino.h>
#include "waveforms.h"

int i = 0;
int sample_delay = 0;
const byte POT_GPIO = 35; // Potentiometer
int   t_sample;

const byte output_pin = 25;
const byte buttonPin = 14;
int waveformID = 0;
volatile int interruptCounter = 0;

// Debouncing parameters
long debouncing_time = 1000; //Debouncing Time in Milliseconds
volatile unsigned long last_micros;

portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR handleInterrupt() {
  portENTER_CRITICAL_ISR(&mux);
   if((long)(micros() - last_micros) >= debouncing_time * 1000) {
    interruptCounter++;
  }
  last_micros = micros();
  portEXIT_CRITICAL_ISR(&mux);
}

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);  // Using an extarnal pull up instead of internal
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, FALLING);
}

void loop() {

  if(interruptCounter>0){

      portENTER_CRITICAL(&mux);
      interruptCounter--;
      portEXIT_CRITICAL(&mux);

      waveformID++;
      if (waveformID == maxWaveform)
        waveformID = 0;

      sample_delay = map(analogRead(POT_GPIO), 0, 4095, 0, 100);

      Serial.print("Waveform ID: ");
      Serial.print(waveformID);
      Serial.print(", delay: ");
      Serial.println(sample_delay);
  }

  dacWrite(output_pin, waveformsTable[waveformID][i]);

  i++;

  if (i == maxSamplesNum) // Reset the counter to repeat the wave
    i = 0;

  delayMicroseconds(sample_delay);  // Hold the sample value for the sample time

}
