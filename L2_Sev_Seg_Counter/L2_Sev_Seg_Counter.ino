// define the component pins
const int pins[7] = {2, 3, 4, 5, 6, 7, 8};  // connect the {A, B, C, D, E, F, G} pins of the 7-segment display
                                            // to these pins in the given order
                                            // connect CC (common cathode) pin of the 7-segment display to GND

// define the values for each digit
const int vals[16][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

void display(int num) {
  // set the values for each segment to display the given number
  for(int i=0; i<7; i++) {
    digitalWrite(pins[i], vals[num][i]);
  }
}

void setup() {
  // set the pin modes
  for (int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // display each number from 0 to 9 in a loop
  for(int num=0; num<10; num++) {
    display(num);
    delay(1000);
  }
}
