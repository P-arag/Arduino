#include <IRremote.h> // include the IRremote library

#define RECEIVER_PIN 2 // define the IR receiver pin
IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class

void setup() {
  Serial.begin(9600); // begin serial communication with a baud rate of 9600
  receiver.enableIRIn(); // enable the receiver
}

void loop() {
  if (receiver.decode(&results)) {
    Serial.println(results.value, HEX);
    Serial.println("yo");
    receiver.resume();
  }
}
