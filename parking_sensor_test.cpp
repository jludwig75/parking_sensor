#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "parking_sensor.h"

#include "test_parking_signal.h"
#include "test_distance_meter.h"
#include "test_range_guide.h"


TEST_CASE( "Parking Sensor effects closeness range", "[ParkingSensor]" ) {
    TestParkingSignal parking_signal(10, 11, 12);
    REQUIRE(parking_signal.get_closeness() == ParkingSignal::NoMeasurement);
    REQUIRE(parking_signal.get_range_state() == ParkingSignal::OutOfRange);

    TestDistanceMeter distance_meter(1, 2);
    
    ParkingSensor parking_sensor(&distance_meter, &parking_signal);

    RangeGuide *range_guide = get_instance();
    REQUIRE(range_guide != NULL);

    unsigned total_status_updates = 0;
    SECTION("No signal thrice") {
        for (int i = 0; i < 3; i++)
        {
            distance_meter.set_distance(0);
            parking_sensor.on_loop();
            REQUIRE(get_current_distance() == 0);
            REQUIRE(get_range_updates() == 1);
        }
    }

    SECTION("Some distance thrice") {
        for (int i = 0; i < 3; i++)
        {
            distance_meter.set_distance(100);
            parking_sensor.on_loop();
            REQUIRE(get_current_distance() == 100);
            REQUIRE(get_range_updates() == 2);
        }
    }

    SECTION("Three diffetent distances") {
        for (int i = 0; i < 3; i++)
        {
            uint16_t test_distance = (i + 1) * 10;
            distance_meter.set_distance(test_distance);
            parking_sensor.on_loop();
            REQUIRE(get_current_distance() == test_distance);
            REQUIRE(get_range_updates() == 3 + i);
        }
    }
}

TEST_CASE( "on_loop calls ParkingSignal::on_loop", "[ParkingSensor]" ) {
    TestParkingSignal parking_signal(10, 11, 12);
    REQUIRE(parking_signal.get_closeness() == ParkingSignal::NoMeasurement);
    REQUIRE(parking_signal.get_range_state() == ParkingSignal::OutOfRange);

    TestDistanceMeter distance_meter(1, 2);
    
    ParkingSensor parking_sensor(&distance_meter, &parking_signal);

    for (unsigned i = 0 ; i < 4; i++)
    {
        REQUIRE(parking_signal.get_loop_count() == i);
        parking_sensor.on_loop();
    }
}
