#include <Keyboard.h>
#include <Mouse.h>

#include "include/config.h"
#include "include/commands.h"

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

        if (command.equals(input_command_a))
        {
            //Hold ASCII 'a'
            Keyboard.press(97);
        }
        else if (command.equals(input_command_b))
        {
            //Release ASCII 'a'
            Keyboard.release(97);
        }
        else if (command.equals(input_command_c))
        {
            //Hold ASCII 'w'
            Keyboard.press(119);
        }
        else if (command.equals(input_command_d))
        {
            //Release ASCII 'w'
            Keyboard.release(119);
        }
        else if (command.equals(input_command_e))
        {
            //Hold ASCII 's'
            Keyboard.press(115);
        }
        else if (command.equals(input_command_f))
        {
            //Release ASCII 's'
            Keyboard.release(115);
        }
        else if (command.equals(input_command_g))
        {
            //Hold ASCII 'd'
            Keyboard.press(100);
        }
        else if (command.equals(input_command_h))
        {
            //Release ASCII 'd'
            Keyboard.release(100);
        }
        else if (command.equals(input_command_i))
        {
            //press ASCII 'HOME'
            Keyboard.press(KEY_HOME);
            delay(KEY_DELAY);
            Keyboard.release(KEY_HOME);
        }
        else if (command.equals(input_command_j))
        {
            //press ASCII 'm'
            Keyboard.press(109);
            delay(KEY_DELAY);
            Keyboard.release(109);
        }
        else if (command.equals(input_command_k))
        {
            //Hold Right Mouse
            Mouse.press(MOUSE_RIGHT);
        }
        else if (command.equals(input_command_l))
        {
            //Release Right Mouse
            Mouse.release(MOUSE_RIGHT);
        }
        else if (command.equals(input_command_m))
        {
            //Mouse Right
            Mouse.move(5, 0, 0);
        }
        else if (command.equals(input_command_n))
        {
            //Mouse Left
            Mouse.move(-5, 0, 0);
        }
        else if (command.equals(input_command_o))
        {
            //Mouse Up
            Mouse.move(0, 0, 1);
        }
        else if (command.equals(input_command_p))
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
