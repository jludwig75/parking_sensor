#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "parking_signal.h"
#include "led_bank.h"


TEST_CASE( "Signal LED's are set correctly", "[ParkingSignal]" ) {
    const int red_led_pin = 10;
    const int green_led_pin = 11;
    const int blue_led_pin = 12;

    ParkingSignal signal(red_led_pin, green_led_pin, blue_led_pin);
    REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
    REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
    REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Off);

    SECTION("No measurement") {
        signal.on_range_status(ParkingSignal::NoMeasurement, ParkingSignal::OutOfRange);
        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Off);
    }

    SECTION("Too far, out of range") {
        signal.on_range_status(ParkingSignal::TooFar, ParkingSignal::OutOfRange);
        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Off);
    }

    SECTION("Too far, close to range") {
        signal.on_range_status(ParkingSignal::TooFar, ParkingSignal::CloseToRange);
        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Flashing);
    }

    SECTION("Within range") {
        signal.on_range_status(ParkingSignal::AtTarget, ParkingSignal::InRange);
        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::On);
    }

    SECTION("Too close, close to range") {
        signal.on_range_status(ParkingSignal::TooClose, ParkingSignal::CloseToRange);
        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Flashing);
    }

    SECTION("Too close, out to range") {
        signal.on_range_status(ParkingSignal::TooClose, ParkingSignal::OutOfRange);
        REQUIRE(LEDBank::instance().get_led_state(red_led_pin) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(green_led_pin) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(blue_led_pin) == LEDBank::Off);
    }
}

TEST_CASE( "on_loop calls on_loop for all LED's", "[ParkingSignal]" ) {
    const int red_led_pin = 10;
    const int green_led_pin = 11;
    const int blue_led_pin = 12;

    ParkingSignal signal(red_led_pin, green_led_pin, blue_led_pin);
    REQUIRE(LEDBank::instance().get_loop_count(red_led_pin) == 0);
    REQUIRE(LEDBank::instance().get_loop_count(green_led_pin) == 0);
    REQUIRE(LEDBank::instance().get_loop_count(blue_led_pin) == 0);

    signal.on_loop();
    REQUIRE(LEDBank::instance().get_loop_count(red_led_pin) == 1);
    REQUIRE(LEDBank::instance().get_loop_count(green_led_pin) == 1);
    REQUIRE(LEDBank::instance().get_loop_count(blue_led_pin) == 1);

    signal.on_loop();
    REQUIRE(LEDBank::instance().get_loop_count(red_led_pin) == 2);
    REQUIRE(LEDBank::instance().get_loop_count(green_led_pin) == 2);
    REQUIRE(LEDBank::instance().get_loop_count(blue_led_pin) == 2);
}
