#include <Keyboard.h>

String command;

void setup() {
  Keyboard.begin();
  Serial.begin(9600); 
  delay(2000);  
  Serial.println("Waiting for input!");
}

void loop() {

        if(Serial.available()){
        command = Serial.readStringUntil('\n');
         
        if(command.equals("1")){
            Serial.println("1");
        }
        else if(command.equals("2")){
            Serial.println("2");
        }
        else if(command.equals("3")){
            Serial.println("3");
        }
        else if(command.equals("4")){
            Serial.println("4");
            //Send an ASCII 'A'
            Keyboard.write(65);
        }
        else{
            Serial.println("Invalid command");
        }
    }
}
