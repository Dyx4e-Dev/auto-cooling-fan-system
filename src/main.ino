#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

int relay = 8;
 
void setup() {
  lcd.init();
  lcd.backlight();

  dht.begin();

  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
}

void loop() {
  float suhu = dht.readTemperature();

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(suhu);
  lcd.print("C");

  lcd.setCursor(0, 1);

  if (suhu > 30) {
    digitalWrite(relay, HIGH);
    lcd.print("Kipas ON");
  } else {
    digitalWrite(relay, LOW);
    lcd.print("Kipas OFF");
  }

  delay(2000);
}