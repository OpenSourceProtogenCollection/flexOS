#!/usr/bin/env python3
import serial
from gpiozero import Button
import os
import random

# input pin declarations begin here
# use syntax name = Button(bcmPinNumber, bounce_time=1)
# find BCM pin numbers at https://pinout.xyz
chgPin = Button(8, bounce_time=1)

# USB declarations begin here
visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
# visorMouth.flush()

# serial write functions begin here
def writeChg():
    visorEyes.write(b"2") # priority 4, left index
#    visorMouth.write(b"2")
    print("chg")
    os.system("omxplayer -o local /home/pi/flexOS/raspberry-pi/sounds/powerrestored.wav > /dev/null")
	
writeChg