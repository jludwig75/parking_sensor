#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "range_guide.h"

#include "test_parking_signal.h"

TEST_CASE( "Parking Signal state set correctly", "[RangeGuide]" ) {
    TestParkingSignal parking_signal(10, 11, 12);

    REQUIRE(parking_signal.get_closeness() == ParkingSignal::NoMeasurement);
    REQUIRE(parking_signal.get_range_state() == ParkingSignal::OutOfRange);

    const uint16_t target_distance = 150;
    const uint16_t target_threshold_distance = 5;
    const uint16_t closeness_threshold_distance = 30;
    RangeGuide range_guide(&parking_signal, target_distance, target_threshold_distance, closeness_threshold_distance);

    SECTION("No measurment") {
        range_guide.on_distance_changed(NO_MEASUREMENT_DISTANCE);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::NoMeasurement);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::OutOfRange);
    }

    SECTION("Too far, not in range") {
        range_guide.on_distance_changed(200);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::TooFar);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::OutOfRange);
    }

    SECTION("Too far, barely not close range") {
        range_guide.on_distance_changed(181);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::TooFar);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::OutOfRange);
    }

    SECTION("Too far, close to range") {
        range_guide.on_distance_changed(180);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::TooFar);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::CloseToRange);
    }

    SECTION("Far, but barely in range") {
        range_guide.on_distance_changed(145);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::AtTarget);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::InRange);
    }

    SECTION("In range") {
        range_guide.on_distance_changed(150);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::AtTarget);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::InRange);
    }

    SECTION("Close, but barely in range") {
        range_guide.on_distance_changed(155);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::AtTarget);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::InRange);
    }

    SECTION("Too close, close to range") {
        range_guide.on_distance_changed(120);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::TooClose);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::CloseToRange);
    }

    SECTION("Too close, barely not in range") {
        range_guide.on_distance_changed(119);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::TooClose);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::OutOfRange);
    }

    SECTION("Too close, not in range") {
        range_guide.on_distance_changed(10);

        REQUIRE(parking_signal.get_closeness() == ParkingSignal::TooClose);
        REQUIRE(parking_signal.get_range_state() == ParkingSignal::OutOfRange);
    }
}