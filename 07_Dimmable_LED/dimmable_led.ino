int potPin = A2;
int ledPin = 10;
float potVal;
float ledVal;


void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  potVal = analogRead(potPin);
  ledVal = (255./1023.) * potVal;
  analogWrite(ledPin, ledVal);
  Serial.println(ledVal);
}
