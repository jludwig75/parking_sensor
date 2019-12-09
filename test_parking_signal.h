#pragma once

#include "parking_signal.h"


class TestParkingSignal : public ParkingSignal
{
public:
    TestParkingSignal(int red_pin, int green_pin, int blue_pin);
    void on_loop() override;
    void on_range_status(Closeness closeness, RangeState range_state) override;

    Closeness get_closeness() const;
    RangeState get_range_state() const;

private:
    Closeness _closeness;
    RangeState _range_state;
};