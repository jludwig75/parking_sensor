#pragma once


#define MAX_LEDS    50


class LEDBank
{
public:
    static LEDBank &instance();

    enum LEDState
    {
        Off,
        On,
        Flashing
    };

    void set_led_state(int led_pin ,LEDState state);
    LEDState get_led_state(int led_pin) const;

protected:
    LEDBank();

private:
    LEDState _led_states[MAX_LEDS];
};