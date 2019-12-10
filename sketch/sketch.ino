#include "distance_meter.h"
#include "parking_signal.h"
#include "parking_sensor.h"

#define ECHO_PIN        1
#define TRIGGER_PIN     2

#define RED_LED_PIN     3
#define GREEN_LED_PIN   4
#define BLUE_LED_PIN    5

DistanceMeter distance_meter(ECHO_PIN, TRIGGER_PIN);
ParkingSignal parking_signal(RED_LED_PIN, GREEN_LED_PIN, BLUE_LED_PIN);
ParkingSensor parking_sensor(&distance_meter, &parking_signal);

void setup()
{

}

void loop()
{
    parking_sensor.on_loop();
}