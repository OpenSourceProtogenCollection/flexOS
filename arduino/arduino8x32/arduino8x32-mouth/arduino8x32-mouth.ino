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
#include "declarations.h" // this file includes variables for LED patterns

// creating the matrix using LEDMatrix
// note that height and width are flipped in this example due to TILE_TYPE
cLEDMatrix <MATRIX_TILE_HEIGHT, MATRIX_TILE_WIDTH, MATRIX_TILE_TYPE> ledmatrix;
// creating a pointer to the matrix so FastLED can still operate
CRGB *leds = ledmatrix[0];
// declaring LEDText
cLEDText ScrollingMsg;

// Purpose: Draws a single LED, then delays. Good for particle effects.
// Accepts: int index of LED, long int hex code, int time to delay after drawing (optional)
// Returns: Nothing
void singleLED(int number, long int colour, int delaytime = 0) {
  leds[number] = colour;
  if (delaytime > 0) {
    FastLED.show();
    FastLED.delay(delaytime);
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

void writeAttnMouth() {
  /* attention mouth - this takes up a lot of space, consider replacing it with LEDText. https://github.com/AaronLiddiment/LEDText/issues/7 */
  while (true) {
    FastLED.clear();
    drawPattern(attentionMouth, ATTN_MOUTH, CRGB::Red);
    FastLED.show();
    FastLED.delay(500);
    FastLED.clear();
    FastLED.show();
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
  }
}

void writeChgMouth() {
  while (true) {
    FastLED.clear();
    drawPattern(chargeMouthOutline, CHG_MOUTH_O, CRGB::White);
    FastLED.show();
    FastLED.delay(750);
    drawPattern(chargeMouthBar1, CHG_MOUTH_B, CRGB::Green);
    FastLED.show();
    FastLED.delay(200);
    drawPattern(chargeMouthBar15, CHG_MOUTH_B, CRGB::Green);
    FastLED.show();
    FastLED.delay(200);
    drawPattern(chargeMouthBar2, CHG_MOUTH_B, CRGB::Green);
    FastLED.show();
    FastLED.delay(200);
    drawPattern(chargeMouthBar25, CHG_MOUTH_B, CRGB::Green);
    FastLED.show();
    FastLED.delay(200);
    drawPattern(chargeMouthBar3, CHG_MOUTH_B, CRGB::Green);
    FastLED.show();
    FastLED.delay(200);
    drawPattern(chargeMouthBar35, CHG_MOUTH_B, CRGB::Green);
    FastLED.show();
    FastLED.delay(200);
    drawPattern(chargeMouthBar4, CHG_MOUTH_B, CRGB::Green);
    FastLED.show();
    FastLED.delay(200);
    drawPattern(chargeMouthBar45, CHG_MOUTH_B, CRGB::Green);
    FastLED.show();
    FastLED.delay(750);
    FastLED.clear();
    if (Serial.available() > 0)
      break;
  }
}

void writeLostHandlerMouth() {
  while (true) {
    ledmatrix.DrawFilledRectangle(0, 0, 31, 7, CRGB::White);

    if (ScrollingMsg.UpdateText() == -1)
      ScrollingMsg.SetText((unsigned char *)handlerMouthText, sizeof(handlerMouthText) - 1);
    else
      FastLED.show();
    FastLED.delay(15);
    if (Serial.available() > 0)
      break;
  }
}

void writeLowBatteryMouth() {
  while (true) {
    FastLED.clear();
    drawPattern(lowBatMouth, LOW_MOUTH, CRGB::Yellow);
    FastLED.show();
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    ledmatrix.DrawRectangle(13, 0, 15, 1, CRGB::Red);
    ledmatrix.DrawFilledRectangle(13, 3, 15, 7, CRGB::Red);
    ledmatrix.DrawRectangle(17, 0, 19, 1, CRGB::Red);
    ledmatrix.DrawFilledRectangle(17, 3, 19, 7, CRGB::Red);
    FastLED.show();
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
  }
}

void writeHappyMouth() {
  while (true) {
    FastLED.clear();
    ledmatrix.DrawLine(2, 6, 8, 1, CRGB::White);
    ledmatrix.DrawLine(8, 1, 10, 4, CRGB::White);
    ledmatrix.DrawLine(10, 4, 12, 1, CRGB::White);
    ledmatrix.DrawLine(12, 1, 15, 4, CRGB::White);
    ledmatrix.DrawLine(16, 4, 19, 1, CRGB::White);
    ledmatrix.DrawLine(19, 1, 21, 4, CRGB::White);
    ledmatrix.DrawLine(21, 4, 23, 1, CRGB::White);
    ledmatrix.DrawLine(29, 6, 23, 1, CRGB::White);
    FastLED.show();
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    ledmatrix.DrawRectangle(15, 3, 16, 2, CRGB::White);
    FastLED.show();
    delay(50);
    ledmatrix.DrawFilledRectangle(14, 2, 17, 0, CRGB::White);
    leds[145] = CRGB::White;
    leds[110] = CRGB::White;
    ledmatrix.DrawLine(14, 0, 17, 0, CRGB::White);
    FastLED.show();
    delay(50);
    ledmatrix.DrawLine(11, 0, 20, 0, CRGB::White);
    leds[161] = CRGB::White;
    leds[94] = CRGB::White;
    FastLED.show();
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    ledmatrix.DrawLine(11, 0, 13, 0, CRGB::Black);
    ledmatrix.DrawLine(18, 0, 20, 0, CRGB::Black);
    leds[161] = CRGB::Black;
    leds[94] = CRGB::Black;
    FastLED.show();
    delay(50);
    ledmatrix.DrawLine(13, 1, 18, 1, CRGB::Black);
    ledmatrix.DrawLine(13, 0, 18, 0, CRGB::Black);
    leds[141] = CRGB::Black;
    leds[114] = CRGB::Black;
    FastLED.show();
    delay(50);
    if (Serial.available() > 0)
      break;
  }
}

void writeSadMouth() {
  while (true) {
    FastLED.clear();
    ledmatrix.DrawLine(2, 1, 8, 4, CRGB::White);
    ledmatrix.DrawLine(8, 4, 10, 1, CRGB::White);
    ledmatrix.DrawLine(10, 1, 12, 4, CRGB::White);
    ledmatrix.DrawLine(12, 4, 15, 1, CRGB::White);
    ledmatrix.DrawLine(16, 1, 19, 4, CRGB::White);
    ledmatrix.DrawLine(19, 4, 21, 1, CRGB::White);
    ledmatrix.DrawLine(21, 1, 23, 4, CRGB::White);
    ledmatrix.DrawLine(29, 1, 23, 4, CRGB::White);
    FastLED.show(); FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    ledmatrix.ShiftDown();
    FastLED.show(); FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
  }
}


void writeSurpriseMouth() {
  while (true) {
    FastLED.clear();
    ledmatrix.DrawLine(5, 3, 5, 6, CRGB::Red);
    leds[209] = CRGB::Red;
    ledmatrix.DrawLine(26, 3, 26, 6, CRGB::Red);
    leds[46] = CRGB::Red;
    ledmatrix.DrawRectangle(13, 1, 17, 2, CRGB::White);
    ledmatrix.DrawLine(14, 3, 16, 3, CRGB::White);
    leds[132] = CRGB::White;
    FastLED.show();
    delay(200);
    ledmatrix.DrawLine(26, 0, 26, 7, CRGB::Black);
    ledmatrix.DrawLine(5, 0, 5, 7, CRGB::Black);
    FastLED.show();
    delay(200);
    ledmatrix.DrawLine(5, 3, 5, 6, CRGB::Red);
    leds[209] = CRGB::Red;
    ledmatrix.DrawLine(26, 3, 26, 6, CRGB::Red);
    leds[46] = CRGB::Red;
    FastLED.show();
    FastLED.delay(100);
    if (Serial.available() > 0)
      break;
    ledmatrix.DrawLine(26, 0, 26, 7, CRGB::Black);
    ledmatrix.DrawLine(5, 0, 5, 7, CRGB::Black);
    FastLED.show();
    delay(100);
    ledmatrix.DrawLine(5, 3, 5, 6, CRGB::Red);
    leds[209] = CRGB::Red;
    ledmatrix.DrawLine(26, 3, 26, 6, CRGB::Red);
    leds[46] = CRGB::Red;
    FastLED.show(); FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
  }
}

void writeOwoMouth() {
  FastLED.clear();
  ledmatrix.DrawLine(10, 4, 13, 1, CRGB::White);
  ledmatrix.DrawLine(13, 1, 15, 3, CRGB::White);
  ledmatrix.DrawLine(16, 3, 18, 1, CRGB::White);
  ledmatrix.DrawLine(18, 1, 21, 4, CRGB::White);
  FastLED.show();
}

void writeHungryMouth() {
  while (true) {
    FastLED.clear();
    if (ScrollingMsg.UpdateText() == -1) {
      ScrollingMsg.SetText(hungryText, 15);
      ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0x00, 0x00, 0xff);
    }
    else
      FastLED.show();
    delay(40);
    if (Serial.available() > 0)
      break;
  }
}

void writeDniMouth() {
  while (true) {
    FastLED.clear();
    if (ScrollingMsg.UpdateText() == -1) {
      ScrollingMsg.SetText(dniText, 21);
      ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xFF, 0x00, 0x00);
    } else {
      FastLED.show();
      delay(20);
    }
    if (Serial.available() > 0)
      break;
  }
}

