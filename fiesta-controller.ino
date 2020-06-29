#include <Keyboard.h>
#include <Mouse.h>

#include "include/config.h"
#include "include/commands.h"
#include "include/keyboard_keys.h"

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

        if (command.equals(INPUT_COMMAND_a))
        {
            //Hold ASCII 'a'
            Keyboard.press(KEY_a);
        }
        else if (command.equals(INPUT_COMMAND_b))
        {
            //Release ASCII 'a'
            Keyboard.release(KEY_a);
        }
        else if (command.equals(INPUT_COMMAND_c))
        {
            //Hold ASCII 'w'
            Keyboard.press(KEY_w);
        }
        else if (command.equals(INPUT_COMMAND_d))
        {
            //Release ASCII 'w'
            Keyboard.release(KEY_w);
        }
        else if (command.equals(INPUT_COMMAND_e))
        {
            //Hold ASCII 's'
            Keyboard.press(KEY_s);
        }
        else if (command.equals(INPUT_COMMAND_f))
        {
            //Release ASCII 's'
            Keyboard.release(KEY_s);
        }
        else if (command.equals(INPUT_COMMAND_g))
        {
            //Hold ASCII 'd'
            Keyboard.press(KEY_d);
        }
        else if (command.equals(INPUT_COMMAND_h))
        {
            //Release ASCII 'd'
            Keyboard.release(KEY_d);
        }
        else if (command.equals(INPUT_COMMAND_i))
        {
            //press HOME
            Keyboard.press(KEY_HOME);
            delay(KEY_DELAY);
            Keyboard.release(KEY_HOME);
        }
        else if (command.equals(INPUT_COMMAND_j))
        {
            //press ASCII 'm'
            Keyboard.press(109);
            delay(KEY_DELAY);
            Keyboard.release(109);
        }
        else if (command.equals(INPUT_COMMAND_k))
        {
            //Hold Right Mouse
            Mouse.press(MOUSE_RIGHT);
        }
        else if (command.equals(INPUT_COMMAND_l))
        {
            //Release Right Mouse
            Mouse.release(MOUSE_RIGHT);
        }
        else if (command.equals(INPUT_COMMAND_m))
        {
            //Mouse Right
            Mouse.move(5, 0, 0);
        }
        else if (command.equals(INPUT_COMMAND_n))
        {
            //Mouse Left
            Mouse.move(-5, 0, 0);
        }
        else if (command.equals(INPUT_COMMAND_o))
        {
            //Mouse Up
            Mouse.move(0, 0, 1);
        }
        else if (command.equals(INPUT_COMMAND_p))
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
