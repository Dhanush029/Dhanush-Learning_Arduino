int ledpin = 9;
int readpin = A3;
int readVal;
float V2;
int delayT = 250;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(readpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  readVal = analogRead(readpin);
  V2 = (5./1023.)*readVal;
  Serial.println(V2);
  delay(delayT);
  if (V2 > 4.0){
    digitalWrite(ledpin, HIGH);
  }
  else {
    digitalWrite(ledpin, LOW);
  }

}
