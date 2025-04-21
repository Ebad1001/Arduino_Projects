#include<Servo.h>
int IR_1 = 3;
int IR_2 = 4;
int servo_pin = 5;
Servo gate;

int open_angle = 90;
int close_angle = 0;

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  gate.attach(servo_pin);
  Serial.begin(9600);
}

void loop() {
  // taking reading from 1st IR
  int val_1 = digitalRead(IR_1);
  Serial.print("\nval_1 = ");
  Serial.print(val_1);
  if(val_1 == 0)
  {
    gate.write(open_angle);
  }
  
  // taking reading from 2nd IR
  int val_2 = digitalRead(IR_2);
  Serial.print("\tval_2 = ");
  Serial.print(val_2);
  if(val_2 == 0)   
  {
    gate.write(close_angle);
  }

  delay(10);
}
