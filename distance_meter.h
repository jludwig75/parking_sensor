#pragma once

#include <cstdint>


class DistanceMeter
{
public:
    DistanceMeter(int echo_pin, int trigger_pin);
    uint16_t get_distance() const;
};