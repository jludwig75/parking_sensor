#include "signal_led.h"

#include <Arduino.h>

SignalLED::SignalLED(int led_pin) :
    _led_pin(led_pin),
    _state(Off),
    _current_pin_level(10)  // Not HIGH or LOW
{
}

void SignalLED::begin()
{
    pinMode(_led_pin, OUTPUT);
}

void SignalLED::set_pint_level(int level)
{
    if (level != _current_pin_level)
    {
        digitalWrite(_led_pin, level);
        _current_pin_level = level;
    }
}

void SignalLED::on_loop()
{
    switch(_state)
    {
        case Off:
            set_pint_level(LOW);
            break;
        case On:
            set_pint_level(HIGH);
            break;
        case Flashing:
            if (millis() % 1000 < 500)
            {
                // On for the first half of the second
                set_pint_level(HIGH);
            }
            else
            {
                // Off for the second half of the second
                set_pint_level(LOW);
            }
            break;
    }
}

void SignalLED::set_led_state(LEDState state)
{
    _state = state;
}
