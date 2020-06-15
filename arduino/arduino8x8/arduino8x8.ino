/*
    This file is part of flexOS and The Open Source Protogen Collection (OSPC).
    flexOS is free software under the MIT license. Please see https://opensource.org/licenses/MIT for more info
*/

/*                 _       _
     /\           | |     (_)
    /  \   _ __ __| |_   _ _ _ __ ______ _____      _____
   / /\ \ | '__/ _` | | | | | '_ \______/ _ \ \ /\ / / _ \
  / ____ \| | | (_| | |_| | | | | |    | (_) \ V  V / (_) |
 /_/    \_\_|  \__,_|\__,_|_|_| |_|     \___/ \_/\_/ \___/ */

#include "config.h"
#include "declarations.h"

// setting up the CRGB array for FastLED, this is how we write to individual pixels
CRGB leds[NUM_LEDS];


void setup() {
  // setting up the WS2812B on pin 6
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);
  // set brightness so it isn't blinding
  // this will need to be adjusted depending on how tinted your covers are
  FastLED.setBrightness(BRIGHTNESS);
  // display the created graphic
  FastLED.show();
}

void loop() {
  // Nothing
}

// Purpose: Dynamic rainbow palette fills pattern array... because who needs drawPattern when you're a  G A M E R
// Accepts: Index of palette to be used, int[] of your desired pattern, int size of the pattern array
// Returns: nothing
// Credits to FastLED for most of this code: https://github.com/FastLED/FastLED/blob/master/examples/ColorPalette/ColorPalette.ino
void FillLEDsFromPaletteColors(uint8_t colorIndex, int patternArray[], int arraySize)
{
  uint8_t brightness = 255;
  for (int i = 0; i < NUM_LEDS; i++) { // run through the entire array, pixel by pixel
    for (int j = 0; j < arraySize; j++) { // run through the array
      if (i == patternArray[j]) { // if the index of this pixel is found in the array
        leds[i] = ColorFromPalette(RainbowColors_p, colorIndex, brightness, LINEARBLEND);
        colorIndex += 3;
      }
    }
  }
}

// Purpose: Draws LEDs by running through the pixels, one by one, and seeing if they should be lit up according to their array
// Accepts: int[] of your desired pattern, int size of the pattern array, long int hex code
// Returns: nothing
void drawPattern(int patternArray[], int patternSize, long int colour) {
  for (int i = 0; i < NUM_LEDS; i++) { // run through the entire array, pixel by pixel
    for (int j = 0; j < patternSize; j++) { // run through the array
      if (i == patternArray[j]) { // if the index of this pixel is found in the array
        leds[i] = colour; // turn on this LED with the colour specified
      }
    }
  }
}

void drawNoteRegular() {
  drawPattern(notePattern, NOTE_SIZE, CRGB::Red);
}

void drawNoteRave() {
  startIndex = startIndex + 1; //motion speed
  FillLEDsFromPaletteColors(startIndex, notePattern, NOTE_SIZE);
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}
