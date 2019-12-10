#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "range_guide.h"
#include "parking_signal.h"
#include "led_bank.h"


TEST_CASE( "Parking Signal state set correctly", "[RangeGuide]" ) {
    const int red_led_pin = 10;
    const int green_led_pin = 11;
    const int blue_led_pin = 12;

    ParkingSignal signal(red_led_pin, green_led_pin, blue_led_pin);
    REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
    REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
    REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Off);

    const uint16_t target_distance = 150;
    const uint16_t target_threshold_distance = 5;
    const uint16_t closeness_threshold_distance = 30;
    RangeGuide range_guide(&signal, target_distance, target_threshold_distance, closeness_threshold_distance);

    SECTION("No measurment") {
        range_guide.on_distance_changed(NO_MEASUREMENT_DISTANCE);

        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Off);
    }

    SECTION("Too far, not in range") {
        range_guide.on_distance_changed(200);

        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Off);
    }

    SECTION("Too far, close to range") {
        range_guide.on_distance_changed(180);

        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Flashing);
    }

    SECTION("In range") {
        range_guide.on_distance_changed(150);

        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::On);
    }

    SECTION("Too close, close to range") {
        range_guide.on_distance_changed(120);

        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Flashing);
    }

    SECTION("Too close, not in range") {
        range_guide.on_distance_changed(10);

        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Off);
    }
}