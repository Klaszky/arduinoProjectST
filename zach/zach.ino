#include <FastLED.h>
#include <HashMap.h>
#define DATA_PIN 6  //this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LEDS 100 //change this for the number of LEDs in the strip
#define COLOR_ORDER RGB




CRGB leds[NUM_LEDS];
const byte HASH_SIZE = 27; 
HashType<char,int> hashRawArray[HASH_SIZE]; 
HashMap<char,int> hashMap = HashMap<char,int>(hashRawArray , HASH_SIZE );
int switchNum = 0;
int wordNum = 0;

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); //setting up the FastLED
  randomSeed(analogRead(0)); //seeding my random numbers to make it more random.  If you just use the random function it will repeat the same pattern every time it is loaded.
  hashMap[0]('a', 27);
  hashMap[1]('b', 25);
  hashMap[2]('c', 23);
  hashMap[3]('d', 21);
  hashMap[4]('e', 19);
  hashMap[5]('f', 17);
  hashMap[6]('g', 15);
  hashMap[7]('h', 34);
  hashMap[8]('i', 35);
  hashMap[9]('j', 37);
  hashMap[10]('k', 38);
  hashMap[11]('l', 40);
  hashMap[12]('m', 41);
  hashMap[13]('n', 43);
  hashMap[14]('o', 44);
  hashMap[15]('p', 46);
  hashMap[16]('q', 48);
  hashMap[17]('r', 71);
  hashMap[18]('s', 70);
  hashMap[19]('t', 69);
  hashMap[20]('u', 68);
  hashMap[21]('v', 67);
  hashMap[22]('w', 65);
  hashMap[23]('x', 64);
  hashMap[24]('y', 63);
  hashMap[25]('z', 61);
  hashMap[26](' ', 99);
  
}

void loop() {
  switch(switchNum){
    case 0:
      for(int i = 0 ; i < 10 ; i ++ ) {
        christmasShift();  
      }
      break;
    case 1:
      wordTest("waffels ");
      delay(100);
      break;
    case 2:
      wordTest("wu tang clan aint nothing to fuck with ");
      delay(100);
      break;
    case 3:
      wordTest("happy b day zach ");
      delay(100);
      break;
    case 4:
      wordTest("the street fists ");
      delay(100);
      break;
    case 5:
      wordTest("run run run run   ");
      delay(100);
      break;
    case 6:
      wordTest("justice for barb ");
      delay(100);
      break;
    case 7:
      wordTest("we have to find will ");
      delay(100);
      break;
    case 8:
      wordTest("demogorgon ");
      delay(100);
      break;
    case 9:
      for(int i = 0 ; i < 10 ; i ++ ) {
        christmasShift();  
      }
      break;
    default:
      christmas();
//      delay(600000);
      delay(300000);
      break;
  }
  switchNum = random(0, 20);
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

void letterTest() {
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i = 0 ; i < sizeof(letters) ; i++){
      flicker(hashMap.getValueOf(letters[i]));
    }
}

void wordTest(String myWord) {
  char buf[myWord.length()+1];
  myWord.toCharArray(buf, myWord.length()+1);
  for(int i = 0 ; i < sizeof(buf) ; i++) {
    flicker(hashMap.getValueOf(buf[i]));
  }
}

void christmasShift() { 
  FastLED.clear();
  for (int i = 0 ; i < 100 ; i += 3) {
    leds[i] = CRGB::Red;
    leds[i + 1] = CRGB::Green;
    leds[i + 2] = CRGB::Blue;
  }
  FastLED.show();
  delay(800);
  FastLED.clear();
  for (int i = 0 ; i < 100 ; i += 3) {
    leds[i] = CRGB::Green;
    leds[i + 1] = CRGB::Blue;
    leds[i + 2] = CRGB::Red;
  }
  FastLED.show();
  delay(800);
  FastLED.clear();
  for (int i = 0 ; i < 100 ; i += 3) {
    leds[i] = CRGB::Blue;
    leds[i + 1] = CRGB::Red;
    leds[i + 2] = CRGB::Green;
  }
  FastLED.show();
  delay(800);  
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
  for (int i = 15 ; i < 72 ; i++) {
    FastLED.clear();
    leds[i] = CRGB(random(1,255), random(1, 255), random(1, 255));
    FastLED.show();
    delay(10);
    FastLED.clear();
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(10);
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

void flicker(int led) {
  if(led == 99) {
    randomAssortment();
  } else {
    for(int i = 0 ; i < random(1,5) ; i++){
      FastLED.clear();
      leds[led] = CRGB::Red;
      FastLED.show();
      delay(random(50,150));
      FastLED.clear();
      leds[led] = CRGB::Black;
      FastLED.show();
      delay(100);
    }
    FastLED.clear();
    leds[led] = CRGB::Red;
    FastLED.show();
    delay(random(500, 1000)); 
  }
}

void randomAssortment(){
  int randomInt;
  for (int i = 0 ; i < random(15, 20) ; i++) {
    randomInt = random(15, 72);
    FastLED.clear();
    leds[randomInt] = CRGB(random(1,255), random(1,255), random(1,255));
    FastLED.show();
    delay(10);
    FastLED.clear();
    leds[randomInt] = CRGB(0, 0, 0);
    FastLED.show();
    delay(10);
  }
}
