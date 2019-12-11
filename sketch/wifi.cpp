#include "wifi.h"

#if 1
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266mDNS.h>
#endif

void connect_to_wifi(const char *ssid, const char *passwd, const char *host_name)
{
#if 1
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

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin(host_name)) {
    Serial.println("MDNS responder started");
  }
#endif
}
