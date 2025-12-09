// include the Servo library
#include <Servo.h>

// create a Servo object
Servo motor;

// define the component pins
int servoPin = 12;  // connect the ylw pin of servo motor at pin 12
                    // connect the red pin of servo motor at 5V
                    // connect the brn pin of servo motor at GND
int IR1 = 4;        // connect the DO pin of the first IR sensor at pin 4
                    // connect its GND pin at GND
                    // connect its VCC pin at 5V
int IR2 = 5;        // connect the DO pin of the second IR sensor at pin 5
                    // connect its GND pin at GND
                    // connect its VCC pin at 5V

// define the angles
int openAngle = 90;
int closeAngle = 0;

void setup() {
  // set the pin modes
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  motor.attach(servoPin);

  // initialize the servo motor as closed
  motor.write(closeAngle);

  // initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // take reading from both the IR sensors
  int value1 = digitalRead(IR1);
  int value2 = digitalRead(IR2);

  // print sensor readings on Serial monitor
  Serial.print("\nvalue1 = ");
  Serial.print(value1);
  Serial.print("\tvalue2 = ");
  Serial.print(value2);

  // making decision based on sensor value
  if (value1 == 0) {
    // if the value1 is 0 (an object is detected at first IR), open the gate
    motor.write(openAngle);
  }
  if (value2 == 0) {
    // if the value2 is 0 (an object is detected at second IR), close the gate
    motor.write(closeAngle);
  }

  // delay for smooth performance
  delay(100);
}