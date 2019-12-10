#include "signal_led.h"


#define RED_LED_PIN     3
#define GREEN_LED_PIN   4
#define BLUE_LED_PIN    5

#define STATE_TEST_DURATION_SEC 3
#define NUM_LEDS          3
#define NUM_TESTS_PER_LED 3
#define NUM_TESTS         (NUM_LEDS * NUM_TESTS_PER_LED)

SignalLED red_led(RED_LED_PIN);
SignalLED green_led(GREEN_LED_PIN);
SignalLED blue_led(BLUE_LED_PIN);

SignalLED *signal_leds[NUM_LEDS];
const char *led_colors[NUM_LEDS];

void setup()
{
  Serial.begin(115200);
  red_led.begin();
  signal_leds[0] = &red_led;
  led_colors[0] = "red";

  signal_leds[1] = &green_led;
  led_colors[1] = "green";

  signal_leds[2] = &blue_led;
  led_colors[2] = "blue";
}

unsigned current_global_test_number = 0xFFFF;

void loop()
{
  red_led.on_loop();
  unsigned global_test_number = (millis() / (STATE_TEST_DURATION_SEC * 1000)) % NUM_TESTS;

  if (global_test_number != current_global_test_number)
  {
    current_global_test_number = global_test_number;
    unsigned led_number = global_test_number / NUM_TESTS_PER_LED;
    unsigned test_number = global_test_number % NUM_TESTS_PER_LED;
    switch(test_number)
    {
      case 0:
        Serial.print("Testing ");
        Serial.print(led_colors[led_number]);
        Serial.println(" LED in state Off");
        signal_leds[led_number]->set_led_state(SignalLED::Off);
        break;
      case 1:
        Serial.print("Testing ");
        Serial.print(led_colors[led_number]);
        Serial.println(" LED in state On");
        signal_leds[led_number]->set_led_state(SignalLED::On);
        break;
      case 2:
        Serial.print("Testing ");
        Serial.print(led_colors[led_number]);
        Serial.println(" LED in state Flashing");
        signal_leds[led_number]->set_led_state(SignalLED::Flashing);
        break;
    }
  }
}
