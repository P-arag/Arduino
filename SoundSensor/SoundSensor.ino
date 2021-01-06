 void setup() {
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    int input = analogRead(A2);
    Serial.println(input*10);
    delay(20);
}
