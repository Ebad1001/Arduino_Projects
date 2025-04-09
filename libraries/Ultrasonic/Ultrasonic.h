#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic {
public:
    Ultrasonic(int trigPin, int echoPin);
    void setPins(int trigPin, int echoPin);
    float getDuration();
    float getDistance(float speedInMetersPerSecond = 343);
private:
    int trigPin;
    int echoPin;
};

#endif

