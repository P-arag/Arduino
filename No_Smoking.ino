//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//
//}

//void loop() {
//  // put your main code here, to run repeatedly:
//  int reading = analogRead(A5);
//  Serial.println(reading);
//  delay(500);
//}
#include <DHT.h>
#include<Servo.h>


#define Type DHT11
const int sensePin = 4;
DHT HT(sensePin, Type);
Servo servo;

float tempF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  servo.attach(9);
  servo.write(0);
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  tempF = HT.readTemperature(true);
  Serial.println(tempF);
  if (tempF > 100) {
    Serial.println("smoking");
    servo.write(180);
  }
  delay(1000);
}
