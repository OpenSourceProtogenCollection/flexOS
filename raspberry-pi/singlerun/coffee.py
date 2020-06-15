#!/usr/bin/env python3
import serial
from gpiozero import Button
import os
import random

# USB declarations begin here
visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
# visorMouth.flush()

# serial write functions begin here
def writeCoffee():
    visorEyes.write(b"3") # priority 1
#    visorMouth.write(b"3")
    print("coffee")
    os.system("omxplayer -o local /home/pi/flexOS/raspberry-pi/sounds/coffee.wav > /dev/null")
	
writeCoffee