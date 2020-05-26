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

/*                 _       _
     /\           | |     (_)
    /  \   _ __ __| |_   _ _ _ __ ______ _____      _____
   / /\ \ | '__/ _` | | | | | '_ \______/ _ \ \ /\ / / _ \
  / ____ \| | | (_| | |_| | | | | |    | (_) \ V  V / (_) |
 /_/    \_\_|  \__,_|\__,_|_|_| |_|     \___/ \_/\_/ \___/ */

#include "config.h" // this file includes our libraries and device-specific variables

// creating the matrix using LEDMatrix
// note that height and width are flipped in this example due to TILE_TYPE
cLEDMatrix <MATRIX_TILE_WIDTH, MATRIX_TILE_HEIGHT, MATRIX_TILE_TYPE> ledmatrix;
// creating a pointer to the matrix so FastLED can still operate
CRGB *leds = ledmatrix[0];

// Purpose: Draws a single LED, then delays. Good for particle effects.
// Accepts: int index of LED, long int hex code, int time to delay after drawing (optional)
// Returns: Nothing
void singleLED(int number, long int colour, int delaytime = 0) {
  leds[number] = colour;
  if (delaytime > 0) {
    FastLED.show();
    delay(delaytime);
  }
}

// Purpose: Draws LEDs by running through the pixels, one by one, and seeing if they should be lit up according to their array
// Accepts: uint16_t[] of your desired pattern, int size of the pattern array, long int hex code
// Returns: nothing
// For more details on how this works, see https://github.com/JaredTheWolf/OpenSourceProtogenCollection/wiki/Notes:-PROGMEM
void drawPattern(uint16_t patternArray[], int patternSize, long int colour) {
  // PGM comes into play here. For more info about PGM, see the declarations header or the wiki
  uint16_t nextPixel; // holds current RAM value from PGM
  int pixelCounter = 0; // increments when a pixel is placed
  for (int i = 0; i < NUM_LEDS; i++) { // loop through LED in the matrix
    for (int j = 0; j < patternSize; j++) { // check every element in the pattern array for the current LED
      nextPixel = pgm_read_word(&patternArray[pixelCounter]); // pull element into RAM
      if (i == nextPixel) { // if the pixel in the matrix matches the array element
        leds[i] = colour; // turn the pixel the specified colour
        pixelCounter++; // move to the next pixel
      }
    }
  }
}

void setup() {
  // instantiate FastLED
  FastLED.addLeds<MATRIX_BOARD_CHIP, LED_PIN, COLOR_ORDER>(ledmatrix[0], ledmatrix.Size());
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  FastLED.clear();
  ledmatrix.DrawFilledRectangle(5, 3, 7, 6, CRGB::Red);
  ledmatrix.DrawLine(8, 3, 8, 13, CRGB::Red);
  ledmatrix.DrawRectangle(9, 13, 10, 12, CRGB::Red);
  ledmatrix.DrawRectangle(10, 11, 11, 10, CRGB::Red);
  FastLED.show();
  delay(2000);
  ledmatrix.DrawRectangle(12, 2, 13, 3, CRGB::Red);
  FastLED.show();
  delay(250);
  leds[212] = CRGB::Red;
  leds[213] = CRGB::Red;
  leds[235] = CRGB::Red;
  FastLED.show();
  delay(250);
  ledmatrix.DrawRectangle(1, 10, 2, 11, CRGB::Red);
  FastLED.show();
  delay(250);
  leds[34] = CRGB::Red;
  leds[35] = CRGB::Red;
  leds[60] = CRGB::Red;
  FastLED.show();
  delay(1000);

  for(int i = 0; i < 2; i++){
  ledmatrix.DrawLine(1, 10, 2, 10, CRGB::Red);
  leds[61] = CRGB::Black;
  leds[28] = CRGB::Black;
  leds[33] = CRGB::Black;
  leds[60] = CRGB::Red;
  ledmatrix.DrawLine(12, 2, 13, 2, CRGB::Black);
  leds[203] = CRGB::Red;
  leds[214] = CRGB::Red;
  leds[234] = CRGB::Red;
  leds[235] = CRGB::Black;
  FastLED.show();
  delay(250);
  
  ledmatrix.DrawLine(1, 10, 2, 10, CRGB::Black);
  leds[61] = CRGB::Red;
  leds[28] = CRGB::Red;
  leds[33] = CRGB::Red;
  leds[60] = CRGB::Black;
  ledmatrix.DrawLine(12, 2, 13, 2, CRGB::Red);
  leds[203] = CRGB::Black;
  leds[234] = CRGB::Black;
  leds[214] = CRGB::Black;
  leds[235] = CRGB::Red;
  FastLED.show();
  delay(250);
  }

  ledmatrix.DrawLine(1, 10, 2, 10, CRGB::Red);
  leds[61] = CRGB::Black;
  leds[28] = CRGB::Black;
  leds[33] = CRGB::Black;
  leds[60] = CRGB::Red;
  FastLED.show();
  delay(1000);

  ledmatrix.DrawRectangle(12, 2, 13, 3, CRGB::Black);
  FastLED.show();
  delay(250);
    leds[212] = CRGB::Black;
  leds[213] = CRGB::Black;
  leds[235] = CRGB::Black;
  FastLED.show();
  delay(250);
  ledmatrix.DrawRectangle(1, 10, 2, 11, CRGB::Black);
  FastLED.show();
  delay(250);
  leds[34] = CRGB::Black;
  leds[35] = CRGB::Black;
  leds[60] = CRGB::Black;
  FastLED.show();
  delay(1000);
}