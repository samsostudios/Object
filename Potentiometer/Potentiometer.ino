int pot;      //potentioemeter in A0
int light;    //light sensor in A1
int brightness; //used for dimming LED

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot = analogRead(A0);
  light = analogRead(A1);
  
  Serial.print("pot: ");
  Serial.println(pot);

  Serial.print("light: ");
  Serial.println(light);

//  delay(1000);

  brightness = map(pot, 0, 1023, 0, 255);
  analogWrite(3, brightness);
  
}
