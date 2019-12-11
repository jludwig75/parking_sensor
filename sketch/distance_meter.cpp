#include "distance_meter.h"


DistanceMeter::DistanceMeter(int echo_pin, int trigger_pin) :
    _ultrasonic(trigger_pin, echo_pin, 400)
{
}

void DistanceMeter::begin()
{
}

uint16_t DistanceMeter::get_distance()
{
    return _ultrasonic.convert_cm(_ultrasonic.ping_median(10));
}
