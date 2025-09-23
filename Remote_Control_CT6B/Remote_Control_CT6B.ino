const int channel_1 = 14; // 14 = A0
const int channel_2 = 15; // 15 = A1
const int channel_3 = 16; // 16 = A2
const int channel_4 = 17; // 17 = A3

void setup()
{
  // set the pin modes
  pinMode(channel_1, INPUT);
  pinMode(channel_2, INPUT);
  pinMode(channel_3, INPUT);
  pinMode(channel_4, INPUT);

  // initialize the serial port
  Serial.begin(9600);
}

void loop()
{
  // read the values
  int value_1 = pulseIn(channel_1, HIGH); // right joystick left-right
  int value_2 = pulseIn(channel_2, HIGH); // right joystick up-down
  int value_3 = pulseIn(channel_3, HIGH); // left joystick up-down
  int value_4 = pulseIn(channel_4, HIGH); // left joystick left-right

  // print the values
  Serial.print("\nch1: ");
  Serial.print(value_1);
  Serial.print("\tch2: ");
  Serial.print(value_2);
  Serial.print("\tch3: ");
  Serial.print(value_3);
  Serial.print("\tch4: ");
  Serial.print(value_4);

  // delay for smooth performance
  delay(100);
}
