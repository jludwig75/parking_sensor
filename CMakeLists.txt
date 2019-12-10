cmake_minimum_required(VERSION 3.5)

# set the project name
project(parking_sensor LANGUAGES CXX VERSION 2.11.0)

# ParkingSensor Integration Test
add_executable(parking_sensor_integration_test
                parking_sensor_integration_test.cpp

                parking_sensor.cpp
                range_guide.cpp
                parking_signal.cpp

                test_led.cpp
                led_bank.cpp
                test_distance_meter.cpp
                distance_meter.cpp
                )
target_include_directories(parking_sensor_integration_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )

# ParkingSensor Unit Test
add_executable(parking_sensor_test
                parking_sensor_test.cpp
                parking_sensor.cpp
                test_parking_signal.cpp
                parking_signal.cpp
                test_led.cpp
                led_bank.cpp
                test_distance_meter.cpp
                distance_meter.cpp
                test_range_guide.cpp
                )
target_include_directories(parking_sensor_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )

# ParkingSignal Unit Test
add_executable(parking_signal_test
                parking_signal_test.cpp
                parking_signal.cpp
                test_led.cpp
                led_bank.cpp
                )
target_include_directories(parking_signal_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )

# RangeGuide Unit Test
add_executable(range_guide_test
                range_guide_test.cpp
                range_guide.cpp
                test_parking_signal.cpp
                parking_signal.cpp
                test_led.cpp
                led_bank.cpp
                )
target_include_directories(range_guide_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )

# RangeGuide and ParkingSignal Integration Test
add_executable(range_guide_parking_signal_test
                range_guide_parking_signal_test.cpp
                range_guide.cpp
                parking_signal.cpp
                test_led.cpp
                led_bank.cpp
                )
target_include_directories(range_guide_parking_signal_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )
