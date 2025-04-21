#include <Arduino.h>
#include "Ultrasonic.h"

float get_duration(int trigPin, int echoPin) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    return pulseIn(echoPin, HIGH);
}

float get_distance(int trigPin, int echoPin, float speed = 0.0343) {
    float duration = get_duration(trigPin, echoPin);
    return (duration * speed) / 2;
}