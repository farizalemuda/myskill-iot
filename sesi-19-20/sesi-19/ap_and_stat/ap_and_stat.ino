#include <WiFi.h>

const char* ssid = "albus"; // Set the Wi-Fi Station name
const char* password = "test123455"; // Set the Wi-Fi Station password

const char* apSsid = "MyESP32AP"; // Set the Access Point name
const char* apPassword = "password123"; // Set the Access Point password

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Set WiFi mode to both Access Point and Station
  WiFi.mode(WIFI_AP_STA);

  // Connect to Wi-Fi Station
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wi-Fi Station connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start Access Point
  WiFi.softAP(apSsid, apPassword);
  Serial.println("Access Point started");
  Serial.print("SSID: ");
  Serial.println(apSsid);
  Serial.print("Password: ");
  Serial.println(apPassword);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Do nothing in the loop
}
