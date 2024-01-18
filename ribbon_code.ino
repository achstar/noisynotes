#include <AutoMap.h>

#define RIBBON_PIN A0
#define FORCE_PIN A1
#define SPEAKER_PIN 9

#define LED_PIN     7
#define NUM_LEDS    30

CRGB leds[NUM_LEDS];
// minimum and maximum freq range
const int MIN_FREQ = 130;
const int MAX_FREQ = 500;

AutoMap mapRibbonFreq(1, 1023, MAX_FREQ, MIN_FREQ);
AutoMap mapLEDs(1, 1023, 1, NUM_LEDS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(analogRead(FORCE_PIN));
  // delay(100);
  // noTone(SPEAKER_PIN);
  int location = analogRead(RIBBON_PIN);
  Serial.println(location);
  if (location == 0) {
    noTone(SPEAKER_PIN);
  }
  else {
    leds[mapLEDs(location)] = CRGB(0, 255, 0);
    tone(SPEAKER_PIN, mapRibbonFreq(location));
  }
  
}
