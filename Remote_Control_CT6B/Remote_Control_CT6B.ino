#include <Arduino.h>

const int channel_1 = A0;
const int channel_2 = A1;
const int channel_3 = A2;
const int channel_4 = A3;
const int channel_5 = A4;
const int channel_6 = A5;

void setup()
{
  // set the pin modes
  pinMode(channel_1, INPUT);
  pinMode(channel_2, INPUT);
  pinMode(channel_3, INPUT);
  pinMode(channel_4, INPUT);
  pinMode(channel_5, INPUT);
  pinMode(channel_6, INPUT);

  // initialize the serial port
  Serial.begin(9600);
}

void loop()
{
  // read the values
  int value_1 = pulseIn(channel_1, HIGH); // right joystick left-right
  Serial.print("\nch1: ");
  Serial.print(value_1);

  int value_2 = pulseIn(channel_2, HIGH); // right joystick up-down
  Serial.print("\tch2: ");
  Serial.print(value_2);

  int value_3 = pulseIn(channel_3, HIGH); // left joystick up-down
  Serial.print("\nch3: ");
  Serial.print(value_3);

  int value_4 = pulseIn(channel_4, HIGH); // left joystick left-right
  Serial.print("\tch4: ");
  Serial.print(value_4);

  int value_5 = pulseIn(channel_5, HIGH); // right knob rotate
  Serial.print("\nch5: ");
  Serial.print(value_5);
  
  int value_6 = pulseIn(channel_6, HIGH); // left knob rotate
  Serial.print("\tch6: ");
  Serial.print(value_6);

  // delay for smooth performance
  Serial.print("\n----------------");
  delay(100);
}
