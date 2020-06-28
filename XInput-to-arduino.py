import serial
from XInput import *

arduinoSerial = serial.Serial("COM4", 9600)

while 1:
    events = get_events()
    for event in events:
        if event.type == EVENT_CONNECTED:
            print("Controller Connected!")
        elif event.type == EVENT_DISCONNECTED:
            print("Controller Disconnected!")
        # elif event.type == EVENT_STICK_MOVED:
        #     if event.stick == LEFT:
        #     elif event.stick == RIGHT:
        # elif event.type == EVENT_TRIGGER_MOVED:
        #     if event.trigger == LEFT:
        #     elif event.trigger == RIGHT:

        elif event.type == EVENT_BUTTON_PRESSED:
            if event.button == "LEFT_THUMB":
                print("LEFT_THUMB Pressed!")
            elif event.button == "RIGHT_THUMB":
                print("RIGHT_THUMB Pressed!")

            elif event.button == "LEFT_SHOULDER":
                print("LEFT_SHOULDER Pressed!")
            elif event.button == "RIGHT_SHOULDER":
                print("RIGHT_SHOULDER Pressed!")

            elif event.button == "BACK":
                print("BACK Pressed!")
            elif event.button == "START":
                print("START Pressed!")

            elif event.button == "DPAD_LEFT":
                print("DPAD_LEFT Pressed!")
            elif event.button == "DPAD_RIGHT":
                print("DPAD_RIGHT Pressed!")
            elif event.button == "DPAD_UP":
                print("DPAD_UP Pressed!")
            elif event.button == "DPAD_DOWN":
                print("DPAD_DOWN Pressed!")

            elif event.button == "A":
                print("A Pressed!")
                arduinoSerial.write(b'a')
                print(arduinoSerial.readline())
            elif event.button == "B":
                print("B Pressed!")
            elif event.button == "Y":
                print("Y Pressed!")
            elif event.button == "X":
                print("X Pressed!")

        elif event.type == EVENT_BUTTON_RELEASED:
            if event.button == "LEFT_THUMB":
                print("LEFT_THUMB Released!")
            elif event.button == "RIGHT_THUMB":
                print("RIGHT_THUMB Released!")

            elif event.button == "LEFT_SHOULDER":
                print("LEFT_SHOULDER Released!")
            elif event.button == "RIGHT_SHOULDER":
                print("RIGHT_SHOULDER Released!")

            elif event.button == "BACK":
                print("BACK Released!")
            elif event.button == "START":
                print("START Released!")

            elif event.button == "DPAD_LEFT":
                print("DPAD_LEFT Released!")
            elif event.button == "DPAD_RIGHT":
                print("DPAD_RIGHT Released!")
            elif event.button == "DPAD_UP":
                print("DPAD_UP Released!")
            elif event.button == "DPAD_DOWN":
                print("DPAD_DOWN Released!")

            elif event.button == "A":
                print("A Released!")
                arduinoSerial.write(b'b')
                print(arduinoSerial.readline())
            elif event.button == "B":
                print("B Released!")
            elif event.button == "Y":
                print("Y Released!")
            elif event.button == "X":
                print("X Released!")
