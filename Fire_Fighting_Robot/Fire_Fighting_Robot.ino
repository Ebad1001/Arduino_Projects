class Reading {
    public:
    int value;
    bool has_no_flame;
    bool is_too_close;
    bool is_close_enough;
    bool is_too_far;
    Reading(int value) {
        this->value = value;
        this->is_too_close = (this->value < 300);                           //    0 -  300 : too close
        this->is_close_enough = (300 <= this->value && this->value < 600);  //  300 -  600 : ideal range
        this->is_too_far = (600 <= this->value && this->value < 1000);      //  600 - 1000 : need to move closer
        this->has_no_flame = (1000 <= this->value);                         // 1000 - 1023 : no flame
    }
    bool is_closer_than(Reading other) {
      return (this->value) < (other.value);
    }
};

const int IR_LEFT = A2;
const int IR_CNTR = A1;
const int IR_RITE = A0;
const int IN4 = 10;
const int IN3 = 11;
const int IN2 = 12;
const int IN1 = 13;
const int EN_RITE = 5;
const int EN_LEFT = 6;
const int PUMP = 3;

const float percentSpeed = 2.55;
const int STOP          =  0; // 0 0 0 0
const int FORWARD       = 10; // 1 0 1 0
const int BACKWARD      =  5; // 0 1 0 1
const int IN_PLACE_LEFT =  9; // 1 0 0 1
const int IN_PLACE_RITE =  6; // 0 1 1 0
const int FORWARD_LEFT  =  8; // 1 0 0 0
const int FORWARD_RITE  =  2; // 0 0 1 0
const int BACKWARD_LEFT =  1; // 0 0 0 1
const int BACKWARD_RITE =  4; // 0 1 0 0

void move(int direction, int interval = 0)
{
  digitalWrite(IN1, (direction & 8) / 8);
  digitalWrite(IN2, (direction & 4) / 4);
  digitalWrite(IN3, (direction & 2) / 2);
  digitalWrite(IN4, (direction & 1) / 1);
  delay(interval);
}

void setup()
{
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_CNTR, INPUT);
  pinMode(IR_RITE, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN_LEFT, OUTPUT);
  pinMode(EN_RITE, OUTPUT);
  pinMode(PUMP, OUTPUT);
  Serial.begin(9600);

  analogWrite(EN_RITE, int(30 * percentSpeed));
  analogWrite(EN_LEFT, int(30 * percentSpeed));
}

void loop()
{
  int one_second = 1000;
  Reading LEFT = Reading(analogRead(IR_LEFT));
  Reading CNTR = Reading(analogRead(IR_CNTR));
  Reading RITE = Reading(analogRead(IR_RITE));
  digitalWrite(PUMP, LOW);
  Serial.print("\nLEFT = ");
  Serial.print(LEFT.value);
  Serial.print("\tCNTR = ");
  Serial.print(CNTR.value);
  Serial.print("\tRITE = ");
  Serial.print(RITE.value);

  while(LEFT.has_no_flame &&
        CNTR.has_no_flame &&
        RITE.has_no_flame) {
    // there's no flame in the range
    // rotate in place
    Serial.print("\nNo flame detected.");
    move(IN_PLACE_LEFT, one_second);
    move(STOP, one_second);
    LEFT = Reading(analogRead(IR_LEFT));
    CNTR = Reading(analogRead(IR_CNTR));
    RITE = Reading(analogRead(IR_RITE));
  }

  bool at_safe_distance = true;
  if (LEFT.is_too_close) {
    Serial.print("\nWe're too close (L).");
    move(BACKWARD_LEFT, one_second);
    at_safe_distance = false;
  }
  if (CNTR.is_too_close) {
    Serial.print("\nWe're too close (C).");
    move(BACKWARD, one_second);
    at_safe_distance = false;
  }
  if (RITE.is_too_close) {
    Serial.print("\nWe're too close (R).");
    move(BACKWARD_RITE, one_second);
    at_safe_distance = false;
  }
  if(at_safe_distance) {
    bool need_to_move = true;
    if(CNTR.is_close_enough) {
      need_to_move = false;
      Serial.print("\nShoot the water >>");
      digitalWrite(PUMP, HIGH);
      delay(3*one_second);
      digitalWrite(PUMP, LOW);
    }
    if(need_to_move) {
      if(LEFT.is_closer_than(CNTR) && LEFT.is_closer_than(RITE)) {
        Serial.print("\nNeed to move a little LEFT.");
        move(FORWARD_LEFT, one_second);
      }
      else if(RITE.is_closer_than(CNTR) && RITE.is_closer_than(LEFT)) {
        Serial.print("\nNeed to move a little RITE.");
        move(FORWARD_RITE, one_second);
      }
      else {
        Serial.print("\nNeed to move a little FORWARD.");
        move(FORWARD, one_second);
      }
    }
    delay(100);
  }
}