void writeError() {
  while (true) {
    FastLED.clear();
    drawPattern(errSt, ERR_S, CRGB::Red);
    FastLED.show();
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    FastLED.delay(500);
    if (Serial.available() > 0)
      break;
    drawPattern(errR1, ERR_1, CRGB::Black);
    drawPattern(errA, ERR_1, CRGB::Red);
    FastLED.show();
    FastLED.delay(250);
    FastLED.clear();
    drawPattern(errSt, ERR_S, CRGB::Red);
    FastLED.show();
    FastLED.delay(250);
    if (Serial.available() > 0)
      break;
    drawPattern(errR1, ERR_1, CRGB::Black);
    drawPattern(errA, ERR_1, CRGB::Red);
    drawPattern(errAGn, ERR_2, seafoam);
    drawPattern(errAB, ERR_2, CRGB::Blue);
    FastLED.show();
    FastLED.delay(100);
    FastLED.clear();
    drawPattern(errSt, ERR_S, CRGB::Red);
    drawPattern(errAGn, ERR_2, seafoam);
    drawPattern(errAB, ERR_2, CRGB::Blue);
    drawPattern(errAY, ERR_Y, CRGB::Yellow);
    drawPattern(errAGr, ERR_3, bluegray);
    drawPattern(errAP, ERR_3, CRGB::Purple);
    FastLED.show();
    FastLED.delay(250);
    drawPattern(errR2, ERR_2, CRGB::Black);
    FastLED.show();
    FastLED.delay(250);
    if (Serial.available() > 0)
      break;
  }
}

