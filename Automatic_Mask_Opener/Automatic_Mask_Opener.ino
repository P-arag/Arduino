#include <Servo.h>

const int trigPin = 7;
const int echoPin = 6;

Servo lidServo;
const int servoPin = 9;

const int buzzPin = 4;

void setup() {
  Serial.begin(9600);
  lidServo.attach(servoPin);
}

void beep(int pin , float freq, float duration, float gap)
{
  tone(pin, freq, duration);
  delay(gap);
  tone(pin, freq, duration);
}

void loop() {
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);

  long duration = pulseIn(echoPin, HIGH);
  int cm = duration / 29 / 2;

  if (cm < 10)
  {
    Serial.println("Food is close");
    beep(buzzPin, 300, 500, 300);
    lidServo.write(180);
  }
  else
    lidServo.write(0);

  delay(100);
}
