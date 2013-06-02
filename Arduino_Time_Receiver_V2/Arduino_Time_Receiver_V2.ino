#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 28, 29, 30, 31);

char buffer[8];

void setup() {
 Serial.begin(9600);
 lcd.begin(4, 20);
 lcd.clear();
}

void loop() {
  getTime();
  lcd.setCursor(0, 0);
  lcd.print(int(buffer[2]));
  lcd.setCursor(2, 0);
  lcd.print(int(buffer[1]));
  lcd.setCursor(4, 0);
  lcd.print(int(buffer[0]));
}


void getTime() {
 if (Serial.available() > 0) {
   digitalWrite(13, HIGH);
    Serial.readBytes(buffer, 8);
  }
}
