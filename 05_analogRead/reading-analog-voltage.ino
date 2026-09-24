int readPin = A3;
float v2 = 0;
int delaytime = 500;
int readVal;

void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  readVal = analogRead(readPin);
  v2 = (5./1023.)*readVal;
  Serial.println(v2);
  delay(delaytime);

}
