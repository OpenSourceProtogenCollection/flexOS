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

/* This file serves to declare all of the variables needed for the various LED patterns */

#ifndef declarations_h
#define declarations_h

// colour codes
const long int black = 0x000000;
const long int red = 0xff0000;
const long int yellow = 0xffd900;
const long int purpleblue = 0x1b139e;
const long int seafoam = 0x009688;
const long int deepblue = 0x0000FF;
const long int purple = 0x7d0099;
const long int bluegray = 0x6e6e6e;
const long int green = 0x00FF00;

// array sizes used by drawPattern
#define ATTN_EYES 42
#define ATTN_MOUTH 145
#define CHG_EYES 44
#define CHG_EYES_R 21
#define CHG_MOUTH_O 50
#define CHG_MOUTH_B 8
#define COF_EYES_B 52
#define COF_EYES_W 12
#define COF_EYES_R 4
#define COF_MOUTH_C 135
#define COF_MOUTH_P 72
#define DNI_EYES 19
#define ERR_EYES_S 44 // start (red)
#define ERR_EYES_1 18 // add (red) and remove #1
#define ERR_EYES_2 10 // green, blue, remove #2
#define ERR_EYES_Y 7 // yellow
#define ERR_EYES_3 4 // purple, gray
#define CHK_EYES_1 5
#define CHK_EYES_M 6
#define CHK_EYES_L 10
#define PHN_EYES_S 58
#define PHN_EYES_1 10
#define PHN_EYES_2 8
#define ZZZ_EYES_S 39
#define ZZZ_EYES_M 10
#define LOW_MOUTH 42

// arrays used by drawPattern, can I shrink these to uint8?
// PGM comes into play here. For more info about PGM, see the declarations header or the wiki

