#pragma once


class SignalLED
{
public:
    SignalLED(int led_pin);

    void begin();

    void on_loop();

    enum LEDState
    {
        Off,
        On,
        Flashing
    };

    void set_led_state(LEDState state);

private:
    const int _led_pin;
    LEDState _state;
};
