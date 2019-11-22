const int heaterPin1 = 3;
int count = 0;
float aT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(heaterPin1, OUTPUT);
  //digitalWrite(heaterPin1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(aT <= 35 && count == 0) {
    digitalWrite(heaterPin1, HIGH); 
  }
  else if (aT <= 36 && count != 0){
    digitalWrite(heaterPin1, HIGH);
  }
  else {
    digitalWrite(heaterPin1, LOW);
  }

 count++;
}
