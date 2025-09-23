// Motor Driver pins
const int IN1 = 10;
const int IN2 = 11;
const int IN3 = 12;
const int IN4 = 13;
const int ENA = 3;
const int ENB = 5;

// Ultrasonic Sensor pins
const int trig = 8;
const int echo = 9;

// Direction constants
const int stop = 0;     // 0 0 0 0
const int forward = 10; // 1 0 1 0
const int backward = 5; // 0 1 0 1
const int left = 6;     // 0 1 1 0
const int right = 9;    // 1 0 0 1

// Other constants
const int maxSpeed = 255;
const int minClearance = 30;
const int speedOfSound = 0.0343; // unit = cm per microsec

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);

  // set speed (max)
  analogWrite(ENA, int(0.5*maxSpeed));
  analogWrite(ENB, int(0.5*maxSpeed));
}

void loop()
{
  float distance = getDistance();
  Serial.println(distance);

  if (distance > minClearance)
  {
    move(forward);
  }
  else
  {
    move(stop);
    delay(500);
    move(backward);
    delay(500);
    move(left); // or move(right);
    delay(1000);
    move(stop);
  }
}

float getDistance()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  float duration = pulseIn(echo, HIGH);
  float distance = speedOfSound * duration / 2;
  return distance;
}

void move(int dire)
{
  digitalWrite(IN1, (dire & 8) / 8);
  digitalWrite(IN2, (dire & 4) / 4);
  digitalWrite(IN3, (dire & 2) / 2);
  digitalWrite(IN4, (dire & 1) / 1);
}
