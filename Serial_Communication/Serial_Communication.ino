
int pot1;
int pot2;

//incoming data from p5
int incoming;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT); //LED pins
  pinMode(5, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  pot1 = analogRead(A1);
  pot2 = analogRead(A0);

  Serial.print(pot1);
  Serial.print(",");
  Serial.println(pot2);
  delay(1);

  //INCOMING SERIAL DATA
  //check if there is serial data, read if there is data
  if(Serial.available() > 0){
    incoming = Serial.read();
    
    //listen for H pressed
    if(incoming  == 'H'){
      digitalWrite(5, HIGH);
    }
    //listen for L pressed
    if(incoming  == 'L'){
      digitalWrite(5, LOW);
    }

    else if(incoming >= 0 && incoming < 256){
      analogWrite(9, incoming); //setting brightness of LED from incoming P5 data
    }
    
  }
  
}
