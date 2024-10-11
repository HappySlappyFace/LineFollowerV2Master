// CommandSender.h

#ifndef COMMAND_SENDER_H
#define COMMAND_SENDER_H

#include <Arduino.h>

class CommandSender {
private:
    HardwareSerial &serial;  // Reference to the serial port (e.g., Serial2)

public:
    // Constructor
    CommandSender(HardwareSerial &serialPort);

    // Method prototypes
    void sendSetSpeed(int speed);
    void sendSetTarget(int target);
    void sendStop();
    void sendSetPID(float p, float i, float d);
};

#endif // COMMAND_SENDER_H
