int LED_count = 7;
int pins[7] = { 2, 7, 5, 10, 8, 3, 12 }; // randomize the LED order for random output

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
