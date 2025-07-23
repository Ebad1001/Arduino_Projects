// int LDR = 7;
// int LED = 13;

// void setup() {
//   pinMode(LDR, INPUT);
//   pinMode(LED, OUTPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   // take input from LDR sensor
//   int value = digitalRead(LDR);
//   Serial.println(value);

//   // show output on LED lamp
//   if (value == 0) {
//     // High light level : Turn the LED OFF
//     digitalWrite(LED, LOW);
//   } else {
//     // Low light level : Turn the LED ON
//     digitalWrite(LED, HIGH);
//   }

//   // repeat
//   delay(100);
// }

int LDR = 7;
int LED = 13;

void setup() {
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // take input from LDR
  int value = digitalRead(LDR);
  Serial.println(value);
  // show output on LED
  if (value == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  
  delay(100);
}
