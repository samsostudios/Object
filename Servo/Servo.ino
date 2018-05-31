#include <Servo.h>

int pot;
int redPin = 3;
int bluePin = 5;
int greenPin = 6;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(9);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot = analogRead(A0);
  int mapPot = map(pot, 0, 1023, 0, 180);
  
  Serial.print("pot: ");
  Serial.println(mapPot);
  
  servo.write(mapPot);
  delay(15);

  if(mapPot >= 0 && mapPot < 60){
    setColor(255, 0, 0);
  }
  else if(mapPot >= 90 && mapPot < 120){
    setColor(255, 200, 0);
  }
  else if(mapPot >= 120 && mapPot <= 180){
    setColor(0, 255, 0);
  }
  
}

void setColor(int redColor, int blueColor, int greenColor){
  analogWrite(redPin, redColor);
  analogWrite(bluePin, blueColor);
  analogWrite(greenPin, greenColor);
}

