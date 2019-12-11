#include "distance_meter.h"
#include "parking_signal.h"
#include "parking_sensor.h"

#include "wifi.h"
#include "ota.h"

#define ECHO_PIN        D3
#define TRIGGER_PIN     D4

#define RED_LED_PIN     D6
#define GREEN_LED_PIN   D7
#define BLUE_LED_PIN    D8

#define WIFI_SSID   ""
#define WIFI_PASSWD ""

#define HOST_NAME   "parking_sensor.local"

DistanceMeter distance_meter(ECHO_PIN, TRIGGER_PIN);
ParkingSignal parking_signal(RED_LED_PIN, GREEN_LED_PIN, BLUE_LED_PIN);
ParkingSensor parking_sensor(&distance_meter, &parking_signal);

void setup()
{
  Serial.begin(115200);
  connect_to_wifi(WIFI_SSID, WIFI_PASSWD, HOST_NAME);
  ota_setup();
  parking_sensor.begin();
}

void loop()
{
  ota_on_loop();
  parking_sensor.on_loop();
}
