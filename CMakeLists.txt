cmake_minimum_required(VERSION 3.5)

# set the project name
project(parking_sensor LANGUAGES CXX VERSION 2.11.0)

enable_testing()

# ParkingSensor Integration Test
add_executable(parking_sensor_integration_test
                test/parking_sensor_integration_test.cpp

                sketch/parking_sensor.cpp
                sketch/range_guide.cpp
                sketch/parking_signal.cpp

                test/test_led.cpp
                test/led_bank.cpp
                test/test_distance_meter.cpp
                sketch/distance_meter.cpp
                test/HCSR04.cpp
                )
target_include_directories(parking_sensor_integration_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/sketch"
                           "${PROJECT_SOURCE_DIR}/test"
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )
add_test(NAME parking_sensor_integration_test COMMAND parking_sensor_integration_test)


# ParkingSensor Unit Test
add_executable(parking_sensor_test
                test/parking_sensor_test.cpp
                
                sketch/parking_sensor.cpp
                sketch/parking_signal.cpp

                test/test_parking_signal.cpp
                test/test_led.cpp
                test/led_bank.cpp
                test/test_distance_meter.cpp
                sketch/distance_meter.cpp
                test/test_range_guide.cpp
                test/HCSR04.cpp
                )
target_include_directories(parking_sensor_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/sketch"
                           "${PROJECT_SOURCE_DIR}/test"
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )
add_test(NAME parking_sensor_test COMMAND parking_sensor_test)

# ParkingSignal Unit Test
add_executable(parking_signal_test
                test/parking_signal_test.cpp

                sketch/parking_signal.cpp

                test/test_led.cpp
                test/led_bank.cpp
                )
target_include_directories(parking_signal_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/sketch"
                           "${PROJECT_SOURCE_DIR}/test"
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )
add_test(NAME parking_signal_test COMMAND parking_signal_test)

# RangeGuide Unit Test
add_executable(range_guide_test
                test/range_guide_test.cpp

                sketch/range_guide.cpp

                test/test_parking_signal.cpp
                sketch/parking_signal.cpp
                test/test_led.cpp
                test/led_bank.cpp
                )
target_include_directories(range_guide_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/sketch"
                           "${PROJECT_SOURCE_DIR}/test"
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )
add_test(NAME range_guide_test COMMAND range_guide_test)

# RangeGuide and ParkingSignal Integration Test
add_executable(range_guide_parking_signal_test
                test/range_guide_parking_signal_test.cpp

                sketch/range_guide.cpp
                sketch/parking_signal.cpp

                test/test_led.cpp
                test/led_bank.cpp
                )
target_include_directories(range_guide_parking_signal_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/sketch"
                           "${PROJECT_SOURCE_DIR}/test"
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )
add_test(NAME range_guide_parking_signal_test COMMAND range_guide_parking_signal_test)
