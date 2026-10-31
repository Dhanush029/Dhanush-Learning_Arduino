#include <Servo.h>

int joyX = A1;
int joyY = A2;
int pinS = 7;
int ledpin = 8;

Servo servoX;

int ServPin = 10;

int dt = 50;

void setup() {
  Serial.begin(115200);
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  pinMode(pinS, INPUT);
  pinMode(ledpin, OUTPUT);

  servoX.attach(ServPin);
  digitalWrite(pinS, HIGH);
  

}

void loop() {

  int Xval = analogRead(joyX);
  int Sval = digitalRead(pinS);
  Serial.print("X val = ");
  Serial.print(Xval);
  Serial.print(" Switch is = ");
  Serial.println(Sval);

  int servoturn = (180./1023.)*Xval;

  servoX.write(servoturn);

  if (Sval == 0){
    digitalWrite(ledpin, HIGH);
  }
  else {
    digitalWrite(ledpin, LOW);
  }

  delay(dt);
  

}
