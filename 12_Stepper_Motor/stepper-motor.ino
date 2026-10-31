#include <Stepper.h>

int steps = 2048;
int speed = 7;

int buttonpin = 4;
int buttonnew;
int buttonold;

int stepnum = 1;

Stepper myStepper(steps, 8, 10, 9, 11);

void setup() {
  Serial.begin(115200);
  myStepper.setSpeed(speed);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  buttonnew = digitalRead(buttonpin);
  Serial.println(buttonnew);

  if (buttonnew == 0 && buttonold == 1){
    stepnum = -stepnum;
  }

  buttonold = buttonnew;

  myStepper.step(stepnum);
}
