#include "range_guide.h"

#include <cstdlib>


RangeGuide *instance = NULL;
static unsigned range_updates = 0;
static uint16_t current_distance = 0;

RangeGuide *get_instance()
{
    return instance;
}

unsigned get_range_updates()
{
    return range_updates;
}

uint16_t get_current_distance()
{
    return current_distance;
}

RangeGuide::RangeGuide(ParkingSignal *parking_signal, uint16_t target_distance, uint16_t target_threshold_distance, uint16_t closeness_threshold_distance) :
    _parking_signal(parking_signal),
    _target_distance(target_distance),
    _target_threshold_distance(target_threshold_distance),
    _closeness_threshold_distance(closeness_threshold_distance)
{
    instance = this;
}

void RangeGuide::on_distance_changed(uint16_t distance)
{
    current_distance = distance;
    range_updates++;
}
