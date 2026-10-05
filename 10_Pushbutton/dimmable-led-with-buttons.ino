int button1 = 12;
int button2 = 10;

int led = 6;
int buzz = 3;

int lednum = 0;

int dt = 150;
int buzzdelay = 2000;

void setup() {
  Serial.begin(115200);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  int button1val = digitalRead(button1);
  int button2val = digitalRead(button2);

  delay(dt);

  
    if (button2val == 0){
      lednum = lednum + 5;
      if (lednum < 256){
        analogWrite(led, lednum);
      }
      else{
        digitalWrite(buzz, HIGH);
        delay(buzzdelay);
        digitalWrite(buzz, LOW);
        lednum = 255;
      }
    }

    if (button1val == 0){
      lednum = lednum - 5;
      if (lednum > -1){
        analogWrite(led, lednum);
      }
      else{
        digitalWrite(buzz, HIGH);
        delay(buzzdelay);
        digitalWrite(buzz, LOW);
        lednum = 0;
      }
    }

  Serial.println(lednum);


}
