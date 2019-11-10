#include <Adafruit_CharacterOLED.h>

Adafruit_CharacterOLED lcd(OLED_V2, 6, 7, 8, 9, 10, 11, 12);

//temperature 

int ThermistorPin1 = 0;
int ThermistorPin2 = 1;
int V1;
int V2;
float R1 = 100000;
float logR21,logR22, R21, R22, T1, T2;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

float aveTemp(float T1, float T2){
  return (T1+T2)/2;
}


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  //lcd.print("Temp Test");

}

void loop() {
  // put your main code here, to run repeatedly:
  //temperature
  V1 = analogRead(ThermistorPin1);
  V2 = analogRead(ThermistorPin2);
  R21 = R1 * (1023.0 / (float)V1 - 1.0);
  R22 = R1 * (1023.0 / (float)V2 - 1.0);
  logR21 = log(R21);
  logR22 = log(R22);
  T1 = (1.0 / (c1 + c2*logR21 + c3*logR21*logR21*logR21));
  T1 = T1 - 273.15;
  T2 = (1.0 / (c1 + c2*logR22 + c3*logR22*logR22*logR22));
  T2 = T2 - 273.15;
  

  //display
  lcd.setCursor(0, 0);
  //average
  lcd.print("Avg Temp: ");
  lcd.print(aveTemp(T1,T2));
  lcd.print("C");
  lcd.setCursor(0, 1);
  //temp1
  lcd.print("Temp1: ");
  lcd.print(T1);
  lcd.print("C");
  delay(1500);

  lcd.setCursor(0, 0);
  lcd.print("Max Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Temp2: ");
  lcd.print(T2);
  lcd.print("C");
  delay(1500);

  lcd.setCursor(0, 0);
  lcd.print("Min Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Temp3: ");
  //lcd.print("       ");
  delay(1500);
  
}
