#!/usr/bin/env python3
import serial
from gpiozero import Button
import os
import random

# input pin declarations begin here
# use syntax name = Button(bcmPinNumber, bounce_time=1)
# find BCM pin numbers at https://pinout.xyz
dniPin = Button(1, bounce_time=1)

# USB declarations begin here
visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
# visorMouth.flush()

# serial write functions begin here
def writeDni():
    visorEyes.write(b"4") # priority 5, left small
#    visorMouth.write(b"4")
    print("dni")
    os.system("omxplayer -o local /home/pi/flexOS/raspberry-pi/sounds/dni.wav > /dev/null")
	
writeDni