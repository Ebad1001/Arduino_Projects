int trigPin = 2;
int echoPIn = 3;

int leftA = 10;
int leftB = 11;
int rightA = 12;
int rightB = 13;

void stop() {
  digitalWrite(leftA, LOW);
  digitalWrite(leftB, LOW);
  digitalWrite(rightA, LOW);
  digitalWrite(rightB, LOW);
}
void goForward() {
  digitalWrite(leftA, HIGH);
  digitalWrite(leftB, LOW);
  digitalWrite(rightA, HIGH);
  digitalWrite(rightB, LOW);
}
void turnRight() {
  digitalWrite(leftA, HIGH);
  digitalWrite(leftB, LOW);
  digitalWrite(rightA, HIGH);
  digitalWrite(rightB, LOW);
}
void stop() {
  digitalWrite(leftA, LOW);
  digitalWrite(leftB, LOW);
  digitalWrite(rightA, LOW);
  digitalWrite(rightB, LOW);
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2;

  if (distance < 20) {
    stop();
    delay(1000);
    turnRight()
    delay(1000);
  } else {
    goForward()
    delay(1000);
  }
}
