#include <WiFi.h>

// Replace with your network credentials (STATION)
const char* ssid = "albus";
const char* password = "test123455";

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  
}

void loop() {
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
}