#pragma once

#include <HCSR04.h>

#include <stdint.h>


class DistanceMeter
{
public:
    DistanceMeter(int echo_pin, int trigger_pin);
    virtual void begin();
    virtual uint16_t get_distance() const;
private:
    HCSR04 _ultrasonic;
};
