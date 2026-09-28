#include <Arduino.h>

// define the pins for the traffic lights
const int red_A = 2;
const int ylw_A = 3;
const int grn_A = 4;
const int red_B = 5;
const int ylw_B = 6;
const int grn_B = 7;
const int led_pins[] = {red_A, ylw_A, grn_A, red_B, ylw_B, grn_B};

void setup()
{
  for (int i = 0; i < 6; i++)
  {
    pinMode(led_pins[i], OUTPUT);
    digitalWrite(led_pins[i], LOW);
  }
}

void show(int pin1, int pin2, int duration)
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  delay(duration);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

void loop()
{
  // red - grn
  show(red_A, grn_B, 2000);
  // red - red
  show(red_A, red_B, 500);
  // ylw - red
  show(ylw_A, red_B, 1000);
  // grn - red
  show(grn_A, red_B, 2000);
  // red - red
  show(red_A, red_B, 500);
  // red - ylw
  show(red_A, ylw_B, 1000);
}
