#pragma once


class DistanceMeter;
class ParkingSignal;


class ParkingSensor
{
public:
    ParkingSensor(DistanceMeter *distance_meter, ParkingSignal *parking_signal);

    void on_loop();
private:
    DistanceMeter *_distance_meter;
    ParkingSignal *_parking_signal;
};