// include the Servo library
#include <Servo.h>

// create a Servo object
Servo motor;

// define the component pins
int servoPin = 12;  // connect the ylw pin of servo motor at pin 12
                    // connect the red pin of servo motor at 5V
                    // connect the brn pin of servo motor at GND
int trigPin = 2;    // connect the TRIG pin of Ultrasonic sensor at pin 2
int echoPin = 3;    // connect the ECHO pin of Ultrasonic sensor at pin 3
                    // connect the VCC pin of Ultrasonic sensor at 5V
                    // connect the GND pin of Ultrasonic sensor at GND

// define the angles
int openAngle = 90;
int closeAngle = 0;

void setup() {
  // set the pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  motor.attach(servoPin);

  // initialize the servo motor as closed
  motor.write(closeAngle);

  // initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // take reading from Ultrasonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long int duration = pulseIn(echoPin, HIGH);
  long int distance = duration * (0.0343 / 2);

  // print sensor readings on Serial monitor
  Serial.print("\nDistance = ");
  Serial.print(distance);

  // making decision based on sensor value
  if (0 < distance && distance <= 30) {
    // if the distance is between 0 to 30 cm, open the lid and wait for 5 secs before closing it again.
    motor.write(openAngle);
    delay(5000);
    motor.write(closeAngle);
  }

  // delay for smooth performance
  delay(100);
}