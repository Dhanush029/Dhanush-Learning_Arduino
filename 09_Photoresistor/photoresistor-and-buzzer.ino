int buzzpin = 11;
int photopin = A1;

int dt;

void setup() {
  Serial.begin(9600);

  pinMode(buzzpin, OUTPUT);
  pinMode(photopin, INPUT);

}

void loop() {
  int output = analogRead(photopin);
  Serial.println(output);

  int dt = output * (3./100.) - 20.;

  digitalWrite(buzzpin, HIGH);
  delay(dt);
  digitalWrite(buzzpin, LOW);
  delay(dt);


}
