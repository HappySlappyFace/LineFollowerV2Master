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
    void sendSetSpeed(int speed) const;
    void sendSetTarget(int target) const;
    void sendStop() const;
    void sendSetPID(float p, float i, float d) const;

    void sendSetRPM1(int rpm) const;

    void sendSetRPM2(int rpm) const;
};

#endif // COMMAND_SENDER_H
