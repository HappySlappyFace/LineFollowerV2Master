// CommandSender.cpp

#include "CommandSender.h"
#include <HardwareSerial.h>


// Constructor that takes a reference to a HardwareSerial object
CommandSender::CommandSender(HardwareSerial &serialPort) : serial(serialPort) {
    // Nothing needed here for now
}

// Method to send the speed command
void CommandSender::sendSetSpeed(int speed) {
    String command = "SETSPD:" + String(speed) + "\n";
    serial.print(command);
    Serial.print("Sent command: ");
    Serial.println(command);
}

// Method to send the target command
void CommandSender::sendSetTarget(int target) {
    String command = "SETTGT:" + String(target) + "\n";
    serial.print(command);
    Serial.print("Sent command: ");
    Serial.println(command);
}

// Method to send the stop command
void CommandSender::sendStop() {
    String command = "STOP\n";
    serial.print(command);
    Serial.print("Sent command: ");
    Serial.println(command);
}

// Method to send the PID command
void CommandSender::sendSetPID(float p, float i, float d) {
    String command = "SETPID:" + String(p, 1) + "," + String(i, 1) + "," + String(d, 1) + "\n";
    serial.print(command);
    Serial.print("Sent command: ");
    Serial.println(command);
}
