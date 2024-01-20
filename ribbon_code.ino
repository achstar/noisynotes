#include <AutoMap.h>
#include <FastLED.h>

#define RIBBON_PIN A0
#define FORCE_PIN A1
#define SPEAKER_PIN 9

#define LED_PIN     7
#define NUM_LEDS    30

CRGB leds[NUM_LEDS];
// minimum and maximum freq range
const int MIN_FREQ = 130;
const int MAX_FREQ = 550;

AutoMap mapRibbonFreq(1, 1023, MAX_FREQ, MIN_FREQ);
AutoMap mapLEDs(1, 1023, NUM_LEDS, 0);

int song[] = {1, 1, 5, 5, 7, 7, 5, 4, 4, 3, 3, 2, 2, 1, 5, 5, 4, 4, 3, 3, 2, 5, 5, 4, 4, 3, 3, 2, 1, 1, 5, 5, 7, 7, 5, 4, 4, 3, 3, 2, 2, 1};
int note = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(analogRead(FORCE_PIN));
  // delay(100);
  // noTone(SPEAKER_PIN);
  int location = analogRead(RIBBON_PIN);
  Serial.println("freq: " + String(mapRibbonFreq(location)) + " LEDs: " + String(mapLEDs(location)));
  if (location == 0) {
    leds[song[note]] = CRGB(255, 255, 255);

    FastLED.show();
    noTone(SPEAKER_PIN);
  } else if (song[note] == mapLEDs(location)) {
    leds[song[note]] = CRGB(0, 255, 0);

    FastLED.show();
    delay(100);
    leds[song[note]] = CRGB::Black;
    FastLED.show();
    if (note < 41) {
      note++;
    }
    else {
      note = 0;
    }
    tone(SPEAKER_PIN, mapRibbonFreq(location));
  }
  else {
    // leds[song[note]] = CRGB(255, 0, 0);
    // FastLED.show();
    tone(SPEAKER_PIN, mapRibbonFreq(location));
  }
  
}
