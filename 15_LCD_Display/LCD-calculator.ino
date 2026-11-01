#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

bool done = false;
float answer;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(115200);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("First Number :");
  while (Serial.available()==0){}
  float firstnum = Serial.parseFloat();
  lcd.setCursor(0, 1);
  lcd.print(firstnum);

  delay(500);
  lcd.clear();

  lcd.print("Second Number :");
  while (Serial.available()==0){}
  float secondnum = Serial.parseFloat();
  lcd.setCursor(0, 1);
  lcd.print(secondnum);

  delay(500);
  lcd.clear();

  lcd.print("Enter operator :");
  while (Serial.available()==0){}
  String op = Serial.readString();
  lcd.setCursor(0, 1);
  lcd.print(op);

  delay(500);
  lcd.clear();

  if (op == "+"){
    answer = firstnum + secondnum;
    done = true;
  }
  else if (op == "-"){
    answer = firstnum - secondnum;
    done = true;
  }
  else if (op == "*"){
    answer = firstnum*secondnum;
    done = true;
  }
  else if (op == "/"){
    if (secondnum == 0) {
      lcd.print("ERROR");
      lcd.setCursor(0, 1);
      lcd.print("Division by Zero");
      delay(2000);
      lcd.clear();
    } else {
      answer = firstnum / secondnum;
      done = true;
    }
  }
  else{
    lcd.print("Invalid operator");

    delay(500);
    lcd.clear();
  }

  if (done == true){
    String printval = String(firstnum) + " " + op + " " + String(secondnum) + " " + "=";
    lcd.print(printval);
    lcd.setCursor(0, 1);
    lcd.print(answer);

    delay(3000);
    lcd.clear();
    done = false;
  }


}
