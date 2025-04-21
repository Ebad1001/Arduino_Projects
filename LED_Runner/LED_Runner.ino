void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(8,LOW);
  
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}

void loop()
{
  int gap = 100;  

  digitalWrite(13, HIGH);
  delay(gap);
  digitalWrite(13, LOW);
  
  digitalWrite(11, HIGH);
  delay(gap);
  digitalWrite(11, LOW);
  
  digitalWrite(9, HIGH);
  delay(gap);
  digitalWrite(9, LOW);
  
  digitalWrite(7, HIGH);
  delay(gap);
  digitalWrite(7, LOW);
  
  digitalWrite(5, HIGH);
  delay(gap);
  digitalWrite(5, LOW);
  
  digitalWrite(3, HIGH);
  delay(gap);
  digitalWrite(3, LOW);
}