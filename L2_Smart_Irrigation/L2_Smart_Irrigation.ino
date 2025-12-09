// define the component pins
const int sensor = A0;      // connect the AO pin of moisture sensor at pin A0
                            // connect the VCC pin of moisture sensor at 5V
                            // connect the GND pin of moisture sensor at GND
const int motor = 13;       // connect the red wire of motor at the OUT pin of relay
                            // connect the blk wire of motor with negative terminal of battery
// RELAY MODULE             // connect the VCC pin of relay at 5V
                            // connect the GND pin of relay at GND
                            // connect the IN pin of relay at pin 13
                            // connect the NC pin of relay with negative terminal of battery
                            // connect the NO pin of relay with positive terminal of battery

// define the threshold value
const int threshold = 500;

void setup() {
  // set the pin modes
  pinMode(sensor, INPUT); 
  pinMode(motor, OUTPUT);

  // initialize the motor pin as LOW - initially the motor is off
  digitalWrite(motor, LOW);

  // initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // take reading from sensor
  int value = analogRead(sensor);
  Serial.print("\nvalue = ");
  Serial.print(value);

  // give output to motor 
  if(value < threshold) {
    digitalWrite(motor, LOW);
  }
  else {
    digitalWrite(motor, HIGH);
  }

  // delay for smooth performance
  delay(100);
}
