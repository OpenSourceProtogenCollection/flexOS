#!/usr/bin/env python3
import serial
from gpiozero import Button
import os
import random

# input pin declarations begin here
# use syntax name = Button(bcmPinNumber, bounce_time=1)
# find BCM pin numbers at https://pinout.xyz
lostPin = Button(0, bounce_time=1)

# USB declarations begin here
visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
# visorMouth.flush()

# serial write functions begin heredef writeLost():
    visorEyes.write(b"f") # priority 5, left ring
#    visorMouth.write(b"f")
    print("lost")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/criticalalarm.wav > /dev/null")
	
writeLost