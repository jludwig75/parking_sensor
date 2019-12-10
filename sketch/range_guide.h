#pragma once

#include <cstdint>


class ParkingSignal;


#define NO_MEASUREMENT_DISTANCE 0


class RangeGuide
{
public:
    RangeGuide(ParkingSignal *parking_signal, uint16_t target_distance, uint16_t target_threshold_distance, uint16_t closeness_threshold_distance);

    void on_distance_changed(uint16_t distance);

private:
    ParkingSignal *_parking_signal;
    const uint16_t _target_distance;
    const uint16_t _target_threshold_distance;
    const uint16_t _closeness_threshold_distance;
};