/* Infrared Drone Peripheral Control
 * Allows an Apple infrared remote to control custom peripheral functions
 * on an Oakwood Robotics Club drone or SalgaDrone.
 * coded by Matthew McClain
 * Version 0.1
 * Copyright 2016 Oakwood Robotics Club
 * 
 * * * * * IMPORTANT LIBRARY INFORMATION: * * * * *
 * This code REQUIRES the use of the IRremote library, which can be found here:
 * <https://github.com/z3t0/Arduino-IRremote>
 * 
 * FOR THIS LIBRARY ONLY, A PREEXISTING ARDUINO LIBRARY MUST BE DELETED. MAKE
 * SURE TO SEE STEP 5 OF THE INSTALLATION INSTRUCTIONS ON THE LIBRARY'S README
 * ON THE GITHUB PAGE.
 * 
 * For additional information on installing libraries, look here:
 * <https://www.arduino.cc/en/Guide/Libraries>
 * 
 * For more information on how to make use of the IR library, look here:
 * <https://learn.sparkfun.com/tutorials/ir-communication>
 * 
 * SETUP:
 *  Connect IR Reciever to pin 11
 *  Connect motor to pin 10
 *  
 *  VERSION HISTORY:
 *  
 *  0.1:
 *    + pin variable declarations and IR codes
 *    + irrecv and decode_results objects
 *    + setup of basic IR sensing commands
 *    + switch statement to perform a specific action based on code recieved
 *    + created dropConfetti() and added testing code
 */

#include <IRremote.h>

// VARIABLES
// Pins
const int RECV_PIN = 11; // IR reciever data pin
const int ledPin = 13; // Onboard LED for testing
const int servoPin = 10; // Storage bay-opening servo

// Remote Button Hexadecimal IR Codes
const int playButton = 0x77E120D8;
const int plusButton = 0x77E1D0D8;
const int minusButton = 0x77E1B0D8;
const int rewindButton = 0x77E110D8;
const int forwardButton = 0x77E1E0D8;
const int menuButton = 0x77E140D8;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  irrecv.enableIRIn();
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  if (irrecv.decode(&results)) { // if IR reciever recieves data
    switch (results.value) { // determine button pressed from code recieved
      case playButton: dropConfetti(); break;
      case plusButton: break;
      case minusButton: break;
      case rewindButton: break;
      case forwardButton: break;
      case menuButton: testBlink(); break;
    }
  }
}

void dropConfetti() { // Drop confetti from the confetti module
  // To do: write final code
}

void testBlink() { // Blinks onboard LED five times
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}
