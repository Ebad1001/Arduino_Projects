// define the component pins
int trigPin = 2;  // connect the TRIG pin of Ultrasonic sensor at pin 2
int echoPin = 3;  // connect the ECHO pin of Ultrasonic sensor at pin 3
                  // connect the VCC pin of Ultrasonic sensor at 5V
                  // connect the GND pin of Ultrasonic sensor at GND
int buzz = 13;    // connect the longer pin of buzzer at pin 13 and its shorter pin at GND

void setup() {
  // set the pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzz, OUTPUT);

  // initialize the buzzer pin as LOW - initially the buzzer is OFF
  digitalWrite(buzz, LOW);

  // initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // take reading from the Ultrasonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;

  // print sensor readings on Serial monitor
  Serial.print("\ndistance = ");
  Serial.print(distance);

  // making decision based on sensor value
  if (distance < 20) {
    // if the distance is less than 20 cm, turn on the buzzer
    digitalWrite(buzz, HIGH);
  } else {
    // if the distance is more than 20 cm, turn off the buzzer
    digitalWrite(buzz, LOW);
  }

  // delay for smooth performance
  delay(100);
}
