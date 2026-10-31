int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int motorspeed = 200;

int tiltpin = 2;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(tiltpin, INPUT);
  digitalWrite(tiltpin, HIGH);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);

  int tiltval = digitalRead(tiltpin);
  Serial.println(tiltval);
  if (tiltval == 0){
    analogWrite(speedPin, motorspeed);
  }
  if (tiltval == 1){
    analogWrite(speedPin, 0);
  }

}
