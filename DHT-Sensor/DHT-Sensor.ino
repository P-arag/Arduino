#include <DHT.h>
#define Type DHT11
const int sensePin = 2;
DHT HT(sensePin, Type);

float humitdity;
float tempC;
float tempF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

  Serial.println("Humidity:- " + humidity + " Temperature in C:- " + tempC + " Temperature in F:- " + tempF );
  delay(10000);
}
