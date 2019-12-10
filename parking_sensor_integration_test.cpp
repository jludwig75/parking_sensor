#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "test_distance_meter.h"
#include "parking_signal.h"
#include "parking_sensor.h"
#include "led_bank.h"


#define ECHO_PIN        1
#define TRIGGER_PIN     2

#define RED_LED_PIN     3
#define GREEN_LED_PIN   4
#define BLUE_LED_PIN    5


TEST_CASE( "Parking Sensor integration test", "[ParkingSensor_integration]" ) {
    TestDistanceMeter distance_meter(ECHO_PIN, TRIGGER_PIN);
    ParkingSignal parking_signal(RED_LED_PIN, GREEN_LED_PIN, BLUE_LED_PIN);
    ParkingSensor parking_sensor(&distance_meter, &parking_signal);

    REQUIRE(LEDBank::instance().get_led_state(RED_LED_PIN) == LEDBank::Off);
    REQUIRE(LEDBank::instance().get_led_state(GREEN_LED_PIN) == LEDBank::Off);
    REQUIRE(LEDBank::instance().get_led_state(BLUE_LED_PIN) == LEDBank::Off);

    SECTION("No measurment") {
        distance_meter.set_distance(NO_MEASUREMENT_DISTANCE);
        parking_sensor.on_loop();

        REQUIRE(LEDBank::instance().get_led_state(RED_LED_PIN) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(GREEN_LED_PIN) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(BLUE_LED_PIN) == LEDBank::Off);
    }

    SECTION("Too far, not in range") {
        distance_meter.set_distance(200);
        parking_sensor.on_loop();

        REQUIRE(LEDBank::instance().get_led_state(RED_LED_PIN) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(GREEN_LED_PIN) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(BLUE_LED_PIN) == LEDBank::Off);
    }

    SECTION("Too far, close to range") {
        distance_meter.set_distance(180);
        parking_sensor.on_loop();

        REQUIRE(LEDBank::instance().get_led_state(RED_LED_PIN) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(GREEN_LED_PIN) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(BLUE_LED_PIN) == LEDBank::Flashing);
    }

    SECTION("In range") {
        distance_meter.set_distance(150);
        parking_sensor.on_loop();

        REQUIRE(LEDBank::instance().get_led_state(RED_LED_PIN) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(GREEN_LED_PIN) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(BLUE_LED_PIN) == LEDBank::On);
    }

    SECTION("Too close, close to range") {
        distance_meter.set_distance(120);
        parking_sensor.on_loop();

        REQUIRE(LEDBank::instance().get_led_state(RED_LED_PIN) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(GREEN_LED_PIN) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(BLUE_LED_PIN) == LEDBank::Flashing);
    }

    SECTION("Too close, not in range") {
        distance_meter.set_distance(10);
        parking_sensor.on_loop();

        REQUIRE(LEDBank::instance().get_led_state(RED_LED_PIN) == LEDBank::On);
        REQUIRE(LEDBank::instance().get_led_state(GREEN_LED_PIN) == LEDBank::Off);
        REQUIRE(LEDBank::instance().get_led_state(BLUE_LED_PIN) == LEDBank::Off);
    }
}