#include <Servo.h>

int servpin = 9;
int servpos;

Servo myServo;

void setup() {
  myServo.attach(servpin);
  Serial.begin(115200);

}

void loop() {
  Serial.println("Enter servo turn degree");

  while (Serial.available() == 0){
  }

  servpos = Serial.parseInt();
  myServo.write(servpos);

}
