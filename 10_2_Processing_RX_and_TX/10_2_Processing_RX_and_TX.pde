import processing.serial.*;

Serial myPort;      // The serial port
int whichKey = -1;  // Variable to hold keystoke values
int inByte = -1;    // Incoming serial data

void setup() {
  size(400, 300);
  // create a font with the third font available to the system:
  PFont myFont = createFont(PFont.list()[2], 14);
  textFont(myFont);

  // List all the available serial ports:
  printArray(Serial.list());

  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // In Windows, this usually opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[7];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(0);
  text("Last Received (hex): " + hex(inByte), 10, 100);
  text("Last Received (dec): " + inByte, 10, 120);
  text("Last Received (char): " + char(inByte), 10, 140);
  text("Last Sent (hex): " + hex(whichKey), 10, 160);
  text("Last Sent (dec): " + whichKey, 10, 180);
  text("Last Sent (char): " + char(whichKey), 10, 200);
}

void serialEvent(Serial myPort) {
  inByte = myPort.read();
}

void keyPressed() {
  // Send the keystroke out:
  myPort.write(key);
  whichKey = key;
}
