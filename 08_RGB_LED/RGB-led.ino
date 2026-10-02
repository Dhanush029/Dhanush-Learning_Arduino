int rpin = 9;
int gpin = 10;
int bpin = 11;

String colour;

void setup() {
  Serial.begin(9600);
  pinMode(rpin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(gpin, OUTPUT);

}

void loop() {
  Serial.println("Enter an LED colour");

  while (Serial.available() == 0){}

  colour = Serial.readString();
  colour.trim();
  colour.toLowerCase();
  

  if (colour == "red"){
    digitalWrite(rpin, HIGH);
    digitalWrite(gpin, LOW);
    digitalWrite(bpin, LOW);
  } 

  if (colour == "green"){
    digitalWrite(rpin, LOW);
    digitalWrite(gpin, HIGH);
    digitalWrite(bpin, LOW);
  } 

  if (colour == "blue"){
    digitalWrite(rpin, LOW);
    digitalWrite(gpin, LOW);
    digitalWrite(bpin, HIGH);
  } 

  if (colour == "off"){
    digitalWrite(rpin, LOW);
    digitalWrite(gpin, LOW);
    digitalWrite(bpin, LOW);
  } 
  
}
