class Reading {
    public:
    int value;
    Reading(int value) {
        this->value = value;
    }
    bool is_invalid() {
        return (value < 1000 || 2000 < value);
    }
    bool is_low() {
        return (1000 < value && value < 1250);
    }
    bool is_mid() {
        return (1250 < value && value < 1750);
    }
    bool is_high() {
        return (1750 < value && value < 2000);
    }
};

// Fwd Motor Driver connects with the two wheels in front
const int IN1 = A2; // IN1 & IN2 are for left fwd motor
const int IN2 = A3;
const int IN3 = A4; // IN3 & IN4 are for right fwd motor
const int IN4 = A5;
const int EN1 = 3;
const int EN2 = 5;

// Bck Motor Driver connects with the two wheels in back
const int IN5 = 6; // IN5 & IN6 are for left bck motor
const int IN6 = 7;
const int IN7 = 8; // IN7 & IN8 are for right bck motor
const int IN8 = 9;
const int EN3 = 10;
const int EN4 = 11;

// RC Receiver Channels
const int CH1 = A0; // for steering
const int CH2 = A1; // for throttle
const int CH3 = 13; // for speed

// pins in arrays for easy access
const int IN_pins[] = {IN1, IN2, IN3, IN4, IN5, IN6, IN7, IN8};
const int EN_pins[] = {EN1, EN2, EN3, EN4};
const int CH_pins[] = {CH1, CH2, CH3};

// direction constants
const int stop = 0;     // 00 00
const int forward = 10; // 10 10
const int backward = 5; // 01 01
const int left = 2;     // 00 10
const int right = 8;    // 10 00

void move(int direction) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(IN_pins[i + 0], direction & (1 << i));
        digitalWrite(IN_pins[i + 4], direction & (1 << i));
    }
}

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 8; i++) {
        pinMode(IN_pins[i], OUTPUT);
    }
    for (int i = 0; i < 4; i++) {
        pinMode(EN_pins[i], OUTPUT);
    }
    for (int i = 0; i < 3; i++) {
        pinMode(CH_pins[i], INPUT);
    }
    move(stop); // Initial state
}

void loop() {
    Reading steering(pulseIn(CH1, 1));
    Reading throttle(pulseIn(CH2, 1));
    Reading    speed(pulseIn(CH3, 1));

    Serial.print("\nSteering: ");
    Serial.print(steering.value);
    Serial.print("\tThrottle: ");
    Serial.print(throttle.value);
    Serial.print("\tSpeed: ");
    Serial.print(speed.value);

    speed.value = map(speed.value, 1000, 2000, 0, 255); // speed
    analogWrite(EN1, speed.value);
    analogWrite(EN2, speed.value);
    analogWrite(EN3, speed.value);
    analogWrite(EN4, speed.value);

    if (steering.is_invalid() || throttle.is_invalid()) {
        Serial.print("\nDead zone.");
        move(stop);
    }
    else if (throttle.is_high() && steering.is_mid()) {
        Serial.print("\nMove Forward");
        move(forward);
    }
    else if (throttle.is_low() && steering.is_mid()) {
        Serial.print("\nMove Backward");
        move(backward);
    }
    else if (steering.is_low() && throttle.is_mid()) {
        Serial.print("\nMove Left");
        move(left);
    }
    else if (steering.is_high() && throttle.is_mid()) {
        Serial.print("\nMove Right");
        move(right);
    }
    else {
        Serial.print("\nYour are using throttle and steering at the same time.");
        move(stop);
    }
    delay(50); // small delay for stability
}
