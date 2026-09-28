#include <Arduino.h>

// We are using channel 1, to control the turn
const int turn = 2;
const int turn_lower = 1330;
const int turn_upper = 1670;

// We are using channel 2, to control the throttle
const int throttle = 3;
const int throttle_lower = 1340;
const int throttle_upper = 1670;

// We are controlling Left motors with PWM pins 5 & 6
const int Left_T1 = 9;
const int Left_T2 = 10;
// We are controlling Right motors with PWM pins 10 & 11
const int Right_T1 = 5;
const int Right_T2 = 6;

void setup() {
  pinMode(turn, INPUT);
  pinMode(throttle, INPUT);
  
  pinMode(Left_T1, OUTPUT);
  pinMode(Left_T2, OUTPUT);
  pinMode(Right_T1, OUTPUT);
  pinMode(Right_T2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int turn_value = pulseIn(turn, HIGH);
  int throttle_value = pulseIn(throttle, HIGH);
  Serial.print("\nTurn: ");
  Serial.print(turn_value);
  Serial.print("\tThrottle: ");
  Serial.println(throttle_value);
  
  if(turn_value == 0 || throttle_value == 0){
    Serial.println("Invalid Reading");
    digitalWrite(Left_T2, LOW);
    digitalWrite(Left_T1, LOW);
    digitalWrite(Right_T1, LOW);
    digitalWrite(Right_T2, LOW);
    Serial.println("Stop");
  }
  else if(turn_value < turn_lower){
    digitalWrite(Left_T2, LOW);
    digitalWrite(Left_T1, HIGH);
    digitalWrite(Right_T1, HIGH);
    digitalWrite(Right_T2, LOW);
    Serial.println("Turn Left");
  }
  else if(turn_value > turn_upper){
    digitalWrite(Left_T2, HIGH);
    digitalWrite(Left_T1, LOW);
    digitalWrite(Right_T1, LOW);
    digitalWrite(Right_T2, HIGH);
    Serial.println("Turn Right");
  }
  else if(throttle_value < throttle_lower){
    digitalWrite(Left_T2, LOW);
    digitalWrite(Left_T1, HIGH);
    digitalWrite(Right_T1, LOW);
    digitalWrite(Right_T2, HIGH);
    Serial.println("Move Backward");
  }
  else if(throttle_value > throttle_upper){
    digitalWrite(Left_T2, HIGH);
    digitalWrite(Left_T1, LOW);
    digitalWrite(Right_T1, HIGH);
    digitalWrite(Right_T2, LOW);
    Serial.println("Move Forward");
  }
  else {
    digitalWrite(Left_T2, LOW);
    digitalWrite(Left_T1, LOW);
    digitalWrite(Right_T1, LOW);
    digitalWrite(Right_T2, LOW);
    Serial.println("Stop");
  }
  delay(100);
}
