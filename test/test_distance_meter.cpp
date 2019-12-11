#include "test_distance_meter.h"


TestDistanceMeter::TestDistanceMeter(int echo_pin, int trigger_pin) :
    DistanceMeter(echo_pin, trigger_pin),
    _distance(0)
{

}

void TestDistanceMeter::begin()
{
}

uint16_t TestDistanceMeter::get_distance()
{
    return _distance;
}

void TestDistanceMeter::set_distance(uint16_t distance)
{
    _distance = distance;
}
