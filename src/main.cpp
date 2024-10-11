//
// Created by hsf on 05/10/24.
//

#include "CommandSender.h"  // Include the CommandSender class

#include <HardwareSerial.h>

HardwareSerial masterSerial(2);  // Use Serial2 for communication with the slave ESP32

CommandSender commandSender(masterSerial);  // Create an instance of CommandSender

unsigned long lastCommandTime = 0;
const unsigned long commandInterval = 1500;  //     500 ms delay between commands

int commandIndex = 2;
int test=1;

void setup() {
    // Initialize UART at 115200 baud rate (TX=17, RX=16 for master ESP32)
    masterSerial.begin(115200, SERIAL_8N1, 16, 17);  // TX=17, RX=16 for UART communication

    Serial.begin(115200);  // For debugging
}

void loop() {
    // Check if 500ms has passed to send the next command
    if(test){
        if (millis() - lastCommandTime >= commandInterval) {
            lastCommandTime = millis();  // Reset the timer

            // Execute different commands based on commandIndex
            switch (commandIndex) {
                case 0:
                    commandSender.sendSetPID(0.7, 2.5, 0.1);  // Set PID values (P=1.0, I=0.5, D=0.1)
                    // commandSender.sendSetPID(3, 3.0, 0.05);  // Set PID values (P=1.0, I=0.5, D=0.1)
                    // commandSender.sendSetSpeed(600);  // Set speed to 100
                    commandSender.sendSetRPM1(100);
                    commandSender.sendSetRPM2(-100);
                break;
                case 1:
                    commandSender.sendSetPID(1.4, 1.4, 0);
                    commandSender.sendStop();         // Stop the motors
                    test=0;
                break;
                case 2:
                    commandSender.sendSetPID(2.4, 3, 0.01);  // Set PID values (P=1.0, I=0.5, D=0.1)
                    commandSender.sendSetRPM1(250);
                    commandSender.sendSetRPM2(220);
                // commandSender.sendSetTarget(50);  // Set target (steering) to 50

                break;
                case 3:
                    commandSender.sendSetPID(2.4, 3, 0.01);  // Set PID values (P=1.0, I=0.5, D=0.1)
                    commandSender.sendSetRPM1(100);
                    commandSender.sendSetRPM2(150);
                    // commandSender.sendSetPID(1.0, 0.5, 0.1);  // Set PID values (P=1.0, I=0.5, D=0.1)
                break;
                case 4:
                    commandSender.sendSetPID(1.4, 1.4, 0);
                    commandSender.sendStop();         // Stop the motors
                    break;
                case 5:
                    commandSender.sendSetPID(0.7, 2.5, 0.1);  // Set PID values (P=1.0, I=0.5, D=0.1)
                    // commandSender.sendSetPID(3, 3.0, 0.05);  // Set PID values (P=1.0, I=0.5, D=0.1)
                    // commandSender.sendSetSpeed(600);  // Set speed to 100
                    commandSender.sendSetRPM1(100);
                    commandSender.sendSetRPM2(-100);
                break;
                default:
                    commandSender.sendSetPID(1.4, 1.4, 0);
                    commandSender.sendStop();         // Stop the motors
                    test=0;


            }

            // Increment command index, loop back if it exceeds the number of commands
            commandIndex = (commandIndex + 1);  // We have 4 commands, so we loop after the last command
        }
    }
}
