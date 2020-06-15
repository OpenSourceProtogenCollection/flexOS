/*     
    This file is part of flexOS and The Open Source Protogen Collection (OSPC).
    flexOS is free software under the MIT license. Please see https://opensource.org/licenses/MIT for more info
*/


// for colour switching
#define UPDATES_PER_SECOND 100

static uint8_t startIndex = 0; // creating an index for FillLEDsFromPaletteColors

// here we define the size of the pattern arrays found below so they can be used in drawPattern
#define BASE_NOTE 31
#define SMALL_HEAD 4
#define SMALL_STEM 3

/*
  store your pattern arrays here
  to find your pattern arrays, check blink.ino and the wiki
  I didn't bother to PROGMEM these because I don't have that many to create and they're not that big
  for more info on PROGMEM and why it might be needed, check the 8x32 declarations.h
*/
const uint16_t noteBase[] PROGMEM = {83, 84, 85, 86, 105, 106, 107, 108, 115, 116, 117, 118, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 156, 157, 162, 163, 164, 165, 186, 187};
const uint16_t noteRight1[] PROGMEM = {204, 205, 210, 211};
const uint16_t noteRight2[] PROGMEM = {212, 213, 235};
const uint16_t noteLeft1[] PROGMEM = {26, 27, 36, 37};
const uint16_t noteLeft2[] PROGMEM = {34, 35, 60};
