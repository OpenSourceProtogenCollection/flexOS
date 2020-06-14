/*     
    This file is part of The Open Source Protogen Collection (OSPC).
    OSPC is free software under the MIT license. Please see https://opensource.org/licenses/MIT for more info
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
#include <MemoryFree.h>


#define MATRIX_TILE_WIDTH   8 // width of matrix (not total display)
#define MATRIX_TILE_HEIGHT  -32 // height of matrix (negative due to flipped text, can use abs() to get positive)
#define MATRIX_TILE_TYPE VERTICAL_ZIGZAG_MATRIX
#define MATRIX_BOARD_CHIP WS2812B
#define MATRIX_TILE_H       1  // number of matrices arranged horizontally
#define MATRIX_TILE_V       1  // number of matrices arranged vertically
#define COLOR_ORDER GRB // hardware-dependent
#define LED_PIN 6 // pin where matrices are connected
#define NUM_LEDS MATRIX_TILE_WIDTH * abs(MATRIX_TILE_HEIGHT)

#define BRIGHTNESS 10 // brightness of LEDs
#endif
