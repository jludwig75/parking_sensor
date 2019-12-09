#include "signal_led.h"

#include "led_bank.h"


SignalLED::SignalLED(int led_pin) :
    _led_pin(led_pin)
{
    LEDBank::instance().set_led_state(_led_pin, LEDBank::Off);
}

void SignalLED::on_loop()
{
    LEDBank::instance().on_loop(_led_pin);
}

void SignalLED::set_led_state(LEDState state)
{
    switch(state)
    {
        case Off:
            LEDBank::instance().set_led_state(_led_pin, LEDBank::Off);
            break;
        case On:
            LEDBank::instance().set_led_state(_led_pin, LEDBank::On);
            break;
        case Flashing:
            LEDBank::instance().set_led_state(_led_pin, LEDBank::Flashing);
            break;
    }
}
