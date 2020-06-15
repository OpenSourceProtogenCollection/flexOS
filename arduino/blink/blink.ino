/*
    This file is part of flexOS and The Open Source Protogen Collection (OSPC).
    flexOS is free software under the MIT license. Please see https://opensource.org/licenses/MIT for more info
*/

// this sketch will visualize your matrix's wirepath for you so you can accurately create images
// it will light every LED in sequence, starting at index 0
// The green LED indicates the first index (0), the red indicates the last (number of pixels - 1)
// disclaimer: this is basically a carbon-copy of the code provided by FastLED on their wiki, +attrib to them

#include <FastLED.h>
#define NUM_LEDS 256 // change this to the number of LEDs you have
#define DATA_PIN 6 // ensure this matches the data pin you're using
CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  for (int dot = 0; dot < NUM_LEDS; dot++) {
    leds[dot] = CRGB::Blue;
    FastLED.show();
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    delay(30);
  }

  FastLED.clear();
  leds[0] = CRGB::Green;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Black;
  leds[(NUM_LEDS - 1)] = CRGB::Red;
  FastLED.show();
  delay(1000);
  leds[(NUM_LEDS - 1)] = CRGB::Black;
}
