#include "range_guide.h"

#include "parking_signal.h"

#include <assert.h>


RangeGuide::RangeGuide(ParkingSignal *parking_signal, uint16_t target_distance, uint16_t target_threshold_distance, uint16_t closeness_threshold_distance) :
    _parking_signal(parking_signal),
    _target_distance(target_distance),
    _target_threshold_distance(target_threshold_distance),
    _closeness_threshold_distance(closeness_threshold_distance)
{

}

static uint16_t calc_distance(uint16_t target, uint16_t value)
{
    if (target > value)
    {
        return target - value;
    }

    return value - target;
}

void RangeGuide::on_distance_changed(uint16_t distance)
{
    ParkingSignal::Closeness closeness = ParkingSignal::NoMeasurement;
    ParkingSignal::RangeState range_state = ParkingSignal::OutOfRange;
    
    if (distance != NO_MEASUREMENT_DISTANCE)
    {
        uint16_t abs_dist = calc_distance(_target_distance, distance);
        if (abs_dist <= _target_threshold_distance)
        {
            range_state = ParkingSignal::InRange;
            closeness = ParkingSignal::AtTarget;
        }
        else
        {
            int32_t dist = static_cast<int32_t>(distance) - static_cast<int32_t>(_target_distance);

            if (dist > 0)
            {
                closeness = ParkingSignal::TooFar;
            }
            else
            {
                closeness = ParkingSignal::TooClose;
            }
            
            if (abs_dist <= _closeness_threshold_distance)
            {
                assert(closeness != ParkingSignal::AtTarget);
                range_state = ParkingSignal::CloseToRange;
            }
            else
            {
                assert(closeness != ParkingSignal::AtTarget);
                range_state = ParkingSignal::OutOfRange;
            }            
        }
        
    }

    _parking_signal->on_range_status(closeness, range_state);
}
