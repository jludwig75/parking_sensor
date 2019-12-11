#pragma once

#include "distance_meter.h"


class TestDistanceMeter : public DistanceMeter
{
public:
    TestDistanceMeter(int echo_pin, int trigger_pin);
    void begin() override;
    uint16_t get_distance() override;
    void set_distance(uint16_t distance);
private:
    uint16_t _distance;
};