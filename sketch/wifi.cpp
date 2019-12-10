#include "wifi.h"

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266mDNS.h>

void connect_to_wifi(const char *ssid, const char *passwd, const char *host_name)
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, passwd);
  Serial.println("");
  
  // Wait for connection
/*  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }*/
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  if (MDNS.begin(host_name)) {
    Serial.println("MDNS responder started");
  }
}
