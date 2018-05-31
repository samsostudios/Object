#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            12
#define NUMPIXELS      5

#define PIN2            8
#define NUMPIXELS2      19

#define PIN3            13
#define NUMPIXELS3      5

#define BRIGHTNESS 255

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsLong = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsShort = Adafruit_NeoPixel(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);

int delayval = 100;

int pot1;
int pot2;
int pot3;
int color;


void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixelsLong.begin();
  pixelsShort.begin();
  pixels.setBrightness(BRIGHTNESS);
  pixelsLong.setBrightness(BRIGHTNESS);
  pixelsShort.setBrightness(BRIGHTNESS);
//  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot1 = analogRead(A5);
  pot2 = analogRead(A4);
  pot3 = analogRead(A3);

  int pot1Map = map(pot1, 0, 1023, 0, 255);
  int pot2Map = map(pot2, 0, 1023, 0, 255);
  int pot3Map = map(pot3, 0, 1023, 0, 255);

  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(pot1Map,pot2Map,pot3Map));
    pixels.show();

    pixelsShort.setPixelColor(i, pixelsShort.Color(pot1Map,pot2Map,pot3Map));
    pixelsShort.show();

    delay(delayval);

  }

  for(int i=0;i<NUMPIXELS2;i++){

    pixelsLong.setPixelColor(i, pixelsLong.Color(pot1Map,pot2Map,pot3Map));
    pixelsLong.show();

    delay(delayval);

  }

//  Serial.print("pot1: ");
//  Serial.println(pot1);

}
