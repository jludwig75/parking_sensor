#include "parking_sensor.h"

#include "distance_meter.h"
#include "parking_signal.h"


#define MIN_VALID_DISTANCE  10
#define MAX_VALID_DISTANCE  130


ParkingSensor::ParkingSensor(DistanceMeter *distance_meter, ParkingSignal *parking_signal) :
    _range_guide(parking_signal, 150, 5, 30),
    _distance_meter(distance_meter),
    _parking_signal(parking_signal),
    _last_distance(UINT16_MAX)
{

}

void ParkingSensor::begin()
{
    _distance_meter->begin();
    _parking_signal->begin();
}

static bool distance_valid(uint16_t distance)
{
    return distance >= MIN_VALID_DISTANCE && distance <= MAX_SENSOR_DISTANCE;
}

void ParkingSensor::on_loop()
{
    uint16_t distance = _distance_meter->get_distance();
    if (distance_valid(distance) && distance != _last_distance)
    {
        _range_guide.on_distance_changed(distance);
        _last_distance = distance;
    }

    _parking_signal->on_loop();
}
