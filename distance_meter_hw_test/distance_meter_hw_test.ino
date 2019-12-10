#include "distance_meter.h"
#include "wifi.h"
#include "ota.h"

#define ECHO_PIN        1
#define TRIGGER_PIN     2

#define WIFI_SSID   ""
#define WIFI_PASSWD ""

#define HOST_NAME   "parking_sensor.local"

#define DISTANCE_CHECK_INTERVAL_MS  300

DistanceMeter distance_meter(ECHO_PIN, TRIGGER_PIN);

void setup()
{
  Serial.begin(115200);
  connect_to_wifi(WIFI_SSID, WIFI_PASSWD, HOST_NAME);
  ota_setup();
  distance_meter.begin();
}

unsigned long last_check_time = 0;

void loop()
{
  ota_on_loop();
  if (millis() - last_check_time >= DISTANCE_CHECK_INTERVAL_MS)
  {
    last_check_time = millis();
    Serial.print("Current distance: ");
    Serial.print(distance_meter.get_distance());
    Serial.println(" cm");
  }
}
