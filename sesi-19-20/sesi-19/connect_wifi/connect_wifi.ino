#include <WiFi.h>
#include <time.h>
struct tm timeinfo;
unsigned long Epoch_Time; 

const char* ssid = "albus";
const char* password = "test123455";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected to WiFi");

    configTime(7 * 3600, 0, "pool.ntp.org"); // Set up time sync via NTP

}

void loop() {
  time_t now; // Get current time
  Epoch_Time =  time(&now);
  Serial.println(Epoch_Time); // Print current time in human-readable format
  delay(1000); // Wait for one second
  }