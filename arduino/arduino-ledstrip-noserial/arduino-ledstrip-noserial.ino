/*
    This file is part of The Open Source Protogen Collection (OSPC).

    OSPC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OSPC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OSPC.  If not, see <https://www.gnu.org/licenses/>.
*/

int patternToWrite; // for RasPi serial communication
#define UPDATES_PER_SECOND 100 // for colour switching
#define BRIGHTNESS 75 // brightness of LEDs
static uint8_t startIndex = 0; // creating an index for FillLEDsFromPaletteColors

#include <FastLED.h>
#define NUM_LEDS 120 // change this to the number of LEDs you have
#define DATA_PIN 6 // ensure this matches the data pin you're using
CRGB leds[NUM_LEDS];

// Purpose: Dynamic rainbow palette loop
// Accepts: Index of palette to be used
// Returns: nothing
// Credits to FastLED for most of this code: https://github.com/FastLED/FastLED/blob/master/examples/ColorPalette/ColorPalette.ino
void FillLEDsFromPaletteColors(uint8_t colorIndex)
{
  for (int i = 0; i < NUM_LEDS; i++) { // run through the entire array, pixel by pixel
    leds[i] = ColorFromPalette(RainbowColors_p, colorIndex, BRIGHTNESS, LINEARBLEND);
    colorIndex += 3;
  }
}

// Purpose: Writes all LEDs a single colour

void writeSolid(long int colour) {
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      leds[dot] = colour;
    }
    FastLED.show();
}

void writeRainbow() {
  while (true) {
    startIndex = startIndex + 1; //motion speed
    FillLEDsFromPaletteColors(startIndex);
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
    if (Serial.available() > 0)
      break;
  }
}

void setup() {
  // instantiate FastLED
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  // make sure the strip is clear before we go any further
  FastLED.clear();
  // place the strip pattern you want to loop here, before FastLED.show()
  writeRainbow();
  FastLED.show();
}

void loop() {
  // this stays empty
}
