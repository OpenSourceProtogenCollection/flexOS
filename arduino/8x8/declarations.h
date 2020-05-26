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

// for colour switching
#define UPDATES_PER_SECOND 100

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
