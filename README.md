# Open Source Protogen Collection
 The full files created for Subwuffer the Protogen, to help anyone create their own protogen fursuit (GPLv3)
 
 Please check the wiki to get started.
 
# Current Status
Arduino: Matrices all fully coded. Serial has been implemented fully. Still having issues with the writeLoading pattern. Refactoring some messy (LEDMatrix) code. More patterns may be added in the future, but other parts of the project are more pertinent at this time.

RasPi: Main coding done, just waiting on additional microcontrollers to test multiple ttyUSBs.

Suit:

- Materials: Waiting to order fur, ordering thermoforming plastic, brainstorming helmet decisions
	
- Assembly: Not started
	
Wiki: Working on updating RasPi documentation

# Requirements
## Hardware
- WS2812B boards
	- I recommend 8x8 grids for cheeks and shoulders, 16x16 grids for legs, and 8x32 grids (x2) for visors
	- These can be found cheaply on AliExpress, but you can buy the more power-efficient versions from Adafruit
- Power sources
	- You'll need to do your own calculations as to how much power you'll need. I ended up going with 4 NiMH AA batteries, which gives 4.8V for every 4-battery holder
- Arduino (or other avr microcontrollers)
	- I went with Nanos, but these may be a bit limited in memory, so I'd recommend ESP32s. This one is up to you. Again, cheap ones can be found on AliExpress	
- Raspberry Pi
	- This one is only if you want to switch emotes in real-time. You will need wireless and the extra GPIO, so get either a 3B+ or newer, or a 1B+ or a 2B+ with a wireless adapter. I went with a 2B+ with a wireless adapter. Don't get a Pi A or Pi B, there aren't enough GPIO pins.
- Hall-effect sensors or reed switches (only for emote switching)
- 220 Ohm resistors, wires etc

## Software
- Codepad of your choice (VSCode and N++ are my choice for these languages)
- Arduino IDE
	- You must also have the following libraries installed:
		- [https://github.com/FastLED/FastLED](FastLED) for drawing arrays of LEDs (can and should be installed from Library Manager)
		- [https://github.com/AaronLiddiment/LEDText](LEDText) for scrolling text
		- [https://github.com/AaronLiddiment/LEDMatrix](LEDMatrix) for drawing shapes. I actually recommend using [jorgen-vikinggod's fork](https://jorgen-vikinggod.github.io/LEDMatrix/) for added functionality.
	- If you're coding and flashing on the go, ArduinoDroid works quite well
- [https://pixilart.com/draw](PixilArt) (web app)
- An image overlay program. For Windows there's OVERLAY2, but it's pretty persistent nagware. There's a better program out there by the name of Image Overlay Utility, but I'm not going to link it here due to (potentially false) positive malware alerts on it. If you go Googling for this, I reiterate that I'm not liable for any damage done. With that said, it seems to work fine on my machine, I have not seen any suspicious activity. If you would like me to screenshot you overlays of your pixel art, shoot me a [Telegram message](https://t.me/JaredTamana).
- A Linux-flashed SD card for your Raspberry Pi. I recommend Raspian. For more details on software for your installation, check the wiki.

# Notes
- I do not support macOS or Linux at this time. The reason I don't support macOS is because I don't own a macOS machine. However, the reason I don't support Linux is because the IDE SUCKS on Linux. There's no Library Manager, the Import Libraries tool is broken, your headers and libraries can't just be in the same folder as your sketch, the auto-format tool behaves strangely, shift-backspace is a nightmare... I could go on, but in short, just don't code Arduino on Linux. It hurts me to not support this because I love Linux and it sucks to have to switch between my Windows machine and my RPi constantly, but until Arduino fixes their IDE, I can't use it.
- This is a WORK IN PROGRESS. I'm very much learning and working with this.
- These are Subwuffer's files in their entirety. You are welcome to use them as-is, but I highly encourage diving into the code and customizing things. I've made it very easy through code comments and the wiki to find your way around ^^
- I do not own the protogen species. For more info on the species and what can and cannot be used in your protogen, please visit [the creator's website](https://www.primaproto.com/). At the time of writing, this site is down for maintenance, but a [backup](https://web.archive.org/web/20191025141630/https://www.primaproto.com/) can be found on the Wayback Machine.
- Big thanks to [Jting-F](https://www.youtube.com/channel/UCz8RfRGTDPPoexpyAg22kbg) for the inspiration and guidance along the way <3

# Getting in touch
I love to see what others make! If you have any questions or just want to chat about this project, you can find me on [Telegram](https://t.me/JaredTamana), [Discord](https://discordapp.com/users/375613991294205964), [Twitter](https://twitter.com/JaredTamana), or via email at [jaredtamana@gmail.com](mailto:jaredtamana@gmail.com). Please do try to contact me on Telegram first, that's where I'm most active.

# License
This code is licensed under GPLv3. TL;DR you must redistribute the source code of any derivative works under this same license. For more info, see the LICENSE file.
