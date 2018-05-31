int pot1;
int pot2;
int btnState = 0;

int incoming;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot1 = analogRead(A1);
  pot2 = analogRead(A0);
  btnState = digitalRead(8);
  

  Serial.print(pot1);
  Serial.print(",");
  Serial.print(pot2);
  Serial.print(",");
  Serial.println(btnState);
  //send btnstate as part of your print message
  
  delay(10);

  if(Serial.available() > 0){
    incoming = Serial.read();

    if(incoming == 1){
      digitalWrite(5, HIGH);
    }
    else{
      digitalWrite(5, LOW);
    }
  }

  
}
