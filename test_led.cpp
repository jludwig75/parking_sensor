#include "signal_led.h"

#include "led_bank.h"


SignalLED::SignalLED(int led_pin) :
    _led_pin(led_pin)
{
    LEDBank::instance().set_led_state(_led_pin, LEDBank::LEDState::Off);
}

void SignalLED::set_led_state(LEDState state)
{
    switch(state)
    {
        case Off:
            LEDBank::instance().set_led_state(_led_pin, LEDBank::LEDState::Off);
            break;
        case On:
            LEDBank::instance().set_led_state(_led_pin, LEDBank::LEDState::On);
            break;
        case Flashing:
            LEDBank::instance().set_led_state(_led_pin, LEDBank::LEDState::Flashing);
            break;
    }
}
