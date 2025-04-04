int pinMap[7] = { 3, 2, 6, 8, 7, 4, 5 };
int digit[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 0, 0, 1 },
  { 0, 1, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 },
};
void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(pinMap[i], OUTPUT);
  }
}
void display(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(pinMap[i], digit[num][i]);
  }
}
int num = 0;
void loop() {
  display(num);
  num += 1;
  num %= 10;
  delay(1000);

}