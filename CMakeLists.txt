cmake_minimum_required(VERSION 3.5)

# set the project name
project(parking_sensor LANGUAGES CXX VERSION 2.11.0)

# add the executable
add_executable(parking_signal_test
                parking_signal_test.cpp
                parking_signal.cpp
                test_led.cpp
                led_bank.cpp
                )

target_include_directories(parking_signal_test PUBLIC
                           "${PROJECT_SOURCE_DIR}/Catch2/single_include/catch2"
                           )
