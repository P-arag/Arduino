#define outputA 6
#define outputB 7
#define switchPin 12

int counter = 0;
int aState;
int aLastState;

void setup() {
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  pinMode(switchPin, INPUT);

  Serial.begin(9600);
  aLastState = digitalRead(outputA);

}

void loop() {
  aState = digitalRead(outputA); 
  if (aState != aLastState) {
    if (digitalRead(outputB) != aState) {
      counter ++;
    } else {
      counter --;
    }

    Serial.println("Position: " + String(counter));
  }
  aLastState = aState;  
}
