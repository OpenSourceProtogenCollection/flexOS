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

// booleans for switching message, since LEDText doesn't have a better way to do this
bool coffeeSet = false;
bool roomSet = false;

void setup() {
  // TODO: Serial bridge with RasPi

  // instantiate FastLED
  FastLED.addLeds<MATRIX_BOARD_CHIP, LED_PIN, COLOR_ORDER>(ledmatrix[0], ledmatrix.Size());
  FastLED.setBrightness(BRIGHTNESS);

  // instantiate LEDText
  ScrollingMsg.SetFont(MatriseFontData);
  ScrollingMsg.Init(&ledmatrix, ledmatrix.Width(), ScrollingMsg.FontHeight() + 1, 0, 0);
}

void loop() {
  /* TODO:
      finish rest of patterns
      decide if attn is being rewritten
      Serial bridge with RasPi
  */

//  // patterns begin here. while testing, all patterns will go in this sketch. later they'll go into separate sketches depending on which patterns go where
//
//  /* attention eyes */
//  FastLED.clear();
//  drawPattern(attentionEyes, ATTN_EYES, red);
//  FastLED.show();
//  delay(500);
//  FastLED.clear();
//  FastLED.show();
//  delay(500);
//
//  /* attention mouth - this takes up a lot of space, consider replacing it with LEDText. https://github.com/AaronLiddiment/LEDText/issues/7 */
//  FastLED.clear();
//  drawPattern(attentionMouth, ATTN_MOUTH, red);
//  FastLED.show();
//  delay(500);
//  FastLED.clear();
//  FastLED.show();
//  delay(500);
//
//  /* charge eyes */
//  FastLED.clear();
//  drawPattern(chargeEyes, CHG_EYES, yellow);
//  FastLED.show();
//  delay(500);
//  for (int i = 0; i < 2; i++) {
//    drawPattern(chargeEyesRemove, CHG_EYES_R, black);
//    drawPattern(chargeEyesAdd, CHG_EYES_R, yellow);
//    FastLED.show();
//    delay(500);
//    FastLED.clear();
//    drawPattern(chargeEyes, CHG_EYES, yellow);
//    FastLED.show();
//    delay(500);
//  }
//  singleLED(12, 100, yellow);
//  singleLED(62, 100, yellow);
//  singleLED(88, 100, yellow);
//  singleLED(161, 100, yellow);
//  singleLED(234, 100, yellow);
//  singleLED(167, 500, yellow);
//  FastLED.clear();
//
//  /* charge mouth */
//  FastLED.clear();
//  drawPattern(chargeMouthOutline, CHG_MOUTH_O, 0xFFFFFF);
//  FastLED.show();
//  delay(750);
//  drawPattern(chargeMouthBar1, CHG_MOUTH_B, 0x00FF00);
//  FastLED.show();
//  delay(200);
//  drawPattern(chargeMouthBar15, CHG_MOUTH_B, 0x00FF00);
//  FastLED.show();
//  delay(200);
//  drawPattern(chargeMouthBar2, CHG_MOUTH_B, 0x00FF00);
//  FastLED.show();
//  delay(200);
//  drawPattern(chargeMouthBar25, CHG_MOUTH_B, 0x00FF00);
//  FastLED.show();
//  delay(200);
//  drawPattern(chargeMouthBar3, CHG_MOUTH_B, 0x00FF00);
//  FastLED.show();
//  delay(200);
//  drawPattern(chargeMouthBar35, CHG_MOUTH_B, 0x00FF00);
//  FastLED.show();
//  delay(200);
//  drawPattern(chargeMouthBar4, CHG_MOUTH_B, 0x00FF00);
//  FastLED.show();
//  delay(200);
//  drawPattern(chargeMouthBar45, CHG_MOUTH_B, 0x00FF00);
//  FastLED.show();
//  delay(750);
//  FastLED.clear();
//
//
//  /* coffee eyes */
//  FastLED.clear();
//  drawPattern(coffeeEyesBlue, COF_EYES_B, purpleblue);
//  drawPattern(coffeeEyesWhite, COF_EYES_W, 0xFFFFFF);
//  FastLED.show();
//  delay(750);
//  drawPattern(coffeeEyesRemove, COF_EYES_R, black);
//  drawPattern(coffeeEyesAdd, COF_EYES_R, 0xFFFFFF);
//  FastLED.show();
//  delay(750);
//  FastLED.clear();
//
//
//  /* coffee mouth*/
//  FastLED.clear();
//  roomSet = false;
//  if (ScrollingMsg.UpdateText() == -1 || coffeeSet == false) {
//    ScrollingMsg.SetText(coffeeText, 19);
//    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0x00, 0x00, 0xff);
//    coffeeSet = true;
//  }
//  else
//    FastLED.show();
//  delay(40);
//
//
//  /* Do Not Interact eyes*/
//  FastLED.clear();
//  drawPattern(dniEyes, DNI_EYES, red);
//  FastLED.show();
//  delay(1000);
//  drawPattern(dniEyes, DNI_EYES, 0xffffff);
//  FastLED.show();
//  delay (1000);
//
//  /* Do Not Interact mouth */
//  FastLED.clear();
//  coffeeSet = false;
//  if (ScrollingMsg.UpdateText() == -1 || roomSet == false) {
//    ScrollingMsg.SetText(returnToRoomText, 41);
//    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0x1b, 0x13, 0x9e);
//    roomSet = true;
//  }
//  else
//    FastLED.show();
//  delay(40);
//
//  /* error eyes*/
//  FastLED.clear();
//  drawPattern(errEyesSt, ERR_EYES_S, red);
//  FastLED.show();
//  delay(1000);
//  drawPattern(errEyesR1, ERR_EYES_1, black);
//  drawPattern(errEyesA, ERR_EYES_1, red);
//  FastLED.show();
//  delay(250);
//  FastLED.clear();
//  drawPattern(errEyesSt, ERR_EYES_S, red);
//  FastLED.show();
//  delay(250);
//  drawPattern(errEyesR1, ERR_EYES_1, black);
//  drawPattern(errEyesA, ERR_EYES_1, red);
//  drawPattern(errEyesAGn, ERR_EYES_2, seafoam);
//  drawPattern(errEyesAB, ERR_EYES_2, deepblue);
//  FastLED.show();
//  delay(100);
//  FastLED.clear();
//  drawPattern(errEyesSt, ERR_EYES_S, red);
//  drawPattern(errEyesAGn, ERR_EYES_2, seafoam);
//  drawPattern(errEyesAB, ERR_EYES_2, deepblue);
//  drawPattern(errEyesAY, ERR_EYES_Y, yellow); // very clearly does not display yellow -_-
//  drawPattern(errEyesAGr, ERR_EYES_3, bluegray);
//  drawPattern(errEyesAP, ERR_EYES_3, purple);
//  FastLED.show();
//  delay(250);
//  drawPattern(errEyesR2, ERR_EYES_2, black);
//  FastLED.show();
//  delay(250);
//
//  /* checkmark eyes */
//  FastLED.clear();
//  drawPattern(checkEyes1, CHK_EYES_1, green);
//  FastLED.show();
//  delay(250);
//  drawPattern(checkEyes2, CHK_EYES_M, green);
//  FastLED.show();
//  delay(250);
//  drawPattern(checkEyes3, CHK_EYES_M, green);
//  FastLED.show();
//  delay(250);
//  drawPattern(checkEyes4, CHK_EYES_L, green);
//  FastLED.show();
//  delay(1000);
//
//  /* incorrect eyes */
//  FastLED.clear();
//  ledmatrix.DrawLine(13, 7, 20, 0, red);
//  ledmatrix.DrawLine(13, 0, 15, 2, red);
//  ledmatrix.DrawLine(20, 7, 18, 5, red);
//  FastLED.show();
//  delay(150);
//  FastLED.clear();
//  FastLED.show();
//  delay(150);
//  ledmatrix.DrawLine(13, 7, 20, 0, red);
//  ledmatrix.DrawLine(13, 0, 15, 2, red);
//  ledmatrix.DrawLine(20, 7, 18, 5, red);
//  FastLED.show();
//  delay(150);
//  FastLED.clear();
//  FastLED.show();
//  delay(150);
//  ledmatrix.DrawLine(13, 7, 20, 0, red);
//  ledmatrix.DrawLine(13, 0, 15, 2, red);
//  ledmatrix.DrawLine(20, 7, 18, 5, red);
//  FastLED.show();
//  delay(1000);
//
///* idle eyes */
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 6, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 6, 0xFFFFFF);
//FastLED.show();
//delay(3000);
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 5, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 5, 0xFFFFFF);
//FastLED.show();
//delay(100);
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 4, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 4, 0xFFFFFF);
//FastLED.show();
//delay(100);
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 5, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 5, 0xFFFFFF);
//FastLED.show();
//delay(100);
//
//
///* crying eyes */
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 5, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 5, 0xFFFFFF);
//FastLED.show();
//delay(1000);
//ledmatrix.DrawLine(3, 3, 4, 3, deepblue);
//ledmatrix.DrawLine(27, 3, 28, 3, deepblue);
//FastLED.show();
//delay(200);
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 5, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 5, 0xFFFFFF);
//ledmatrix.DrawLine(3, 2, 4, 2, deepblue);
//ledmatrix.DrawLine(27, 2, 28, 2, deepblue);
//FastLED.show();
//delay(200);
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 5, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 5, 0xFFFFFF);
//ledmatrix.DrawLine(3, 3, 4, 3, deepblue);
//ledmatrix.DrawLine(27, 3, 28, 3, deepblue);
//ledmatrix.DrawLine(3, 1, 4, 1, deepblue);
//ledmatrix.DrawLine(27, 1, 28, 1, deepblue);
//FastLED.show();
//delay(200);
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 5, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 5, 0xFFFFFF);
//ledmatrix.DrawLine(3, 2, 4, 2, deepblue);
//ledmatrix.DrawLine(27, 2, 28, 2, deepblue);
//ledmatrix.DrawLine(3, 0, 4, 0, deepblue);
//ledmatrix.DrawLine(27, 0, 28, 0, deepblue);
//FastLED.show();
//delay(200);
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 5, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 5, 0xFFFFFF);
//ledmatrix.DrawLine(3, 1, 4, 1, deepblue);
//ledmatrix.DrawLine(27, 1, 28, 1, deepblue);
//FastLED.show();
//delay(200);
//FastLED.clear();
//ledmatrix.DrawRectangle(3, 4, 4, 5, 0xFFFFFF);
//ledmatrix.DrawRectangle(27, 4, 28, 5, 0xFFFFFF);
//ledmatrix.DrawLine(3, 0, 4, 0, deepblue);
//ledmatrix.DrawLine(27, 0, 28, 0, deepblue);
//FastLED.show();
//delay(200);
//
///* id card eyes */
//FastLED.clear();
//ledmatrix.DrawRectangle(6, 0, 25, 7, deepblue);
//ledmatrix.DrawLine(19, 3, 15, 3, deepblue);
//ledmatrix.DrawLine(15, 5, 23, 5, deepblue);
//ledmatrix.DrawRectangle(9, 4, 10, 5, deepblue);
//ledmatrix.DrawRectangle(8, 1, 11, 2, deepblue);
//FastLED.show();
//delay(750);
//FastLED.clear();
//FastLED.show();
//delay(750);
//
///* eyes laughing */
//FastLED.clear();
//ledmatrix.DrawLine(3, 4, 5, 6, 0xFFFFFF);
//ledmatrix.DrawLine(7, 4, 6, 5, 0xFFFFFF);
//ledmatrix.DrawLine(24, 4, 26, 6, 0xFFFFFF);
//ledmatrix.DrawLine(28, 4, 27, 5, 0xFFFFFF);
//FastLED.show();
//delay(200);
//FastLED.clear();
//ledmatrix.DrawLine(3, 5, 5, 7, 0xFFFFFF);
//ledmatrix.DrawLine(7, 5, 6, 6, 0xFFFFFF);
//ledmatrix.DrawLine(24, 5, 26, 7, 0xFFFFFF);
//ledmatrix.DrawLine(28, 5, 27, 6, 0xFFFFFF);
//FastLED.show();
//delay(150);
//
///* eyes joy */
//FastLED.clear();
//ledmatrix.DrawLine(3, 4, 5, 6, 0xFFFFFF);
//ledmatrix.DrawLine(7, 4, 6, 5, 0xFFFFFF);
//ledmatrix.DrawLine(24, 4, 26, 6, 0xFFFFFF);
//ledmatrix.DrawLine(28, 4, 27, 5, 0xFFFFFF);
//FastLED.show();
//delay(1000);
//FastLED.clear();
//ledmatrix.DrawLine(3, 5, 5, 7, 0xFFFFFF);
//ledmatrix.DrawLine(7, 5, 6, 6, 0xFFFFFF);
//ledmatrix.DrawLine(24, 5, 26, 7, 0xFFFFFF);
//ledmatrix.DrawLine(28, 5, 27, 6, 0xFFFFFF);
//FastLED.show();
//delay(1000);
//
///* eyes phone old method - scrambled >.< */
//FastLED.clear();
//drawPattern(phoneEyesSt, PHN_EYES_S, deepblue);
//FastLED.show();
//delay(250);
//drawPattern(phoneEyes1, PHN_EYES_1, green);
//FastLED.show();
//delay(250);
//drawPattern(phoneEyes2, PHN_EYES_2, green);
//FastLED.show();
//delay(250);
//
///* eyes phone */
//FastLED.clear();
//ledmatrix.DrawFilledRectangle(8, 1, 11, 3, deepblue);
//ledmatrix.DrawFilledRectangle(20, 1, 23, 3, deepblue);
//ledmatrix.DrawFilledRectangle(21, 3, 10, 5, deepblue);
//leds[180] = deepblue;
//leds[75] = deepblue;
//FastLED.show();
//delay(250);
//leds[51] = green;
//leds[52] = green;
//leds[58] = green;
//leds[70] = green;
//leds[73] = green;
//leds[182] = green;
//leds[185] = green;
//leds[197] = green;
//leds[203] = green;
//leds[204] = green;
//FastLED.show();
//delay(250);
//ledmatrix.DrawLine(26, 5, 26, 6, green);
//ledmatrix.DrawLine(25, 7, 24, 7, green);
//ledmatrix.DrawLine(6, 7, 7, 7, green);
//ledmatrix.DrawLine(5, 6, 5, 5, green);
//FastLED.show();
//delay(250);

