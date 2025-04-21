#ifndef ULTRASONIC_H
#define ULTRASONIC_H

float get_duration(int trigPin, int echoPin);
float get_distance(int trigPin, int echoPin, float speed = 0.0343);  

#endif

