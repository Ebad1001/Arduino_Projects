#include <Arduino.h>
#include "SevenSegment.h"

const int digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
    {1, 1, 1, 0, 1, 1, 1}, // A
    {0, 0, 1, 1, 1, 1, 1}, // B
    {1, 0, 0, 1, 1, 1, 0}, // C
    {0, 1, 1, 1, 1, 0, 1}, // D
    {1, 0, 0, 1, 1, 1, 1}, // E
    {1, 1, 0, 0, 1, 1, 1}, // F
};

void clearDisplay(int pins[])
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(pins[i], 0);
    }
}
void displayNumber(int digit, int pins[])
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(pins[i], digits[digit][i]);
    }
}
void displayHex(int digit, int pins[])
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(pins[i], digits[digit][i]);
    }
}
