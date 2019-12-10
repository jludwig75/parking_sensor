#pragma once


#include <stdint.h>


class HCSR04
{
public:
    HCSR04(uint8_t trigger_pin, uint8_t echo_pin, int16_t temperature = 20, uint16_t maxDistance = 300);
    void begin(void);
    float getMedianFilterDistance() const;
};