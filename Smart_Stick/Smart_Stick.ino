int trigPin = 6;
int echoPin = 7;
int buzz = 8;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(buzz,OUTPUT);
  digitalWrite(buzz,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  delay(50);
  Serial.print("Distance:");
  Serial.println(distance);
  if(distance<20){
    digitalWrite(buzz, HIGH);
  }
  else{
    digitalWrite(buzz, LOW);
  }
  delay(100);
}
