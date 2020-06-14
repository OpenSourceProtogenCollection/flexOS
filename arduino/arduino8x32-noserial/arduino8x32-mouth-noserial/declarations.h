/*     
    This file is part of The Open Source Protogen Collection (OSPC).
    OSPC is free software under the MIT license. Please see https://opensource.org/licenses/MIT for more info
*/

/* This file serves to declare all of the variables needed for the various LED patterns */

#ifndef declarations_h
#define declarations_h

// colour codes
const long int purpleblue = 0x1b139e;
const long int seafoam = 0x009688;
const long int bluegray = 0x6e6e6e;

// array sizes used by drawPattern
#define ATTN_MOUTH 145
#define CHG_MOUTH_O 50
#define CHG_MOUTH_B 8
#define COF_MOUTH_C 135
#define COF_MOUTH_P 72
#define LOW_MOUTH 42
#define ERR_S 44 // start (red)
#define ERR_1 18 // add (red) and remove #1
#define ERR_2 10 // green, blue, remove #2
#define ERR_Y 7 // yellow
#define ERR_3 4 // purple, gray
#define OWO_MOUTH 12
#define SUR_MOUTH_1 12
#define SUR_MOUTH_2 10

// arrays used by drawPattern, can I shrink these to uint8?
// PGM comes into play here. For more info about PGM, see the declarations header or the wiki

// very long, considering rewriting with LEDText
const uint16_t attentionMouth[] PROGMEM = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 42, 43, 53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 86, 87, 88, 89, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 118, 119, 120, 121, 136, 137, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 182, 183, 186, 187, 188, 189, 190, 191, 194, 195, 196, 197, 198, 199, 200, 201, 202, 205, 210, 211, 212, 213, 214, 215, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 240, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 255};
//battery bar
// I initially coded this using 4 sections but later decided I wanted more, hence 1.5, 2.5, etc
const uint16_t chargeMouthOutline[] PROGMEM = {51, 52, 58, 59, 60, 61, 65, 66, 67, 68, 69, 70, 73, 78, 81, 86, 89, 94, 97, 102, 105, 110, 113, 118, 121, 126, 129, 134, 137, 142, 145, 150, 153, 158, 161, 166, 169, 174, 177, 182, 185, 190, 193, 198, 201, 202, 203, 204, 205, 206};
const uint16_t chargeMouthBar1[] PROGMEM = {186, 187, 188, 189, 194, 195, 196, 197}; 
const uint16_t chargeMouthBar15[] PROGMEM = {170, 171, 172, 173, 178, 179, 180, 181};
const uint16_t chargeMouthBar2[] PROGMEM = {154, 155, 156, 157, 162, 163, 164, 165};
const uint16_t chargeMouthBar25[] PROGMEM = {138, 139, 140, 141, 146, 147, 148, 149};
const uint16_t chargeMouthBar3[] PROGMEM = {122, 123, 124, 125, 130, 131, 132, 133};
const uint16_t chargeMouthBar35[] PROGMEM = {106, 107, 108, 109, 114, 115, 116, 117};
const uint16_t chargeMouthBar4[] PROGMEM = {90, 91, 92, 93, 98, 99, 100, 101};
const uint16_t chargeMouthBar45[] PROGMEM = {74, 75, 76, 77, 82, 83, 84, 85};
const uint16_t lowBatMouth[] PROGMEM = {24, 27, 34, 35, 36, 38, 39, 41, 42, 43, 44, 45, 46, 48, 49, 51, 52, 53, 59, 60, 63, 184, 187, 194, 195, 196, 198, 199, 201, 202, 203, 204, 205, 206, 208, 209, 211, 212, 213, 219, 220, 223};
const uint16_t errSt[] PROGMEM = {73, 74, 78, 82, 83, 84, 86, 89, 91, 97, 98, 99, 100, 101, 102, 113, 117, 118, 121, 123, 124, 125, 132, 134, 137, 138, 139, 140, 141, 142, 153, 158, 161, 164, 166, 169, 171, 174, 177, 178, 179, 180, 181, 182};
// first removal (cleanup)
const uint16_t errR1[] PROGMEM = {74, 78, 82, 97, 98, 100, 101, 113, 117, 125, 138, 139, 141, 142, 158, 178, 180, 181};
// shifts portions of text (add)
const uint16_t errA[] PROGMEM = {69, 75, 81, 93, 106, 109, 110, 116, 122, 126, 130, 133, 145, 146, 155, 170, 189, 190};
const uint16_t errAGn[] PROGMEM = {123, 132, 137, 139, 150, 153, 156, 163, 172, 179}; // green
const uint16_t errAB[] PROGMEM = {97, 110, 113, 142, 145, 158, 161, 174, 177, 190}; // blue
const uint16_t errAY[] PROGMEM = {117, 121, 122, 170, 180, 186, 187}; // yellow
const uint16_t errAP[] PROGMEM = {90, 91, 99, 100}; // purple
const uint16_t errAGr[] PROGMEM = {67, 74, 75, 76}; // gray
// second removal (effect)
const uint16_t errR2[] PROGMEM = {84, 90, 91, 101, 102, 134, 140, 156, 163, 164};
const uint16_t owoMouth[] PROGMEM = {84, 92, 98, 110, 114, 124, 131, 141, 145, 157, 163, 171};
const uint16_t surpriseMouth1[] PROGMEM = {113, 114, 124, 125, 126, 129, 130, 131, 132, 140, 141, 142, 145, 146};
const uint16_t surpriseMouth2[] PROGMEM = {49, 51, 52, 53, 54, 209, 211, 212, 213, 214};

// * end drawPattern arrays *

// char arrays used by LEDText
const unsigned char dniText[] = "      DO NOT INTERACT";
//const unsigned char coffeeText[] = "      COFFEE PLS...";
const unsigned char handlerMouthText[] = {EFFECT_BACKGND_LEAVE "      LOST HANDLER"};
const unsigned char hungryText[] = "      Hungry...";
const unsigned char internalErrorText[] = "Pattern err";

// for RasPi serial communication
int patternToWrite;

#endif
