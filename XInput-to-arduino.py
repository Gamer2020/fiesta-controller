import os
import serial
import yaml
from XInput import (
    get_events,
    EVENT_CONNECTED,
    EVENT_DISCONNECTED,
    EVENT_STICK_MOVED,
    LEFT,
    RIGHT,
    EVENT_BUTTON_PRESSED,
    EVENT_BUTTON_RELEASED,
    EVENT_TRIGGER_MOVED,
)

right_trig_flag = False
left_trig_flag = False

config_file = "config.yaml"

if os.path.exists(config_file) is False:
    print(config_file + " Not found!")
    quit()

with open(config_file, "r") as file:
    config_list = yaml.full_load(file)

arduino_port = config_list["port"]
arduino_baud = config_list["baud"]

arduinoSerial = serial.Serial(arduino_port, arduino_baud)

while 1:
    events = get_events()
    for event in events:
        if event.type == EVENT_CONNECTED:
            print("Controller Connected!")
        elif event.type == EVENT_DISCONNECTED:
            print("Controller Disconnected!")
        elif event.type == EVENT_STICK_MOVED:
            if event.stick == LEFT:
                if (event.x == 0.0) and (event.y == 0.0):
                    print("Left Stick is neutral")
                    arduinoSerial.write(b"b")
                    arduinoSerial.write(b"d")
                    arduinoSerial.write(b"f")
                    arduinoSerial.write(b"h")
                if event.x < -0.75:  # Left
                    arduinoSerial.write(b"a")
                    arduinoSerial.write(b"d")
                    arduinoSerial.write(b"f")
                    arduinoSerial.write(b"h")
                elif event.x > 0.75:  # Right
                    arduinoSerial.write(b"g")
                    arduinoSerial.write(b"b")
                    arduinoSerial.write(b"d")
                    arduinoSerial.write(b"f")
                if event.y > 0.75:  # Up
                    arduinoSerial.write(b"c")
                    arduinoSerial.write(b"b")
                    arduinoSerial.write(b"f")
                    arduinoSerial.write(b"h")
                elif event.y < -0.75:  # Down
                    arduinoSerial.write(b"e")
                    arduinoSerial.write(b"b")
                    arduinoSerial.write(b"d")
                    arduinoSerial.write(b"h")

            elif event.stick == RIGHT:
                if (event.x == 0.0) and (event.y == 0.0):
                    print("Right Stick is neutral")
                    arduinoSerial.write(b"l")
                elif event.x < 0.0:  # Left
                    arduinoSerial.write(b"k")
                    arduinoSerial.write(b"n")
                elif event.x > 0.0:  # Right
                    arduinoSerial.write(b"k")
                    arduinoSerial.write(b"m")
                if event.y > 0.0:  # Up
                    arduinoSerial.write(b"k")
                    arduinoSerial.write(b"o")
                elif event.y < 0.0:  # Down
                    arduinoSerial.write(b"k")
                    arduinoSerial.write(b"p")
        elif event.type == EVENT_TRIGGER_MOVED:
            if event.trigger == LEFT:
                if event.value == 0.0:
                    print("LEFT_TRIGGER Neutral!")
                    left_trig_flag = False
                elif (event.value > 0.0) and (left_trig_flag == False):
                    print("LEFT_TRIGGER Pressed!")
                    left_trig_flag = True
                    arduinoSerial.write(b"y")
            elif event.trigger == RIGHT:
                if event.value == 0.0:
                    right_trig_flag = False
                elif (event.value > 0.0) and (right_trig_flag == False):
                    print("RIGHT_TRIGGER Pressed!")
                    right_trig_flag = True
                    arduinoSerial.write(b"z")

        elif event.type == EVENT_BUTTON_PRESSED:
            if event.button == "LEFT_THUMB":
                print("LEFT_THUMB Pressed!")
                arduinoSerial.write(b"q")
            elif event.button == "RIGHT_THUMB":
                print("RIGHT_THUMB Pressed!")
                arduinoSerial.write(b"v")

            elif event.button == "LEFT_SHOULDER":
                print("LEFT_SHOULDER Pressed!")
                arduinoSerial.write(b"w")
            elif event.button == "RIGHT_SHOULDER":
                print("RIGHT_SHOULDER Pressed!")
                arduinoSerial.write(b"x")

            elif event.button == "BACK":
                print("BACK Pressed!")
                arduinoSerial.write(b"C")
            elif event.button == "START":
                print("START Pressed!")
                arduinoSerial.write(b"D")

            elif event.button == "DPAD_LEFT":
                print("DPAD_LEFT Pressed!")
                arduinoSerial.write(b"A")
            elif event.button == "DPAD_RIGHT":
                print("DPAD_RIGHT Pressed!")
                arduinoSerial.write(b"B")
            elif event.button == "DPAD_UP":
                print("DPAD_UP Pressed!")
                arduinoSerial.write(b"j")
            elif event.button == "DPAD_DOWN":
                print("DPAD_DOWN Pressed!")
                arduinoSerial.write(b"i")

            elif event.button == "A":
                print("A Pressed!")
                arduinoSerial.write(b"r")
            elif event.button == "B":
                print("B Pressed!")
                arduinoSerial.write(b"s")
            elif event.button == "Y":
                print("Y Pressed!")
                arduinoSerial.write(b"u")
            elif event.button == "X":
                print("X Pressed!")
                arduinoSerial.write(b"t")

        # The below is left here in case someone want's to do something on release.

        # elif event.type == EVENT_BUTTON_RELEASED:
        # if event.button == "LEFT_THUMB":
        #     print("LEFT_THUMB Released!")
        # elif event.button == "RIGHT_THUMB":
        #     print("RIGHT_THUMB Released!")

        # if event.button == "LEFT_SHOULDER":
        #     print("LEFT_SHOULDER Released!")
        # elif event.button == "RIGHT_SHOULDER":
        #     print("RIGHT_SHOULDER Released!")

        # elif event.button == "BACK":
        #     print("BACK Released!")
        # elif event.button == "START":
        #     print("START Released!")

        # elif event.button == "DPAD_LEFT":
        #     print("DPAD_LEFT Released!")
        # elif event.button == "DPAD_RIGHT":
        #     print("DPAD_RIGHT Released!")
        # elif event.button == "DPAD_UP":
        #     print("DPAD_UP Released!")
        # elif event.button == "DPAD_DOWN":
        #     print("DPAD_DOWN Released!")

        # elif event.button == "A":
        #     print("A Released!")
        # elif event.button == "B":
        #     print("B Released!")
        # elif event.button == "Y":
        #     print("Y Released!")
        # elif event.button == "X":
        #     print("X Released!")
