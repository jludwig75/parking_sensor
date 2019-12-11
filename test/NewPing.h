#pragma once

#include <stdint.h>


	#define MAX_SENSOR_DISTANCE 500 // Maximum sensor distance can be as high as 500cm, no reason to wait for ping longer than sound takes to travel this distance and back. Default=500


class NewPing
{
public:
    NewPing(uint8_t trigger_pin, uint8_t echo_pin, unsigned int max_cm_distance = MAX_SENSOR_DISTANCE);
    unsigned long ping_median(uint8_t it = 5, unsigned int max_cm_distance = 0);
    static unsigned int convert_cm(unsigned int echoTime);
};