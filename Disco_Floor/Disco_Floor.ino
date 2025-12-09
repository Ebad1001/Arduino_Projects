int LED_count = 7;
int pins[7] = { 8, 9, 10, 11, 12, 13 }; // randomize the LED order for random output

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<LED_count; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<LED_count; i++)
  {
    digitalWrite(pins[i], HIGH);
    delay(100);
    digitalWrite(pins[i], LOW);
  }
}
