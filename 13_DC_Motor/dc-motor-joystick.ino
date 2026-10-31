int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int motorspeed = 200;

int ypin = A1;
int yval;


void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(ypin, INPUT);
  Serial.begin(9600);

}

void loop() {
  yval = analogRead(ypin);

  Serial.println(yval);

  if (yval > 512){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    motorspeed = yval * 0.499022 -255.49902;
    analogWrite(speedPin, motorspeed);
  }
  else if (yval < 512){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    motorspeed = yval * -0.498047 + 255.;
    analogWrite(speedPin, motorspeed);
  }
  else{
    analogWrite(speedPin, 0);
  }

  Serial.println(motorspeed);


}
