// define the component pins
const int pins[7] = {2, 3, 4, 5, 6, 7, 8};  // connect the {A, B, C, D, E, F, G} pins of the 7-segment display
                                            // to these pins in the given order
                                            // connect CC (common cathode) pin of the 7-segment display to GND
const int IR = 13;  // connect the DO pin of the IR sensor at pin 13
                    // connect its GND pin at GND
                    // connect its VCC pin at 5V

// define the values for each digit
const int vals[16][7] = {
    {0, 0, 0, 1, 0, 0, 0}, // _
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}  // 6
};

void display(int num) {
  for(int i=0; i<7; i++) {
    digitalWrite(pins[i], vals[num][i]);
  }
}

void setup() {
  // set the pin modes
  pinMode(IR, INPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // initialize the display with _
  display(0);

  // initialize the serial port
  Serial.begin(9600);
}

int prev_reading = 0;
void loop() {
  // take reading from IR sensor
  int reading = digitalRead(IR);
  // if an object is detected: display a random number
  if(reading == 1 and prev_reading == 0) {
    int num = random(1, 7);
    display(num);
    Serial.print("\nnum = ");
    Serial.print(num);
  }
  // update the previous reading for next round
  prev_reading = reading;

  // delay for smooth performance
  delay(100);
}
