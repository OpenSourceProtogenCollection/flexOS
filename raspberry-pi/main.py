 #!/usr/bin/env python3
import serial
from gpiozero import Button

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
joyPin = Button(17, bounce_time=1) # some issue with 35
loadPin = Button(16, bounce_time=1)
hungryPin = Button(26, bounce_time=1)
errorPin = Button(20, bounce_time=1)
laughPin = Button(21, bounce_time=1)


# USB declarations begin here
visorEyes = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# visorMouth = serial.Serial('dev/ttyUSB1', 9600, timeout=1)
visorEyes.flush()
# visorMouth.flush()#nothing


# serial write functions begin here

def writeAttn(): # might not include the mouth, not sure
    visorEyes.write(b"1") # priority 4, left thumb
#    visorMouth.write(b"1")
    print("attn")

def writeChg():
    visorEyes.write(b"2") # priority 4, left index
#    visorMouth.write(b"2")
    print("chg")

def writeLow():
    visorEyes.write(b"g") # priority 5, left middle
#    visorMouth.write(b"g")
    print("low")

def writeLost():
    visorEyes.write(b"f") # priority 5, left ring
#    visorMouth.write(b"f")
    print("lost")

def writeDni():
    visorEyes.write(b"4") # priority 5, left small
#    visorMouth.write(b"4")
    print("dni")

def writeIdle():
    visorEyes.write(b"8") # priority 5, right thumb
#    visorMouth.write(b"8")
    print("idle")

def writeCheck():
    visorEyes.write(b"6") # priority 4, right index
#    visorMouth.write(b"6")
    print("check")

def writeWrong():
    visorEyes.write(b"7") # priority 4, right middle
#    visorMouth.write(b"7")
    print("wrong")

def writeId():
    visorEyes.write(b"0") # priority 4, right ring
#    visorMouth.write(b"0")
    print("id")

def writeJoy():
    visorEyes.write(b"a") # priority 4, right small
#    visorMouth.write(b"a")
    print("joy")

def writeLoad():
    visorEyes.write(b"e") # priority 3, left collar
#    visorMouth.write(b"e")

def writeHungry():
    visorEyes.write(b"k") # priority 3, left beltline
#    visorMouth.write(b"k")
    print("hungry")

def writeError():
    visorEyes.write(b"5") # priority 3, right beltline
#    visorMouth.write(b"5")
    print("error")

def writeLaugh():
    visorEyes.write(b"b") # priority 3, left hip
#    visorMouth.write(b"b")
    print("laugh")

def writeSleep():
    visorEyes.write(b"d") # priority 3, right hip
#    visorMouth.write(b"d")
    print("sleep")

def writeOwo():
    visorEyes.write(b"h") # priority 3, right collar
#    visorMouth.write(b"h")
    print("owo")

def writeHeart():
    visorEyes.write(b"j") # priority 2
#    visorMouth.write(b"j")
    print("heart")

def writeCoffee():
    visorEyes.write(b"3") # priority 1
#    visorMouth.write(b"3")
    print("coffee")

def writeUwu():
    visorEyes.write(b"i") # priority 1
#    visorMouth.write(b"i")
    print("uwu")

def writePhone():
    visorEyes.write(b"c") # priority 1
#    visorMouth.write(b"c")
    print("phone")

def writeCry():
    visorEyes.write(b"9")
#    visorMouth.write(b"9")
    print("cry")

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