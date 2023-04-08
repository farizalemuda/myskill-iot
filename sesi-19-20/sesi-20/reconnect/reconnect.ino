#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "albus";
const char* password = "test123455";

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to Wi-Fi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your code here

  // Check if we lost connection to Wi-Fi network
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Lost connection to Wi-Fi network! Reconnecting...");
    WiFi.reconnect();

    // Wait for reconnection to complete
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
    }

    Serial.println("Reconnected to Wi-Fi network!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }

  // Add delay to avoid flooding the network with reconnect requests
  delay(1000);
}
