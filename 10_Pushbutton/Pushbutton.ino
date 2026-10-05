int ledpin = 8;
int butpin = 12;


void setup() {
  Serial.begin(9600);

  pinMode(ledpin, OUTPUT);
  pinMode(butpin, INPUT);
}

void loop() {
  int buttonval = digitalRead(butpin);

  if (buttonval == 0){
    digitalWrite(ledpin, HIGH);
  }
  else {
    digitalWrite(ledpin, LOW);
  }

}
