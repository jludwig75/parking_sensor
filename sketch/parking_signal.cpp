#include "parking_signal.h"

#include <assert.h>

ParkingSignal::ParkingSignal(int red_pin, int green_pin, int blue_pin) :
    _red_led(red_pin),
    _green_led(green_pin),
    _blue_led(blue_pin)
{

}

void ParkingSignal::on_loop()
{
    _red_led.on_loop();
    _green_led.on_loop();
    _blue_led.on_loop();
}

void ParkingSignal::on_range_status(Closeness closeness, RangeState range_state)
{
    switch(closeness)
    {
        case NoMeasurement:
            assert(range_state == OutOfRange);
            _red_led.set_led_state(SignalLED::Off);
            _green_led.set_led_state(SignalLED::Off);
            _blue_led.set_led_state(SignalLED::Off);
            break;
        case TooFar:
            assert(range_state != InRange);
            _red_led.set_led_state(SignalLED::Off);
            _green_led.set_led_state(SignalLED::On);
            switch(range_state)
            {
                case OutOfRange:
                    _blue_led.set_led_state(SignalLED::Off);
                    break;
                case CloseToRange:
                    _blue_led.set_led_state(SignalLED::Flashing);
                    break;
            }
            break;
        case TooClose:
            assert(range_state != InRange);
            _red_led.set_led_state(SignalLED::On);
            _green_led.set_led_state(SignalLED::Off);
            switch(range_state)
            {
                case OutOfRange:
                    _blue_led.set_led_state(SignalLED::Off);
                    break;
                case CloseToRange:
                    _blue_led.set_led_state(SignalLED::Flashing);
                    break;
            }
            break;
        case AtTarget:
            assert(range_state == InRange);
            _red_led.set_led_state(SignalLED::Off);
            _green_led.set_led_state(SignalLED::Off);
            _blue_led.set_led_state(SignalLED::On);
            break;
    }
}
