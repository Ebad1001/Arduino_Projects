// define the component pins
const int trigPin = 8;  // connect the TRIG pin of Ultrasonic sensor at pin 8
const int echoPin = 9;  // connect the ECHO pin of Ultrasonic sensor at pin 9
                        // connect the VCC pin of Ultrasonic sensor at 5V
                        // connect the GND pin of Ultrasonic sensor at GND
// MOTOR DRIVER         // connect the 12V pin of motor driver with the positive terminal of battery
                        // connect the GND pin of motor driver with the negative terminal of battery & with GND pin of Arduino
                        // connect the 5V pin of motor driver with the Vin pin of Arduino
                        // connect the OUT4 & OUT3 pins of motor driver with left motor
                        // connect the OUT2 & OUT1 pins of motor driver with right motor
const int IN4 = 10;     // connect the IN4 pin of motor driver at pin 10
const int IN3 = 11;     // connect the IN3 pin of motor driver at pin 11
const int IN2 = 12;     // connect the IN2 pin of motor driver at pin 12
const int IN1 = 13;     // connect the IN1 pin of motor driver at pin 13
const int ENB = 5;      // connect the ENB pin of motor driver at pin 5
const int ENA = 6;      // connect the ENA pin of motor driver at pin 6

// direction constants
const int stop = 0;     // 0 0 0 0
const int forward = 10; // 1 0 1 0
const int backward = 5; // 0 1 0 1
const int left = 6;     // 0 1 1 0
const int right = 9;    // 1 0 0 1

// other constants
const int minClearance = 50; 
const int maxClearance = 500;
const float percentSpeed = 2.55;
const float speedOfSound = 0.0343; // unit = cm per microsec

float getDistance()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  float duration = pulseIn(echo, HIGH);
  float distance = speedOfSound * (duration / 2);
  return distance;
}

void move(int direction, int interval = 0)
{
  digitalWrite(IN4, (direction & 8) / 8);
  digitalWrite(IN3, (direction & 4) / 4);
  digitalWrite(IN2, (direction & 2) / 2);
  digitalWrite(IN1, (direction & 1) / 1);
  delay(interval);
}

void setup()
{
  // set the pin modes
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // set speed (max)
  analogWrite(ENA, int(60*percentSpeed));
  analogWrite(ENB, int(80*percentSpeed));

  // initially stop
  move(stop);

  // initialize the serial port
  Serial.begin(9600);
}

void loop()
{
  // take reading from Ultrasonic Sensor
  float distance = getDistance();
  Serial.print("\ndistance = ");
  Serial.print(distance);

  // making decision based on sensor value
  if (distance == 0 || maxClearance < distance)
  {
    Serial.print("\tInvalid");
    return; // invalid reading
}
else if (minClearance < distance && distance < maxClearance)
{
    Serial.print("\tOpen path");
    move(forward, 100);
}
else 
{
    Serial.print("\tObstructed path");
    move(stop,  500);
    move(backward, 1000);
    move(left,  1000);
    move(right, 2000);
    move(stop,  500);
  }
}