// exclamation marks
const uint16_t attentionEyes[] PROGMEM = {64, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 79, 120, 121, 122, 123, 124, 125, 127, 128, 130, 131, 132, 133, 134, 135, 176, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 191};
// "! ATTN !" text
// very long, considering rewriting with LEDText
const uint16_t attentionMouth[] PROGMEM = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 42, 43, 53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 86, 87, 88, 89, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 118, 119, 120, 121, 136, 137, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 182, 183, 186, 187, 188, 189, 190, 191, 194, 195, 196, 197, 198, 199, 200, 201, 202, 205, 210, 211, 212, 213, 214, 215, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 240, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 255};
// lightning
const uint16_t chargeEyes[] PROGMEM = {27, 35, 36, 38, 39, 41, 42, 43, 44, 45, 49, 50, 52, 53, 59, 107, 115, 116, 118, 119, 121, 122, 123, 124, 125, 129, 130, 132, 133, 139, 187, 195, 196, 198, 199, 201, 202, 203, 204, 205, 209, 210, 212, 213, 219};
// moves lightning
const uint16_t chargeEyesAdd[] PROGMEM = {28, 34, 37, 46, 48, 51, 60, 108, 114, 117, 126, 128, 131, 140, 188, 194, 197, 206, 208, 211, 220};
// removes leftovers
const uint16_t chargeEyesRemove[] PROGMEM = {27, 36, 39, 41, 50, 53, 59, 107, 116, 119, 121, 130, 133, 139, 187, 196, 199, 201, 210, 213, 219};
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
// cups
const uint16_t coffeeEyesBlue[] PROGMEM = {59, 60, 61, 66, 68, 75, 76, 77, 80, 81, 82, 83, 84, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 107, 108, 109, 146, 147, 148, 155, 157, 162, 163, 164, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 187, 188, 189, 190, 191, 194, 195, 196};
// whisps of steam
const uint16_t coffeeEyesWhite[] PROGMEM = {73, 85, 87, 102, 104, 106, 166, 168, 170, 185, 197, 199};
// remove bits of steam
const uint16_t coffeeEyesRemove[] PROGMEM = {73, 102, 166, 185};
// readd them elsewhere
const uint16_t coffeeEyesAdd[] PROGMEM = {89, 118, 182, 201};
const uint16_t dniEyes[] PROGMEM = {107, 108, 109, 113, 117, 121, 125, 127, 128, 131, 134, 137, 139, 143, 145, 149, 155, 156, 157};
// base "error" text
const uint16_t errEyesSt[] PROGMEM = {73, 74, 78, 82, 83, 84, 86, 89, 91, 97, 98, 99, 100, 101, 102, 113, 117, 118, 121, 123, 124, 125, 132, 134, 137, 138, 139, 140, 141, 142, 153, 158, 161, 164, 166, 169, 171, 174, 177, 178, 179, 180, 181, 182};
// first removal (cleanup)
const uint16_t errEyesR1[] PROGMEM = {74, 78, 82, 97, 98, 100, 101, 113, 117, 125, 138, 139, 141, 142, 158, 178, 180, 181};
// shifts portions of text (add)
const uint16_t errEyesA[] PROGMEM = {69, 75, 81, 93, 106, 109, 110, 116, 122, 126, 130, 133, 145, 146, 155, 170, 189, 190};
const uint16_t errEyesAGn[] PROGMEM = {123, 132, 137, 139, 150, 153, 156, 163, 172, 179}; // green
const uint16_t errEyesAB[] PROGMEM = {97, 110, 113, 142, 145, 158, 161, 174, 177, 190}; // blue
const uint16_t errEyesAY[] PROGMEM = {117, 121, 122, 170, 180, 186, 187}; // yellow
const uint16_t errEyesAP[] PROGMEM = {90, 91, 99, 100}; // purple
const uint16_t errEyesAGr[] PROGMEM = {67, 74, 75, 76}; // gray
// second removal (effect)
const uint16_t errEyesR2[] PROGMEM = {84, 90, 91, 101, 102, 134, 140, 156, 163, 164};
// checkmark
const uint16_t checkEyes1[] PROGMEM = {142, 145, 156, 157, 163};
const uint16_t checkEyes2[] PROGMEM = {113, 126, 127, 128, 129, 143};
const uint16_t checkEyes3[] PROGMEM = {99, 108, 109, 114, 115, 125};
const uint16_t checkEyes4[] PROGMEM = {73, 85, 86, 89, 90, 91, 99, 100, 101, 107};
const uint16_t phoneEyesSt[] PROGMEM = {66, 67, 68, 76, 77, 78, 79, 82, 83, 84, 85, 86, 91, 92, 93, 94, 95, 100, 101, 102, 107, 108, 109, 116, 117, 118, 123, 124, 125, 132, 133, 134, 139, 140, 141, 148, 149, 150, 155, 156, 157, 162, 163, 164, 165, 166, 171, 172, 173, 174, 175, 178, 179, 180, 181, 189, 190, 191};
const uint16_t phoneEyes1[] PROGMEM = {52, 53, 59, 67, 74, 183, 186, 198, 204, 205};
const uint16_t phoneEyes2[] PROGMEM = {38, 39, 41, 56, 201, 216, 218, 219};
const uint16_t zzzEyes1[] PROGMEM = {41, 44, 51, 53, 54, 57, 59, 60, 67, 68, 70, 73, 76, 106, 109, 114, 116, 117, 122, 124, 125, 130, 131, 133, 138, 141, 171, 174, 177, 179, 180, 187, 189, 190, 193, 194, 196, 203, 206};
const uint16_t zzzEyesA1[] PROGMEM = {170, 173, 178, 181, 186, 188, 195, 197, 202, 205};
const uint16_t zzzEyesR1[] PROGMEM = {171, 174, 177, 179, 187, 190, 193, 196, 203, 206};
const uint16_t zzzEyesA2[] PROGMEM = {105, 108, 115, 118, 121, 123, 132, 134, 137, 140};
const uint16_t zzzEyesR2[] PROGMEM = {106, 109, 114, 116, 122, 125, 130, 133, 138, 141};
const uint16_t zzzEyesA3[] PROGMEM = {40, 43, 52, 55, 56, 58, 69, 71, 72, 75};
const uint16_t zzzEyesR3[] PROGMEM = {41, 44, 51, 53, 57, 60, 67, 70, 73, 76};
const uint16_t lowBatMouth[] PROGMEM = {24, 27, 34, 35, 36, 38, 39, 41, 42, 43, 44, 45, 46, 48, 49, 51, 52, 53, 59, 60, 63, 184, 187, 194, 195, 196, 198, 199, 201, 202, 203, 204, 205, 206, 208, 209, 211, 212, 213, 219, 220, 223};

// * end drawPattern arrays *

// char arrays used by LEDText
const unsigned char returnToRoomText[] = "      Returning to room - do not interact";
const unsigned char coffeeText[] = "      COFFEE PLS...";
const unsigned char attnText[] = "! ATTN !"; // currently unused  
const unsigned char handlerMouthText[] = { EFFECT_FRAME_RATE "\x00"
EFFECT_BACKGND_LEAVE EFFECT_RGB "\xFF\x00\x00"
EFFECT_SCROLL_LEFT "      LOST HANDLER"
};
const unsigned char handlerEyesText[] = { EFFECT_FRAME_RATE "\x00"
EFFECT_BACKGND_LEAVE EFFECT_RGB "\xFF\x00\x00"
EFFECT_SCROLL_LEFT "      HELP"
};


// arrays used by loading anim
const int topRow[] = {136, 135, 120, 119, 104, 103, 88};
const int rightRow[] = {89, 90, 91, 92, 93, 94, 95};
const int bottomRow[] = {96, 111, 112, 127, 128, 143};
const int leftRow[] = {142, 141, 140, 139, 138, 137, 136};
const uint32_t rainbow[] = {CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Blue, CRGB::Indigo, CRGB::Violet};

#endif
