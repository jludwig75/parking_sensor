#include "test_parking_signal.h"


TestParkingSignal::TestParkingSignal(int red_pin, int green_pin, int blue_pin) :
    ParkingSignal(red_pin, green_pin, blue_pin),
    _range_state(OutOfRange),
    _closeness(NoMeasurement)
{

}

void TestParkingSignal::on_loop()
{

}

void TestParkingSignal::on_range_status(Closeness closeness, RangeState range_state)
{
    _range_state = range_state;
    _closeness = closeness;
}

TestParkingSignal::Closeness TestParkingSignal::get_closeness() const
{
    return _closeness;
}

TestParkingSignal::RangeState TestParkingSignal::get_range_state() const
{
    return _range_state;
}
