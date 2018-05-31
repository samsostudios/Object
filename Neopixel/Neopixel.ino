// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      5

#define BRIGHTNESS 50

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // delay for half a second

int btnState;
int constBtnState = 0;
int changeColorBtn;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.

//  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(2, INPUT);

  pixels.setBrightness(BRIGHTNESS);
}

void loop() {
  btnState = digitalRead(3);
  changeColorBtn = digitalRead(2);
  
  if(btnState == 1 && constBtnState == 0){
    constBtnState = 1;
  }else if (btnState == 1 && constBtnState == 1){
    constBtnState = 0;
  }

  if(constBtnState == 0){
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    
    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
  }else{
    if(changeColorBtn == 0){
      for(int i=0;i<NUMPIXELS;i++){

      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(247,0,90)); // Moderately bright green color.
    
      pixels.show(); // This sends the updated pixel color to the hardware.

      delay(delayval); // Delay for a period of time (in milliseconds).

      }
    }else{
      for(int i=0;i<NUMPIXELS;i++){

      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(38,155,144)); // Moderately bright green color.
    
      pixels.show(); // This sends the updated pixel color to the hardware.

      delay(delayval); // Delay for a period of time (in milliseconds).

      }
    }
  }

}
