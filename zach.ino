#include <FastLED.h>
#define DATA_PIN 6  //this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LEDS 100 //change this for the number of LEDs in the strip
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); //setting up the FastLED
  randomSeed(analogRead(0)); //seeding my random numbers to make it more random.  If you just use the random function it will repeat the same pattern every time it is loaded.
}

void loop() {
  rando();
  delay(3000);
  christmasShift();
  delay(3000);
  lightTest();
  delay(3000);
}

void christmas() {

  FastLED.clear();
  for (int i = 0 ; i < 100 ; i += 3) {
    leds[i] = CRGB::Red;
    leds[i + 1] = CRGB::Green;
    leds[i + 2] = CRGB::Blue;
  }
  FastLED.show();
}

void christmasShift() { 
  FastLED.clear();
  for (int i = 0 ; i < 100 ; i += 3) {
    leds[i] = CRGB::Red;
    leds[i + 1] = CRGB::Green;
    leds[i + 2] = CRGB::Blue;
  }
  FastLED.show();
  delay(1000);
  FastLED.clear();
  for (int i = 0 ; i < 100 ; i += 3) {
    leds[i] = CRGB::Green;
    leds[i + 1] = CRGB::Blue;
    leds[i + 2] = CRGB::Red;
  }
  FastLED.show();
  delay(1000);
  FastLED.clear();
  for (int i = 0 ; i < 100 ; i += 3) {
    leds[i] = CRGB::Blue;
    leds[i + 1] = CRGB::Red;
    leds[i + 2] = CRGB::Green;
  }
  FastLED.show();
  delay(1000);
}

void rando() {
  FastLED.clear();
  for(int i = 0 ; i < 100 ; i++) {
    leds[i] = CRGB (random (0, 255),random (0, 255),random (0, 255));
  }
  FastLED.show();
}

void lightTest() {
  FastLED.clear();
  for (int i = 0 ; i < 100 ; i++) {
    FastLED.clear();
    leds[i] = CRGB::White;
    FastLED.show();
    delay(50);
    FastLED.clear();
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(50);
  }
  FastLED.clear();
}

void clearLights() {
  FastLED.clear();
  for (int i = 0 ; i < 100 ; i++) {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
}
