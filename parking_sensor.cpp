#include "parking_sensor.h"

#include "distance_meter.h"
#include "parking_signal.h"

ParkingSensor(DistanceMeter *distance_meter, ParkingSignal *parking_signal) :
    _distance_meter(distance_meter),
    _parking_signal(parking_signal)
{

}

void ParkingSensor::on_loop()
{
    _parking_signal->on_loop();
}
