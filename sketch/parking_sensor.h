#pragma once

#include "range_guide.h"


class DistanceMeter;
class ParkingSignal;


class ParkingSensor
{
public:
    ParkingSensor(DistanceMeter *distance_meter, ParkingSignal *parking_signal);

    void begin();
    void on_loop();

private:
    RangeGuide _range_guide;
    DistanceMeter *_distance_meter;
    ParkingSignal *_parking_signal;
    uint16_t _last_distance;
};
