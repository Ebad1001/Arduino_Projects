#include "SevenSegment.h"

int ones[7] = { 9, 11, A3, A4, 13, 10, 12 };
int tens[7] = { 2, 4, 7, 8, 6, 3, 5 };
int buzzPin = A1;
int knobPin = A0;

void prepare(int num) {
  if (num < 0) {
    clearDisplay(tens);
    clearDisplay(ones); 
    return;
  }
  int T = num / 10;
  int O = num % 10;
  displayNumber(T, tens);
  displayNumber(O, ones);
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(ones[i], OUTPUT);
    pinMode(tens[i], OUTPUT);
  }
  pinMode(buzzPin, OUTPUT);
  pinMode(knobPin, INPUT);
  Serial.begin(9600);

  int interval = analogRead(knobPin);
  int minutes = map(interval, 0, 1023, 1, 15);
  Serial.print("Timer set for ");
  Serial.print(minutes);
  Serial.print(" minutes.\n");
  prepare(minutes);
  delay(1000);
  prepare(-1);  // clrscr
  int ticks = minutes * 60 * 1000 / 100;
  Serial.println(ticks);

  int num = 100;
  while (num > 0) {
    num -= 1;
    prepare(num);
    delay(ticks);
  }
  // prepare(-1);
  digitalWrite(buzzPin, HIGH);
  delay(3000);
  digitalWrite(buzzPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
}
