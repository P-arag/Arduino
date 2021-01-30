#include <IRremote.h>

IRrecv IR(9);
decode_results out;

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
}
void loop() {
  // put your main code here, to run repeatedly:

  if (IR.decode()) {
    Serial.println(out.value, HEX);
    Serial.print("  Got it");
    delay(1500);
    IR.resume();
  }
}
