#include "DHT.h"
#define Type DHT11
#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
 
int dhtpin=2;
DHT HT(dhtpin,Type);
float humidity;
float tempC;
float tempF;
int dt=250;
 
void setup() {
  Serial.begin(115200);
  HT.begin();
  lcd.begin(16,2);
}
 
void loop() {
  humidity=HT.readHumidity();
  tempC=HT.readTemperature();
  tempF=HT.readTemperature(true);

  lcd.print("Hum: " + String(humidity) +"%");
  lcd.setCursor(0,1);
  lcd.print("Temp: " + String(tempC));
  lcd.write(223);
  lcd.print("C");

  delay(dt);

  lcd.clear();

  Serial.println(humidity);
  Serial.println(tempC);
  Serial.println(tempF);
  Serial.println();
  
 
 
}