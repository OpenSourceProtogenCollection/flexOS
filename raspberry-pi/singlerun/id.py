#!/usr/bin/env python3
import serial
from gpiozero import Button
import os
import random

# input pin declarations begin here
# use syntax name = Button(bcmPinNumber, bounce_time=1)
# find BCM pin numbers at https://pinout.xyz
idPin = Button(13, bounce_time=1)

# USB declarations begin here
visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
# visorMouth.flush()

# serial write functions begin here
def writeId():
    visorEyes.write(b"0") # priority 4, right ring
#    visorMouth.write(b"0")
    print("id")
    randomNumber = random.randint(0,1)
    if randomNumber == 0:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/identify.wav > /dev/null")
    else if randomNumber == 1:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/displayid.wav > /dev/null")
	
writeId