#pragma once

#include "distance_meter.h"


class TestDistanceMeter : protected DistanceMeter
{
    TestDistanceMeter(int echo_pin, int trigger_pin);
    uint16_t get_distance() const;
    void set_distance(uint16_t distance);
private:
    uint16_t _distance;
};