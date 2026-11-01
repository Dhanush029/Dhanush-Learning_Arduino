#include <LiquidCrystal.h>

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int trig = 4;
int echo = 5;
int time;
float distance;
float total;
float soundspeed = 0.0343; //speed of sound in cm per microsecond

int buttonpin = 2;
int buttonnum;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buttonpin, INPUT_PULLUP);
  lcd.begin(16,2);
  Serial.begin(115200);
}

void loop() {
  lcd.print("Press button");
  lcd.setCursor(0, 1);
  lcd.print("to measure");
  buttonnum = digitalRead(buttonpin);
  while (buttonnum == 1){
    buttonnum = digitalRead(buttonpin);
  }
  lcd.clear();

  for (int i = 1; i <= 50; i++){
    digitalWrite(trig, LOW);
    delayMicroseconds(10);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    time = pulseIn(echo, HIGH);
    delay(25);

    total = total + soundspeed * (time / 2.);
  }

  distance = total / 50.;

  Serial.print("Total - ");
  Serial.println(total);
  Serial.print("distance - ");
  Serial.println(distance);

  total = 0;

  lcd.print("Object distance: ");
  lcd.setCursor(0, 1);
  lcd.print(String(distance) + " cm");
  delay(3750);
  lcd.clear();

}


