#pragma once

#include <NewPing.h>

#include <stdint.h>


class DistanceMeter
{
public:
    DistanceMeter(int echo_pin, int trigger_pin);
    virtual void begin();
    virtual uint16_t get_distance();
private:
    NewPing _ultrasonic;
};
