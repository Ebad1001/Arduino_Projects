// define the LED pins
int led_red = 11;  // connect the anode of red LED at pin 11 and its cathode at GND
int led_ylw = 12;  // connect the anode of ylw LED at pin 12 and its cathode at GND
int led_grn = 13;  // connect the anode of grn LED at pin 13 and its cathode at GND

void setup() {
  // set the pin modes
  pinMode(led_red, OUTPUT);
  pinMode(led_ylw, OUTPUT);
  pinMode(led_grn, OUTPUT);

  // initialize the LED pins as LOW - initially all LEDs are off
  digitalWrite(led_red, LOW);
  digitalWrite(led_ylw, LOW);
  digitalWrite(led_grn, LOW);
}

void loop() {
  // glow the led_red for 5 seconds
  digitalWrite(led_red, HIGH);
  delay(5000);
  digitalWrite(led_red, LOW);

  // glow the led_ylw for 3 seconds
  digitalWrite(led_ylw, HIGH);
  delay(3000);
  digitalWrite(led_ylw, LOW);

  // glow the led_grn for 5 seconds
  digitalWrite(led_grn, HIGH);
  delay(5000);
  digitalWrite(led_grn, LOW);
}