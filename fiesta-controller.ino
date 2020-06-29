#include <Keyboard.h>

String command;

void setup()
{
    Keyboard.begin();
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
            delay(800);
            Keyboard.release(KEY_HOME);
        }
        else if (command.equals("106"))
        {
            //press ASCII 'HOME'
            Keyboard.press(109);
            delay(500);
            Keyboard.release(109);
        }
        else
        {
            Serial.println("Invalid command " + command);
        }
    }
}
