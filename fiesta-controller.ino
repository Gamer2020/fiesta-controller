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
            sendKeyPress(KEY_HOME);
        }
        else if (command.equals(INPUT_COMMAND_j))
        {
            //press ASCII 'm'
            sendKeyPress(KEY_m);
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
            Mouse.move(0, -1, 0);
        }
        else if (command.equals(INPUT_COMMAND_p))
        {
            //Mouse Down
            Mouse.move(0, 1, 0);
        }
        else if (command.equals(INPUT_COMMAND_q))
        {
            //press TAB
            sendKeyPress(KEY_TAB);
        }
        else if (command.equals(INPUT_COMMAND_r))
        {
            //press ASCII '1'
            sendKeyPress(KEY_1);
        }
        else if (command.equals(INPUT_COMMAND_s))
        {
            //press ASCII '2'
            sendKeyPress(KEY_2);
        }
        else if (command.equals(INPUT_COMMAND_t))
        {
            //press ASCII '3'
            sendKeyPress(KEY_3);
        }
        else if (command.equals(INPUT_COMMAND_u))
        {
            //press ASCII '4'
            sendKeyPress(KEY_4);
        }
        else if (command.equals(INPUT_COMMAND_v))
        {
            //press TAB
            sendKeyPress(KEY_space);
        }
        else if (command.equals(INPUT_COMMAND_w))
        {
            //press ASCII '5'
            sendKeyPress(KEY_5);
        }
        else if (command.equals(INPUT_COMMAND_x))
        {
            //press ASCII '6'
            sendKeyPress(KEY_6);
        }
        else if (command.equals(INPUT_COMMAND_y))
        {
            //press ASCII '7'
            sendKeyPress(KEY_7);
        }
        else if (command.equals(INPUT_COMMAND_z))
        {
            //press ASCII '8'
            sendKeyPress(KEY_8);
        }
        else
        {
            Serial.println("Invalid command " + command);
        }
    }
}

int sendKeyPress(int key_to_send)
{
    Keyboard.press(key_to_send);
    delay(KEY_DELAY);
    Keyboard.release(key_to_send);
}
