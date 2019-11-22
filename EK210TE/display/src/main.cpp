
#include "../lib/Adafruitdisplay/Adafruit_CharacterOLED.h"
#include <Arduino.h>

Adafruit_CharacterOLED lcd(OLED_V2, 6, 7, 8, 9, 10, 11, 12);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  //lcd.print("Temp Test");

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Avg Temp1: ");
  lcd.setCursor(0, 1);
  lcd.print("Temp1: ");
  delay(3000);

  lcd.setCursor(0, 0);
  lcd.print("Max Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Temp2: ");
  delay(3000);

  lcd.setCursor(0, 0);
  lcd.print("Min Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Temp3: ");
  delay(3000);

}
