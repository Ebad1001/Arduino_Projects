#include <Servo.h>

// sensor pins
#define ir_L A0
#define ir_F A1
#define ir_R A2
// motor driver pins
#define enA 7  // Enable1 L298 Pin enA
#define in1 6  // Motor1 L298 Pin in1
#define in2 5  // Motor1 L298 Pin in2
#define in3 4  // Motor2 L298 Pin in3
#define in4 3  // Motor2 L298 Pin in4
#define enB 2  // Enable2 L298 Pin enB
// output pins
Servo motor;
#define servo A4
#define pump A5

const int speed = 160;
const int angleRange = 40;

void setup() {
  // declare fire sensor pin as input
  pinMode(ir_R, INPUT);
  pinMode(ir_F, INPUT);
  pinMode(ir_L, INPUT);
  // declare motor driver pin as output
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  // declare output pins as output
  motor.attach(servo);
  pinMode(pump, OUTPUT);

  // setting motor speed
  analogWrite(enA, speed);  // 0 to 255 for Motor speed
  analogWrite(enB, speed);  // 0 to 255 for Motor speed

  // 40 <--(50 degrees)--> 90 <--(50 degrees)--> 140
  for (int angle = 90; angle <= 140; angle += 5) {
    motor.write(angle);
  }
  for (int angle = 140; angle >= 40; angle -= 5) {
    motor.write(angle);
  }
  for (int angle = 40; angle <= 90; angle += 5) {
    motor.write(angle);
  }

  Serial.begin(9600);
  delay(500);
}
void loop() {
  // reading sensor values
  int s_r = analogRead(ir_R);
  int s_f = analogRead(ir_F);
  int s_l = analogRead(ir_L);

  Serial.print(s_r);
  Serial.print("\t");
  Serial.print(s_f);
  Serial.print("\t");
  Serial.print(s_l);
  Serial.print("\n");

  if (s_f < 350) {
    // if high reading around mid sensor
    // spray in front
    stop();
    digitalWrite(pump, HIGH);
    for (int angle = 90; angle <= 120; angle += 3) {
      motor.write(angle);
    }
    for (int angle = 120; angle >= 60; angle -= 3) {
      motor.write(angle);
    }
    for (int angle = 60; angle <= 90; angle += 3) {
      motor.write(angle);
    }
  } else if (s_r < 250) {
    // if high reading around right sensor
    // spray in right
    stop();
    digitalWrite(pump, HIGH);
    for (int angle = 90; angle >= 40; angle -= 3) {
      motor.write(angle);
    }
    for (int angle = 40; angle <= 90; angle += 3) {
      motor.write(angle);
    }
  } else if (s_l < 250) {
    // if high reading around left sensor
    // spray in left
    stop();
    digitalWrite(pump, HIGH);
    for (int angle = 90; angle <= 140; angle += 3) {
      motor.write(angle);
    }
    for (int angle = 140; angle >= 90; angle -= 3) {
      motor.write(angle);
    }
  } else if (s_f >= 251 && s_f <= 800) {
    // if low reading around mid sensor
    // go forwards
    digitalWrite(pump, LOW);
    forward();
  } else if (s_r >= 251 && s_r <= 700) {
    // if low reading around right sensor
    // go towards right
    digitalWrite(pump, LOW);
    backward();
    delay(100);
    turnRight();
    delay(200);
  } else if (s_l >= 251 && s_l <= 700) {
    // if low reading around left sensor
    // go towards left
    digitalWrite(pump, LOW);
    backward();
    delay(100);
    turnLeft();
    delay(200);
  } else {
    digitalWrite(pump, LOW);
    stop();
  }
  delay(100);
}

// functions for moving the car
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}