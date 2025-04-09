#include <Arduino.h>
#include "Ultrasonic.h"

class Ultrasonic
{
    int trigPin;
    int echoPin;

public:
    Ultrasonic(int trigPin = 0, int echoPin= 0)
    {
        this->trigPin = trigPin;
        this->echoPin = echoPin;
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
    }
    void setPins(int trigPin, int echoPin)
    {
        this->trigPin = trigPin;
        this->echoPin = echoPin;
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
    }
    float getDuration()
    {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        return pulseIn(echoPin, HIGH);
    }
    float getDistance(float speedInMetersPerSecond = 343)
    {
        return this->getDuration() * speedInMetersPerSecond / 20000;
    }
};