/* eyes sleepy*/
FastLED.clear();
ledmatrix.DrawLine(28, 5, 25, 5, 0xFFFFFF);
ledmatrix.DrawLine(6, 5, 3, 5, 0xFFFFFF);
FastLED.show();
delay(1000);
FastLED.clear();
drawPattern(zzzEyes1, ZZZ_EYES_S, 0xFFFFFF);
FastLED.show();
delay(300);
drawPattern(zzzEyesA1, ZZZ_EYES_M, 0xFFFFFF);
drawPattern(zzzEyesR1, ZZZ_EYES_M, black);
FastLED.show();
delay(300);
FastLED.clear();
drawPattern(zzzEyes1, ZZZ_EYES_S, 0xFFFFFF);
drawPattern(zzzEyesA2, ZZZ_EYES_M, 0xFFFFFF);
drawPattern(zzzEyesR2, ZZZ_EYES_M, black);
FastLED.show();
delay(300);
FastLED.clear();
drawPattern(zzzEyes1, ZZZ_EYES_S, 0xFFFFFF);
drawPattern(zzzEyesA3, ZZZ_EYES_M, 0xFFFFFF);
drawPattern(zzzEyesR3, ZZZ_EYES_M, black);
FastLED.show();
delay(300);
FastLED.clear();
drawPattern(zzzEyes1, ZZZ_EYES_S, 0xFFFFFF);
FastLED.show();
delay(1000);
  
}

// Purpose: Draws LEDs by running through the pixels, one by one, and seeing if they should be lit up according to their array
// Accepts: uint16_t[] of your desired pattern, int size of the pattern array, long int hex code
// Returns: nothing
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


void singleLED(int number, int delaytime, long int colour) {
  ledmatrix.DrawPixel(floor(number / 8), (number % 8), colour);
  FastLED.show();
  delay(delaytime);
}
