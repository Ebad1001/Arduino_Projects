#define red_A 2
#define ylw_A 3
#define grn_A 4
#define red_B 5
#define ylw_B 6
#define grn_B 7

void setup() {
  for (int pin = 2; pin < 8; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void blink(int pin1, int pin2, int duration) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  delay(duration);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

void loop() {
  // red - grn
  blink(red_A, grn_B, 2000);
  // red - red
  blink(red_A, red_B, 500);
  // ylw - red
  blink(ylw_A, red_B, 1000);
  // grn - red
  blink(grn_A, red_B, 2000);
  // red - red
  blink(red_A, red_B, 500);
  // red - ylw
  blink(red_A, ylw_B, 1000);
}
