/*     
    This file is part of flexOS and The Open Source Protogen Collection (OSPC).
    flexOS is free software under the MIT license. Please see https://opensource.org/licenses/MIT for more info
*/


// for colour switching
#define UPDATES_PER_SECOND 100

static uint8_t startIndex = 0; // creating an index for FillLEDsFromPaletteColors

// here we define the size of the pattern arrays found below so they can be used in drawPattern
#define NOTE_SIZE 22
#define CLEF_SIZE 14

/*
  store your pattern arrays here
  to find your pattern arrays, check blink.ino and the wiki
  I didn't bother to PROGMEM these because I don't have that many to create and they're not that big
  for more info on PROGMEM and why it might be needed, check the 8x32 declarations.h
*/
int notePattern[] = {1, 2, 3, 12, 13, 14, 17, 18, 19, 28, 35, 37, 38, 41, 42, 44, 51, 52, 53, 58, 59, 60};
int bassClefPattern[] = {2, 12, 20, 24, 26, 37, 40, 42, 45, 46, 49, 50, 52, 60};
