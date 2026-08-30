int led1 = 6;
int led2 = 5;
int led3 = 4;
int led4 = 3;
int led5 = 2;

int count = 1;
int wait = 500;

// for the purpose of the LED counter, I have reversed the LED numbering order with the pin numbering order


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {

  digitalWrite(led1, count & 1);
  digitalWrite(led2, count & 2);
  digitalWrite(led3, count & 4);
  digitalWrite(led4, count & 8);
  digitalWrite(led5, count & 16);

  delay(wait);

  count = count + 1;
  if (count > 31){
    count = 0;
  }
}
