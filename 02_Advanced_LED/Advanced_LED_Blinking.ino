void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  //r - 5
  //g - 10
  //b - 15

  for (int i = 0; i<5; i++){
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
  }

  for (int a = 0; a<10; a++){
    digitalWrite(9,HIGH);
    delay(100);
    digitalWrite(9,LOW);
    delay(100);
  }

  for (int b = 0; b<15; b++){
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(8,LOW);
    delay(100);
  }

}
