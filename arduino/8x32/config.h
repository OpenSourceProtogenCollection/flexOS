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

// this file contains device-specific configurations and library imports

#ifndef config_h
#define config_h
#include <FastLED.h>
#include <LEDMatrix.h>
#include <Font12x16.h>
#include <Font16x24.h>
#include <FontMatrise.h>
#include <LEDText.h>

#define MATRIX_TILE_WIDTH   8 // width of matrix (not total display)
#define MATRIX_TILE_HEIGHT  -32 // height of matrix (negative due to flipped text, can use abs() to get positive)
#define MATRIX_TILE_TYPE VERTICAL_ZIGZAG_MATRIX
#define MATRIX_BOARD_CHIP WS2812B
#define MATRIX_TILE_H       1  // number of matrices arranged horizontally
#define MATRIX_TILE_V       1  // number of matrices arranged vertically
#define COLOR_ORDER GRB // hardware-dependent
#define LED_PIN 6 // pin where matrices are connected
#define NUM_LEDS MATRIX_TILE_WIDTH * abs(MATRIX_TILE_HEIGHT)

#define BRIGHTNESS 32 // brightness of LEDs
#endif
