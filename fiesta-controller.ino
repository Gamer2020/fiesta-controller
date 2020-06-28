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
            Serial.println("a");
            //Hold ASCII 'a'
            Keyboard.press(97);
        }
        else if (command.equals("98"))
        {
            Serial.println("b");
            //Release ASCII 'a'
            Keyboard.release(97);
        }
        else if (command.equals("99"))
        {
            Serial.println("c");
        }
        else if (command.equals("100"))
        {
            Serial.println("d");
        }
        else
        {
            Serial.println("Invalid command " + command);
        }
    }
}
