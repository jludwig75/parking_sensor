#pragma once


#include "signal_led.h"


class ParkingSignal
{
public:
    ParkingSignal(int red_pin, int green_pin, int blue_pin);

    void on_loop();

    enum Closeness {
        NoMeasurement,
        TooFar,
        TooClose
    };
    enum RangeState
    {
        OutOfRange,
        CloseToRange,
        InRange
    };

    void on_range_status(Closeness closeness, RangeState range_state);

private:
    SignalLED _red_led;
    SignalLED _green_led;
    SignalLED _blue_lde;
};