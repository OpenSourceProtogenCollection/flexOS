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
  while (true) {
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      leds[dot] = colour;
    }
    FastLED.show();
    FastLED.delay(500);
    while (Serial.available() == 0){
      // do nothing
    }
    break;
  }
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
  // start Serial connection for emote switching
  Serial.begin(9600);

  // instantiate FastLED
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  // make sure the strip is clear before we go any further
  FastLED.clear();
  FastLED.show();
}

void loop() {
  if (Serial.available() > 0) { // if there's a character in the Serial buffer
    patternToWrite = Serial.read(); // get the character and store it
    Serial.print("Got: ");
    Serial.println(patternToWrite); // just debug strings
    switch (patternToWrite) {
      case 48:
        writeSolid(CRGB::Yellow);
        break;
      case 49:
        writeSolid(CRGB::Red);
        break;
      case 50:
        writeSolid(CRGB::Yellow);
        break;
      case 51:
        writeSolid(CRGB::Blue);
        break;
      case 52 ... 53:
        writeSolid(CRGB::Red);
        break;
      case 54:
        writeSolid(CRGB::Green);
        break;
      case 55:
        writeSolid(CRGB::Red);
        break;
      case 56:
        writeSolid(CRGB::Green);
        break;
      case 57:
        writeSolid(CRGB::Blue);
        break;
      case 97 ... 99:
        writeSolid(CRGB::Green);
        break;
      case 100:
        writeSolid(CRGB::Blue);
        break;
      //        case 101:
      //        writeLoadingEyes();
      //        break;
      // broken due to RAM issues, WIP
      case 102 ... 103:
        writeSolid(CRGB::Red);
        break;
      case 104 ... 106:
        writeSolid(CRGB::Green);
        break;
      case 107:
        writeSolid(CRGB::Blue);
        break;
      case 108:
        writeSolid(CRGB::Green);
        break;
      case 122:
        writeRainbow();
      case 10:
        break;
      default:
        writeSolid(CRGB::Purple);
        break;
    }
  }
}
