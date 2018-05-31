#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>

int rotate;
int down;
int downState;
int left;
int leftState;
int right;
int rightState;
int start;
//
//int shapeState = 1;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 17, 8,
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  
  matrix.begin();
  matrix.setBrightness(100);
  matrix.setTextColor( matrix.Color(255, 255, 255) );
  matrix.setTextWrap(false);

}

void loop() {
  down = digitalRead(3);
  left = digitalRead(10);
  start = digitalRead(4);

//  Serial.println(downState);

  if(down == 1){
    downFunc();
  }
  if(start == 1){
    generateShape();
  }
  
  if(left == 1){
    if(right == 0){
      leftState = 0;
    }
    delay(200);
    leftState += 1;
    rightState = 1;
    
    if(leftState >= 6){
      leftState = 6;
    }
  }

  if(right == 1){
    delay(200);
    rightState += 1;
    leftState = 0;

    if(rightState >=6){
      rightState = 6;
    }
  }

//  Serial.print(" right: ");
//  Serial.println(rightState);
//  delay(300);
  
//  shape1(downState, rightState, leftState);
//  shape2();
}


void generateShape(){
  int randShape = random(0, 1) % 1;
  Serial.print("random: ");
  Serial.println(randShape);

  switch(randShape){
    case 0:
      shape1(downState, rightState, leftState);
      break;
    case 1:
      shape2();
      break;
  }

}

void downFunc(){
  Serial.println("in down: ");
  downState += 1;
  

  if(downState >=15){
      downState = 15;

//      generateShape();
      //nextShape();
      //generate a random random(0, 5) shape outside of loop() - in a function 
      //set global state to whatever the new shape is
    }
}


void shape1(int down, int right, int left){
  Serial.println("in shape1: ");
  clear();
  int downStep = down;
  int rightStep =  right;
  int leftStep = left;

  int led1[2] = {0, 0 + downStep};
  int led2[2] = {0, 1 + downStep};
  int led3[2] = {0, 2 + downStep};
  int led4[2] = {1, 1 + downStep};

  showStuff(led1, led2, led3, led4);
}

void shape2(){
  int led1[2] = {0, 2};
  int led2[2] = {0, 1};
  int led3[2] = {1, 1};
  int led4[2] = {0, 1};
  
}

void showStuff(int* showled1, int* showled2, int* showled3, int* showled4){
  Serial.println("in show: ");
  int l1x = showled1[0];
  int l1y = showled1[1];
  
  int l2x = showled2[0];
  int l2y = showled2[1];
  
  int l3x = showled3[0];
  int l3y = showled3[1];
  
  int l4x = showled4[0];
  int l4y = showled4[1];

  matrix.drawPixel(l1x, l1y, matrix.Color(225, 0, 0));
  matrix.drawPixel(l2x, l2y, matrix.Color(225, 0, 0));
  matrix.drawPixel(l3x, l3y, matrix.Color(225, 0, 0));
  matrix.drawPixel(l4x, l4y, matrix.Color(225, 0, 0));
  matrix.show();
  
}

void clear(){
  int rows = 8;
  int cols = 18;

  for(int i = 0; i <= rows; i++){
    for(int j = 0; j <= cols; j++){
      matrix.drawPixel(i, j, matrix.Color(0, 0, 0));
    }
  }
}

