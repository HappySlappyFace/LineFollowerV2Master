// CommandSender.cpp

#include "CommandSender.h"
#include <HardwareSerial.h>

int debugCommunication=0;
// Constructor that takes a reference to a HardwareSerial object
CommandSender::CommandSender(HardwareSerial &serialPort) : serial(serialPort) {
    // Nothing needed here for now
}

// Method to send the speed command

void CommandSender::sendSetSpeed(int speed) const {
    String command = "SETSPD:" + String(speed) + "\n";
    serial.print(command);
    if(debugCommunication) { Serial.print("Sent command: ");
        Serial.println(command);
    }
}

void CommandSender::sendSetTarget(int target) const {
    String command = "T:" + String(target) + "\n";
    serial.print(command);

    if (debugCommunication) {
        Serial.print("Sent command: ");
        Serial.println(command);
    }

}

// Method to send the target command

// Method to send the stop command
void CommandSender::sendStop() const {
    String command = "STOP\n";
    serial.print(command);

    Serial.print("Sent command: ");
    Serial.println(command);
}

// Method to send the PID command
void CommandSender::sendSetPID(float p, float i, float d) const {
    String command = "SETPID:" + String(p, 1) + "," + String(i, 1) + "," + String(d, 1) + "\n";
    serial.print(command);
    Serial.print("Sent command: ");
    Serial.println(command);
}
void CommandSender::sendSetRPM1(int rpm) const {
    String command = "SETRPM1:" + String(rpm) + "\n";
    serial.print(command);
    Serial.print("Sent command for Motor 1: ");
    Serial.println(command);
}
void CommandSender::sendSetRPM2(int rpm) const {
    String command = "SETRPM2:" + String(rpm) + "\n";
    serial.print(command);
    Serial.print("Sent command for Motor 2: ");
    Serial.println(command);
}
