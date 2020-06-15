#!/usr/bin/env python3
import serial
from gpiozero import Button
import os
import random

# input pin declarations begin here
# use syntax name = Button(bcmPinNumber, bounce_time=1)
# find BCM pin numbers at https://pinout.xyz
joyPin = Button(17, bounce_time=1)

# USB declarations begin here
visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
# visorMouth.flush()

# serial write functions begin here
def writeJoy():
    visorEyes.write(b"a") # priority 4, right small
#    visorMouth.write(b"a")
    print("joy")
    randomNumber = random.randint(0,4)
    if randomNumber == 0:
        os.system("omxplayer -o local /home/pi/flexOS/raspberry-pi/sounds/analysis.wav > /dev/null")
    else if randomNumber == 1:
        os.system("omxplayer -o local /home/pi/flexOS/raspberry-pi/sounds/registered.wav > /dev/null")
    else if randomNumber == 2:
        os.system("omxplayer -o local /home/pi/flexOS/raspberry-pi/sounds/vocalizing.wav > /dev/null")
    else if randomNumber == 3:
        os.system("omxplayer -o local /home/pi/flexOS/raspberry-pi/sounds/idlynoisy.wav > /dev/null")
    else if randomNumber == 4:
        os.system("omxplayer -o local /home/pi/flexOS/raspberry-pi/sounds/calculating.wav > /dev/null")
	
writeJoy