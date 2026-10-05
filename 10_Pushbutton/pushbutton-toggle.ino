int ledpin = 8;
int butpin = 12;
int dt = 100;

int buttonval1 = 1;

bool clicked;
bool led = false;


void setup() {
  Serial.begin(115200);

  pinMode(ledpin, OUTPUT);
  pinMode(butpin, INPUT);
}

void loop() {
  int buttonval2 = digitalRead(butpin);
  Serial.println(buttonval1);
  if (buttonval1 == 1 && buttonval2 == 0){
    clicked = true;
  }
  else{
    clicked = false;
  }
  
  if (clicked == true){
    if (led == true){
      digitalWrite(ledpin, LOW);
      led = false;
    }
    else{
      digitalWrite(ledpin, HIGH);
      led = true;
    }
  }

  buttonval1 = buttonval2;
  delay(dt);

}








