#include "distance_meter.h"
#include "parking_signal.h"
#include "parking_sensor.h"

#include "wifi.h"
#include "ota.h"

#define ECHO_PIN        1
#define TRIGGER_PIN     2

#define RED_LED_PIN     3
#define GREEN_LED_PIN   4
#define BLUE_LED_PIN    5

#define WIFI_SSID   ""
#define WIFI_PASSWD ""

#define HOST_NAME   "parking_sensor.local"

DistanceMeter distance_meter(ECHO_PIN, TRIGGER_PIN);
ParkingSignal parking_signal(RED_LED_PIN, GREEN_LED_PIN, BLUE_LED_PIN);
ParkingSensor parking_sensor(&distance_meter, &parking_signal);

void setup()
{
  connect_to_wifi(WIFI_SSID, WIFI_PASSWD, HOST_NAME);
  ota_setup();
}

void loop()
{
  ota_on_loop();
  parking_sensor.on_loop();
}
