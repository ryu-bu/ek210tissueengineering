#include <Adafruit_CharacterOLED.h>

Adafruit_CharacterOLED lcd(OLED_V2, 6, 7, 8, 9, 10, 11, 12);

void getTemp();
void tempCont();

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  //lcd.print("Temp Test");

}

void loop() {
  // put your main code here, to run repeatedly:
  tempCont();
  getTemp();
  
}

void tempCont(){
  lcd.setCursor(0, 0);
  lcd.print("Avg Temp: ");
  delay(4000);

  lcd.setCursor(0, 0);
  lcd.print("Max Temp: ");
  delay(4000);

  lcd.setCursor(0, 0);
  lcd.print("Min Temp: ");
  delay(4000);
  
}
void getTemp(){
  lcd.setCursor(0, 1);
  lcd.print("Temp1: ");
  delay(3000);
  
  lcd.setCursor(0, 1);
  lcd.print("Temp2: ");
  delay(3000);
  
  lcd.setCursor(0, 1);
  lcd.print("Temp3: ");
  delay(3000);
}
