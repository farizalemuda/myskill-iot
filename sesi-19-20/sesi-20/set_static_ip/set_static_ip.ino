#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "albus";
const char* password = "test123455";

// Replace with your static IP address configuration

IPAddress staticIP(192, 168, 192, 50);
IPAddress gateway(192,168,192,32);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "hello from esp32!");
}
void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network with dynamic IP
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Configure static IP address
  Serial.println("Configuring static IP address...");
  if (!WiFi.config(staticIP, gateway, subnet)) {
    Serial.println("Failed to configure static IP address.");
  }

  Serial.println("Connected to Wi-Fi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.begin();

}

void loop() {
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks
}
