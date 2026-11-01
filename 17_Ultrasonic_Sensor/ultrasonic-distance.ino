int trig = 10;
int echo = 8;
int time;
float distance;
float soundspeed = 0.0343; //speed of sound in cm per microsecond

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH);
  delay(25);
  distance = soundspeed * (time / 2.);
  Serial.print(distance);
  Serial.println(" cm");

}

