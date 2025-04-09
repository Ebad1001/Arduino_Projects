int led_red = 11;
int led_ylw = 12;
int led_grn = 13;

void setup()
{
  // set the pin modes to OUTPUT
  pinMode(led_red, OUTPUT);
  pinMode(led_ylw, OUTPUT);
  pinMode(led_grn, OUTPUT);

  // initialize the pins as LOW
  digitalWrite(led_red, LOW);
  digitalWrite(led_ylw, LOW);
  digitalWrite(led_grn, LOW);  
}

void loop()
{
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