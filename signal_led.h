#pragma once


class SignalLED
{
public:
    SignalLED(int led_pin);

    void on_loop();

    enum LEDState
    {
        Off,
        On,
        Flashing
    };

    void set_led_state(LEDState state);

private:
    int _led_pin;
};