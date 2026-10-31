int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte LEDs = 0b00000001;
int dt = 100;

void setup() {
  Serial.begin(115200);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
  digitalWrite(latchPin, HIGH);

  //LEDs = LEDs/128 + LEDs*2;
  LEDs = LEDs*128 + LEDs/2;

  Serial.println(LEDs, BIN);
  delay(dt);

}
