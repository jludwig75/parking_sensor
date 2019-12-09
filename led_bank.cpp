#include "led_bank.h"

#include <assert.h>


LEDBank &LEDBank::instance()
{
    static LEDBank instance;

    return instance;
}

LEDBank::LEDBank()
{
    for(int i = 0; i < MAX_LEDS; i++)
    {
        _led_states[i] = Off;
        _led_loop_counts[i] = 0;
    }
}

void LEDBank::set_led_state(int led_pin ,LEDBank::LEDState state)
{
    assert(led_pin < MAX_LEDS);

    _led_states[led_pin] = state;
}

LEDBank::LEDState LEDBank::get_led_state(int led_pin) const
{
    assert(led_pin < MAX_LEDS);

    return _led_states[led_pin];
}

void LEDBank::on_loop(int led_pin)
{
    assert(led_pin < MAX_LEDS);

    _led_loop_counts[led_pin]++;
}

unsigned LEDBank::get_loop_count(int led_pin) const
{
    assert(led_pin < MAX_LEDS);

    return _led_loop_counts[led_pin];
}
