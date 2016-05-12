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
 *  0.2:
 *    + super important irrecv.resume() method run after interpreting code
 *    + servo position setting variables
 *    + new IR codes for new IR remote
 *    + resetServo() to allow greater control of servo position
 *  
 *  0.1:
 *    + pin variable declarations and IR codes
 *    + irrecv and decode_results objects
 *    + setup of basic IR sensing commands
 *    + switch statement to perform a specific action based on code recieved
 *    + created dropConfetti() and added testing code
 */

#include <IRremote.h>
#include <Servo.h>

// VARIABLES
// Pins
const int RECV_PIN = 11; // IR reciever data pin
const int ledPin = 13; // Onboard LED for testing
const int servoPin = 10; // Storage bay-opening servo

// Servo Position Settings
const int unlocked = 12;
const int locked = unlocked + 90;

// Apple IR Remote Button Hexadecimal IR Codes
const long playButton = 2011275285;
const long plusButton = 2011254805;
const long minusButton = 2011246613;
const long rewindButton = 2011271189;
const long forwardButton = 2011258901;
const long menuButton = 2011283477;

// OBJECTS
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;

void setup() {
  //Serial.begin(9600); // begin serial monitor for testing
  irrecv.enableIRIn();
  servo.attach(servoPin);
  servo.write(unlocked); // set initial servo position to unlocked
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) { // if IR reciever recieves data
    //Serial.println(results.value);
    switch (results.value) { // determine button pressed from code recieved
      case playButton: dropConfetti(); break;
      case plusButton: break;
      case minusButton: break;
      case rewindButton: resetServo(); break;
      case forwardButton: break;
      case menuButton: testBlink(); break;
    }
    irrecv.resume();
  }
}

void dropConfetti() { // Drop confetti from the confetti module
  servo.write(unlocked); // turn servo to side, releasing bottom
}

void resetServo() {
  servo.write(locked); // put servo horn underneath bottom of dropper, locking it
}

void testBlink() { // Blinks onboard LED five times
  //Serial.println("Testing 123");
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}
