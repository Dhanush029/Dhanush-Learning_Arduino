int thePin = A3;
int readVal;
float V2;
int delayv = 250;

void setup() {
  Serial.begin(9600);

}

void loop() {
  readVal = analogRead(thePin);
  V2 = (5./1023.) * readVal;
  Serial.println(V2);
  delay(delayv);
}
