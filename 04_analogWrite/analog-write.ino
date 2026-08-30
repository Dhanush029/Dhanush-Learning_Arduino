int thePin = 9;
int delayt = 20;

void setup() {
  pinMode(thePin, OUTPUT);

}

void loop() {
  
  for (int i = 0; i<100; i++){
    analogWrite(thePin, i);
    delay(delayt);
  } 
    
  for (int x = 99; x>-1; x--){
    analogWrite(thePin, x);
    delay(delayt);
  }
  

}
