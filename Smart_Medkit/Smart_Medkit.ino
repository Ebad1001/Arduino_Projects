#include <Servo.h>

// this list store the timings for the 4 alarms
// multiplying the timings with 60000 to convert from minutes to milliseconds
unsigned long timings[5] = {
  0,                // 0 for start, no alarm
  1 * 60000,        // timing for first alarm  (here we set 1min)
  2 * 60000,        // timing for second alarm (here we set 2min)
  3 * 60000,        // timing for third alarm  (here we set 3min)
  4 * 60000         // timing for fourth alarm (here we set 4min)
};                  //
int nextEvent = 1;  // index for first event
int lastEvent = 4;  // index for last event

void setup() {
  const int sensorPin = 8;     // setting up IR sensor
  pinMode(sensorPin, INPUT);   // sensor is connected to pin #8
  Servo motor;                 // setting up servo motor
  motor.attach(12);            // servo is connected to pin #12
  motor.write(0);              // initially set motor to 0 degrees
  const int buzzPin = 13;      // setting up buzzer
  pinMode(buzzPin, OUTPUT);    // buzzer is connected to pin #13
  digitalWrite(buzzPin, LOW);  // initially set buzzer to OFF

  unsigned long startTime = millis();                     // note the start time
  while (nextEvent <= lastEvent) {                        // keep running while there are events
    int prevReading = digitalRead(sensorPin);             // take reading from IR sensor
    while (timings[nextEvent] <= millis() - startTime) {  // if the next event has started
      digitalWrite(buzzPin, HIGH);                        // turn the buzzer ON
      motor.write(45 * nextEvent);                        // move the servo to open the next lid
      int currReading = digitalRead(sensorPin);           // take reading from IR sensor
      if (currReading != prevReading) {                   // if there's a change in sensor reading
        digitalWrite(buzzPin, LOW);                       // turn the buzzer OFF
        nextEvent += 1;                                   // update the timer for next event
        break;                                            // break the loop to wait for next event
      }                                                   //
      prevReading = currReading;                          // update the sensor reading for next round
      delay(10);                                          // add a little delay for better performance
    }                                                     //
    delay(10);                                            // add a little delay for better performance
  }
}
void loop() {}
