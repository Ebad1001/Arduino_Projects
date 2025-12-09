// define the component pins
int LDR = 7;   // connect the DO pin of LDR sensor at pin 7
               // connect the GND pin of LDR sensor at GND
               // connect the VCC pin of LDR sensor at 5V
int LED = 13;  // connect the anode of LED at pin 13 and its cathode at GND

void setup() {
  // set the pin modes
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);

  // initialize the LED pin as LOW - initially the LED is off
  digitalWrite(LED, LOW);

  // initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // take reading from LDR sensor
  int value = digitalRead(LDR);

  // print sensor readings on Serial monitor
  Serial.print("\nvalue = ");
  Serial.print(value);

  // making decision based on sensor value
  if (value == 1) {
    // if the value is 1 (Darkness), turn on the LED
    digitalWrite(LED, HIGH);
  } else {
    // if the value is 0 (Brightness), turn off the LED
    digitalWrite(LED, LOW);
  }

  // delay for smooth performance
  delay(100);
}
