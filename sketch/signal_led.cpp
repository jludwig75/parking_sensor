#include "signal_led.h"

SignalLED::SignalLED(int led_pin) :
    _led_pin(led_pin),
    _state(Off)
{
}

void SignalLED::begin()
{
}

void SignalLED::on_loop()
{
}

void SignalLED::set_led_state(LEDState state)
{
    _state = state;
}
