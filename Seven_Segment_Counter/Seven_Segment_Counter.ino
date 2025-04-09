#include <SevenSegment.h>

int pinMap[7] = { 1, 2, 3, 4, 5, 6, 7 };

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(pinMap[i], OUTPUT);
  }
}

int num = 0;
void loop() {
  display(num, pinMap);
  num += 1;
  num %= 10;
  delay(1000);
}