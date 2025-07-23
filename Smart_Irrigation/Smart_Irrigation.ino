const int sensor = A0;
const int motor = 13;
const int threshold = 512;

void setup() {
  pinMode(sensor, INPUT); 
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // take reading from sensor
  int reading = analogRead(sensor);
  Serial.println(reading);

  // give output to motor 
  if(reading < threshold) {
    digitalWrite(motor, LOW);
  }
  else {
    digitalWrite(motor, HIGH);
  }

  delay(100);
}
