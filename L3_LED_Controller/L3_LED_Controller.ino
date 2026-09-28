#include <Arduino.h>

// define the channel pins
const int channel_1 = A0;
const int channel_2 = A1;
// define the LED pins
const int LED_L = 2;
const int LED_R = 3;
const int LED_U = 4;
const int LED_D = 5;

void setup()
{
  // set the pin modes
  pinMode(channel_1, INPUT);
  pinMode(channel_2, INPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_U, OUTPUT);
  pinMode(LED_D, OUTPUT);

  // initialize the serial port
  Serial.begin(9600);
}

void loop()
{
  // read the values
  int value_LR = pulseIn(channel_1, HIGH); // right joystick left-right
  int value_UD = pulseIn(channel_2, HIGH); // right joystick up-down

  // show the values on the serial monitor
  Serial.print("\nch1: ");
  Serial.print(value_LR);
  Serial.print("\tch2: ");
  Serial.print(value_UD);
  Serial.print("\n----------------");

  // turn all LEDs off
  digitalWrite(LED_L, LOW);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_U, LOW);
  digitalWrite(LED_D, LOW);

  // glow LEDs based on the readings
  if(value_LR < 1300)
  {
    digitalWrite(LED_L, HIGH);
  }
  if(value_LR > 1700)
  {
    digitalWrite(LED_R, HIGH);
  }
  if(value_UD < 1300)
  {
    digitalWrite(LED_D, HIGH);
  }
  if(value_UD > 1700)
  {
    digitalWrite(LED_U, HIGH);
  }

  // delay for smooth performance
  delay(1000);
}
