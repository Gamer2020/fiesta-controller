#include <Keyboard.h>
#include <Mouse.h>

#include "include/config.h"

String command;
void setup()
{
    Keyboard.begin();
    Mouse.begin();
    Serial.begin(9600);
    delay(2000);
    Serial.println("Waiting for input!");
}

void loop()
{
    if (Serial.available())
    {
        command = Serial.read();

        if (command.equals("97"))
        {
            //Hold ASCII 'a'
            Keyboard.press(97);
        }
        else if (command.equals("98"))
        {
            //Release ASCII 'a'
            Keyboard.release(97);
        }
        else if (command.equals("99"))
        {
            //Hold ASCII 'w'
            Keyboard.press(119);
        }
        else if (command.equals("100"))
        {
            //Release ASCII 'w'
            Keyboard.release(119);
        }
        else if (command.equals("101"))
        {
            //Hold ASCII 's'
            Keyboard.press(115);
        }
        else if (command.equals("102"))
        {
            //Release ASCII 's'
            Keyboard.release(115);
        }
        else if (command.equals("103"))
        {
            //Hold ASCII 'd'
            Keyboard.press(100);
        }
        else if (command.equals("104"))
        {
            //Release ASCII 'd'
            Keyboard.release(100);
        }
        else if (command.equals("105"))
        {
            //press ASCII 'HOME'
            Keyboard.press(KEY_HOME);
            delay(KEY_DELAY);
            Keyboard.release(KEY_HOME);
        }
        else if (command.equals("106"))
        {
            //press ASCII 'm'
            Keyboard.press(109);
            delay(KEY_DELAY);
            Keyboard.release(109);
        }
        else if (command.equals("107"))
        {
            //Hold Right Mouse
            Mouse.press(MOUSE_RIGHT);
        }
        else if (command.equals("108"))
        {
            //Release Right Mouse
            Mouse.release(MOUSE_RIGHT);
        }
        else if (command.equals("109"))
        {
            //Mouse Right
            Mouse.move(5, 0, 0);
        }
        else if (command.equals("110"))
        {
            //Mouse Left
            Mouse.move(-5, 0, 0);
        }
        else if (command.equals("111"))
        {
            //Mouse Up
            Mouse.move(0, 0, 1);
        }
        else if (command.equals("112"))
        {
            //Mouse Down
            Mouse.move(0, 0, -10);
        }
        else
        {
            Serial.println("Invalid command " + command);
        }
    }
}
