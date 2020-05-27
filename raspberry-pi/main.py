#!/usr/bin/env python3
import serial
import time
import RPi.GPIO as GPIO

# input pin declarations begin here
owoPin = 21
sleepPin = 22
attnPin = 23
chgPin = 24
lowPin = 26
lostPin = 27
dniPin = 28
idlePin = 29
checkPin = 31
wrongPin = 32
idPin = 33
joyPin = 35
loadPin = 36
hungryPin = 37
errorPin = 38
laughPin = 40

# GPIO setup
GPIO.setmode(GPIO.BCM)
GPIO.setup(attnPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(chgPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.add_event_detect(attnPin, GPIO.BOTH, callback=writeAttn,bouncetime=800)
GPIO.add_event_detect(chgPin, GPIO.BOTH, callback=writeChg, bouncetime=800)
GPIO.add_event_detect(lowPin, GPIO.BOTH, callback=writeLow, bouncetime=800)
GPIO.add_event_detect(lostPin, GPIO.BOTH, callback=writeLost, bouncetime=800)
GPIO.add_event_detect(dniPin, GPIO.BOTH, callback=writeDni, bouncetime=800)
GPIO.add_event_detect(idlePin, GPIO.BOTH, callback=writeIdle, bouncetime=800)
GPIO.add_event_detect(checkPin, GPIO.BOTH, callback=writeCheck, bouncetime=800)
GPIO.add_event_detect(wrongPin, GPIO.BOTH, callback=writeWrong, bouncetime=800)
GPIO.add_event_detect(idPin, GPIO.BOTH, callback=writeId, bouncetime=800)
GPIO.add_event_detect(joyPin, GPIO.BOTH, callback=writeJoy, bouncetime=800)
GPIO.add_event_detect(loadPin, GPIO.BOTH, callback=writeLoad, bouncetime=800)
GPIO.add_event_detect(hungryPin, GPIO.BOTH, callback=writeHungry, bouncetime=800)
GPIO.add_event_detect(errorPin, GPIO.BOTH, callback=writeError, bouncetime=800)
GPIO.add_event_detect(laughPin, GPIO.BOTH, callback=writeLaugh, bouncetime=800)
GPIO.add_event_detect(owoPin, GPIO.BOTH, callback=writeOwo, bouncetime=800)
GPIO.add_event_detect(sleepPin, GPIO.BOTH, callback=writeSleep, bouncetime=800)

visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
visorMouth.flush()

# serial write functions begin here

def writeAttn(): # might not include the mouth, not sure
    visorEyes.write(b"1") # priority 4, left thumb

def writeChg():
    visorEyes.write(b"2") # priority 4, left index

def writeLow():
    visorEyes.write(b"g") # priority 5, left middle

def writeLost():
    visorEyes.write(b"f") # priority 5, left ring

def writeDni():
    visorEyes.write(b"4") # priority 5, left small

def writeIdle():
    visorEyes.write(b"8") # priority 5, right thumb
    
def writeCheck():
    visorEyes.write(b"6") # priority 4, right index

def writeWrong():
    visorEyes.write(b"7") # priority 4, right middle

def writeId():
    visorEyes.write(b"0") # priority 4, right ring

def writeJoy():
    visorEyes.write(b"a") # priority 4, right small

def writeLoad():
    visorEyes.write(b"e") # priority 3, left collar
    
def writeHungry():
    visorEyes.write(b"k") # priority 3, left beltline

def writeError():
    visorEyes.write(b"5") # priority 3, right beltline

def writeLaugh():
    visorEyes.write(b"b") # priority 3, left hip

def writeSleep():
    visorEyes.write(b"d") # priority 3, right hip

def writeOwo():
    visorEyes.write(b"h") # priority 3, right collar
    
def writeHeart():
    visorEyes.write(b"j") # priority 2

def writeCoffee():
    visorEyes.write(b"3") # priority 1

def writeUwu():
    visorEyes.write(b"i") # priority 1

def writePhone():
    visorEyes.write(b"c") # priority 1

def writeCry():
    visorEyes.write(b"9")