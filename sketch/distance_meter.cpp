#include "distance_meter.h"


DistanceMeter::DistanceMeter(int echo_pin, int trigger_pin) :
    _ultrasonic(trigger_pin, echo_pin)
{
}

void DistanceMeter::begin()
{
    _ultrasonic.begin();
}

uint16_t DistanceMeter::get_distance() const
{
    return _ultrasonic.getMedianFilterDistance();
}
