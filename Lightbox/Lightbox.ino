int pot1;
int pot2;
int pot3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot1 = analogRead(A5);
  pot2 = analogRead(A4);
  pot3 = analogRead(A3);
  
  int pot1Map = map(pot1, 0, 1023, 0, 255);
  int pot2Map = map(pot2, 0, 1023, 0, 255);
  int pot3Map = map(pot3, 0, 1023, 0, 255);
  
  Serial.print("Pot1: ");
  Serial.println(pot1Map);

  Serial.print("Pot2: ");
  Serial.println(pot2Map);

  Serial.print("Pot3: ");
  Serial.println(pot3Map);
  
  delay(500);
  
}
