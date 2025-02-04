#include <Adafruit_CharacterOLED.h>

Adafruit_CharacterOLED lcd(OLED_V2, 6, 7, 8, 9, 10, 11, 12);

//temperature 

const int ThermistorPin1 = 0;
const int ThermistorPin2 = 1;
const int ThermistorPin3 = 2;
const int ThermistorPin4 = 3;
int V1, V2, V3, V4;
const float R1 = 100000;
float T1, T2, T3, T4;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

float aveTemp(float T1, float T2, float T3, float T4){
  return (T1+T2+T3+T4)/4;
}

float calcTemp(int Vo){
  float R2 = R1 * (1023.0 / (float)Vo - 1.0);
  float logR = log(R2);
  float T = (1.0 / (c1 + c2*logR + c3*logR*logR*logR));
  float Tc = T - 273.15;

  return Tc;
}

void printTemp(int n, float T){
  lcd.setCursor(0, 1);
  if (n == 1){
    lcd.print("Temp1: ");
  }
  else if (n == 2){
    lcd.print("Temp2: ");
  }
  else if (n == 3){
    lcd.print("Temp3: ");
  }
  else {
    lcd.print("Temp4: ");
  }
  lcd.print(T);
  lcd.print("C");
}

void printStuff(int n, float val){
  lcd.setCursor(0, 0);
  if (n == 1){
    lcd.print("Ave Temp: ");
  }
  else if (n == 2){
    lcd.print("Max Temp: ");
  }
  else {
    lcd.print("Min Temp: ");
  }
  lcd.print(val);
  lcd.print("C");
}

float maxTemp(float T1, float T2, float T3, float T4){
  float maxT = T1;
  float maxArray[4] = {T1, T2, T3, T4};
  for (int i = 0; i < 4; i++){
    if (maxArray[i] > maxT){
      maxT = maxArray[i];
    }
  }
  
  return maxT;
}

float minTemp(float T1, float T2, float T3, float T4){
  float minT = T1;
  float minArray[4] = {T1, T2, T3, T4};
  for (int i = 0; i < 4; i++){
    if (minArray[i] < minT){
      minT = minArray[i];
    }
  }

  return minT;
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
  V3 = analogRead(ThermistorPin3);
  V4 = analogRead(ThermistorPin4);
  
  T1 = calcTemp(V1);
  T2 = calcTemp(V2);
  T3 = calcTemp(V3);
  T4 = calcTemp(V4);

  float aT = aveTemp(T1,T2,T3,T4);
  
  printStuff(1, aT);
  printTemp(1, T1);
  delay(1500);

  printStuff(1, aT);
  printTemp(2, T2);
  delay(1500);
  
  printStuff(2, maxTemp(T1,T2,T3,T4));
  printTemp(3, T3);
  delay(1500);

  printStuff(3, minTemp(T1,T2,T3,T4));
  printTemp(4, T4);
  delay(1500);
 
  
}
