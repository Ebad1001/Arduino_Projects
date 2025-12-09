// define the component pins
const int IR_B = A1;  // connect the DO pin of the first IR sensor at pin A1
                      // connect its GND pin at GND
                      // connect its VCC pin at 5V
const int IR_A = A0;  // connect the DO pin of the first IR sensor at pin A1
                      // connect its GND pin at GND
                      // connect its VCC pin at 5V
// MOTOR DRIVER       // connect the 12V pin of motor driver with the positive terminal of battery
                      // connect the GND pin of motor driver with the negative terminal of battery & with GND pin of Arduino
                      // connect the 5V pin of motor driver with the Vin pin of Arduino
                      // connect the OUT4 & OUT3 pins of motor driver with left motor
                      // connect the OUT2 & OUT1 pins of motor driver with right motor
const int IN4 = 10;   // connect the IN4 pin of motor driver at pin 10
const int IN3 = 11;   // connect the IN3 pin of motor driver at pin 11
const int IN2 = 12;   // connect the IN2 pin of motor driver at pin 12
const int IN1 = 13;   // connect the IN1 pin of motor driver at pin 13
const int EN_B = 5;   // connect the ENB pin of motor driver at pin 5
const int EN_A = 6;   // connect the ENA pin of motor driver at pin 6

const float percentSpeed = 2.55;

void setup()
{
  // set the pin modes
  pinMode(IR_A, INPUT);
  pinMode(IR_B, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(EN_A, OUTPUT);

  // set speed
  analogWrite(EN_RITE, int(50 * percentSpeed));
  analogWrite(EN_LEFT, int(50 * percentSpeed));

  // initially stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // initialize the serial port
  Serial.begin(9600);
}

void loop()
{
  // take reading from both the IR sensors
  int A = digitalRead(IR_A); 
  int B = digitalRead(IR_B);

  // print sensor readings on Serial monitor
  Serial.print("\nLEFT  = ");
  Serial.print(A);  
  Serial.print("\tRIGHT = ");
  Serial.print(B);

  // if left IR detects white floor, left wheel moves forward
  digitalWrite(IN4, A);
  // if right IR detects white floor, right wheel moves forward
  digitalWrite(IN2, B);
  
  // delay for smooth performance
  delay(100);
}