void writeInternalError() {
  while (true) {
    FastLED.clear();
    if (ScrollingMsg.UpdateText() == -1) {
      ScrollingMsg.SetText(internalErrorText, 28);
      ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xFF, 0x00, 0x00);
    } else {
      FastLED.show();
      delay(20);
    }
    if (Serial.available() > 0)
      break;
  }
}

void writeBlank() {
  FastLED.clear();
  FastLED.show();
}

void setup() {
  // TODO: Serial bridge with RasPi

  Serial.begin(9600);

  // instantiate FastLED
  FastLED.addLeds<MATRIX_BOARD_CHIP, LED_PIN, COLOR_ORDER>(ledmatrix[0], ledmatrix.Size());
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(9600);

  // instantiate LEDText
  ScrollingMsg.SetFont(MatriseFontData);
  ScrollingMsg.Init(&ledmatrix, ledmatrix.Width(), ScrollingMsg.FontHeight() + 1, 0, 0);

  FastLED.clear();
  FastLED.show();
}

void loop() {
  /* TODO:
    decide if attn is being rewritten
    Serial bridge with RasPi
  */

  if (Serial.available() > 0) {
    patternToWrite = Serial.read();
    //Serial.print("Got: ");
    //Serial.println(patternToWrite);
    switch (patternToWrite) {
      case 48:
        writeBlank();
        break;
      case 49:
        writeAttnMouth();
        break;
      case 50:
        writeChgMouth();
        break;
      case 51:
        writeBlank();
        break;
      case 52:
        writeDniMouth();
        break;
      case 53:
        writeError();
        break;
      case 54:
        writeHappyMouth();
        break;
      case 55:
        writeSadMouth();
        break;
      case 56:
        writeHappyMouth();
        break;
      case 57:
        writeSadMouth();
        break;
      case 97:
        writeHappyMouth();
        break;
      case 98:
        writeHappyMouth();
        break;
      case 99:
        writeSurpriseMouth();
        break;
      case 100:
        writeHappyMouth();
        break;
      //        case 101:
      //        writeLoadingEyes();
      //        break;
      case 102:
        writeLostHandlerMouth();
        break;
      case 103:
        writeBlank();
        break;
      case 104:
        writeOwoMouth();
        break;
      case 105:
        writeOwoMouth();
        break;
      case 106:
        writeHappyMouth();
        break;
      case 107:
        writeHungryMouth();
        break;
      case 108:
        writeSurpriseMouth();
        break;
      case 10:
        break;
      default:
        writeInternalError();
        break;
    }
  }

}
