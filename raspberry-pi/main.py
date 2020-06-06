 #!/usr/bin/env python3
import serial
from gpiozero import Button
import os
import random

# input pin declarations begin here
# use syntax name = Button(bcmPinNumber, bounce_time=1)
# find BCM pin numbers at https://pinout.xyz
owoPin = Button(9, bounce_time=1)
sleepPin = Button(25, bounce_time=1)
attnPin = Button(11, bounce_time=1)
chgPin = Button(8, bounce_time=1)
lowPin = Button(7, bounce_time=1)
lostPin = Button(0, bounce_time=1)
dniPin = Button(1, bounce_time=1)
idlePin = Button(5, bounce_time=1)
checkPin = Button(6, bounce_time=1)
wrongPin = Button(12, bounce_time=1)
idPin = Button(13, bounce_time=1)
joyPin = Button(17, bounce_time=1)
loadPin = Button(16, bounce_time=1)
hungryPin = Button(26, bounce_time=1)
errorPin = Button(20, bounce_time=1)
laughPin = Button(21, bounce_time=1)


# USB declarations begin here
visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
# visorMouth.flush()


# serial write functions begin here

def writeAttn():
    visorEyes.write(b"1") # priority 4, left thumb
#    visorMouth.write(b"1")
    print("attn")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/rapidchirp.wav > /dev/null")

def writeChg():
    visorEyes.write(b"2") # priority 4, left index
#    visorMouth.write(b"2")
    print("chg")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/powerrestored.wav > /dev/null")

def writeLow():
    visorEyes.write(b"g") # priority 5, left middle
#    visorMouth.write(b"g")
    print("low")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/lowbattery.wav > /dev/null")

def writeLost():
    visorEyes.write(b"f") # priority 5, left ring
#    visorMouth.write(b"f")
    print("lost")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/criticalalarm.wav > /dev/null")

def writeDni():
    visorEyes.write(b"4") # priority 5, left small
#    visorMouth.write(b"4")
    print("dni")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/dni.wav > /dev/null")

def writeIdle():
    visorEyes.write(b"8") # priority 5, right thumb
#    visorMouth.write(b"8")
    print("idle")
    randomNumber = random.randint(0,4)
    if randomNumber == 0:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/analysis.wav > /dev/null")
    else if randomNumber == 1:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/registered.wav > /dev/null")
    else if randomNumber == 2:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/vocalizing.wav > /dev/null")
    else if randomNumber == 3:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/idlynoisy.wav > /dev/null")
    else if randomNumber == 4:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/calculating.wav > /dev/null")

def writeCheck():
    visorEyes.write(b"6") # priority 4, right index
#    visorMouth.write(b"6")
    print("check")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/correct.wav > /dev/null")

def writeWrong():
    visorEyes.write(b"7") # priority 4, right middle
#    visorMouth.write(b"7")
    print("wrong")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/incorrect.wav > /dev/null")

def writeId():
    visorEyes.write(b"0") # priority 4, right ring
#    visorMouth.write(b"0")
    print("id")
    randomNumber = random.randint(0,1)
    if randomNumber == 0:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/identify.wav > /dev/null")
    else if randomNumber == 1:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/displayid.wav > /dev/null")

def writeJoy():
    visorEyes.write(b"a") # priority 4, right small
#    visorMouth.write(b"a")
    print("joy")
    randomNumber = random.randint(0,4)
    if randomNumber == 0:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/analysis.wav > /dev/null")
    else if randomNumber == 1:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/registered.wav > /dev/null")
    else if randomNumber == 2:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/vocalizing.wav > /dev/null")
    else if randomNumber == 3:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/idlynoisy.wav > /dev/null")
    else if randomNumber == 4:
        os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/calculating.wav > /dev/null")

def writeLoad():
    visorEyes.write(b"e") # priority 3, left collar
#    visorMouth.write(b"e")

def writeHungry():
    visorEyes.write(b"k") # priority 3, left beltline
#    visorMouth.write(b"k")
    print("hungry")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/lifelost.wav > /dev/null")

def writeError():
    visorEyes.write(b"5") # priority 3, right beltline
#    visorMouth.write(b"5")
    print("error")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/criticalwarning.wav > /dev/null")

def writeLaugh():
    visorEyes.write(b"b") # priority 3, left hip
#    visorMouth.write(b"b")
    print("laugh")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/laughing.wav > /dev/null")

def writeSleep():
    visorEyes.write(b"d") # priority 3, right hip
#    visorMouth.write(b"d")
    print("sleep")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/snoring.wav > /dev/null")

def writeOwo():
    visorEyes.write(b"h") # priority 3, right collar
#    visorMouth.write(b"h")
    print("owo")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/owo.wav > /dev/null")

def writeHeart():
    visorEyes.write(b"j") # priority 2
#    visorMouth.write(b"j")
    print("heart")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/exclamation.wav > /dev/null")

def writeCoffee():
    visorEyes.write(b"3") # priority 1
#    visorMouth.write(b"3")
    print("coffee")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/coffee.wav > /dev/null")

def writeUwu():
    visorEyes.write(b"i") # priority 1
#    visorMouth.write(b"i")
    print("uwu")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/uwu.wav > /dev/null")

def writePhone():
    visorEyes.write(b"c") # priority 1
#    visorMouth.write(b"c")
    print("phone")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/phone.wav > /dev/null")

def writeCry():
    visorEyes.write(b"9")
#    visorMouth.write(b"9")
    print("cry")
    os.system("omxplayer -o local /home/pi/OpenSourceProtogenCollection/raspberry-pi/sounds/frazzled.wav > /dev/null")

owoPin.when_pressed = writeOwo
sleepPin.when_pressed = writeSleep
attnPin.when_pressed = writeAttn
chgPin.when_pressed = writeChg
lowPin.when_pressed = writeLow
lostPin.when_pressed = writeLost
dniPin.when_pressed = writeDni
idlePin.when_pressed = writeIdle
checkPin.when_pressed = writeCheck
wrongPin.when_pressed = writeWrong
idPin.when_pressed = writeId
joyPin.when_pressed = writeJoy
loadPin.when_pressed = writeLoad
hungryPin.when_pressed = writeHungry
errorPin.when_pressed = writeError
laughPin.when_pressed = writeLaugh

while True:
    pass