#include <WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() { //perintah koneksi wifi
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA); //setting wifi chip sebagai station/client
  WiFi.begin(ssid, password); //koneksi ke jaringan wifi

  while (WiFi.status() != WL_CONNECTED) { //perintah tunggu esp32 sampi terkoneksi ke wifi
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) { //perintah untuk menampilkan data ketika esp32 di setting sebagai subscriber
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) { //mengecek jumlah data yang ada di topik mqtt
    Serial.print((char)payload[i]);
  }
  Serial.println();
 
  if(String(topic) == "/myskill/p/mqtt/ledmerah"){
    Serial.println("dapet");
    if ((char)payload[0] == '0') {
      digitalWrite(4, LOW);   // Turn the LED on (Note that LOW is the voltage level  
    } 
    if((char)payload[0] == '1'){
      digitalWrite(4, HIGH);  // Turn the LED off by making the voltage HIGH
    }
  }

  if(String(topic) == "/myskill/p/mqtt/ledbiru"){
    if ((char)payload[0] == '0') {
      digitalWrite(19, LOW);   // Turn the LED on (Note that LOW is the voltage level  
    } 
    if((char)payload[0] == '1'){
      digitalWrite(19, HIGH);  // Turn the LED off by making the voltage HIGH
    }
  }

}

void reconnect() { //perintah koneksi esp32 ke mqtt broker baik itu sebagai publusher atau subscriber
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // perintah membuat client id agar mqtt broker mengenali board yang kita gunakan
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      client.subscribe("/myskill/p/mqtt/ledmerah"); //perintah subscribe data ke mqtt broker
      client.subscribe("/myskill/p/mqtt/ledbiru");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(4, OUTPUT);     // inisialisasi pin 2 / ledbuiltin sebagai output
  pinMode(19, OUTPUT);     // inisialisasi pin 2 / ledbuiltin sebagai output
  
  Serial.begin(115200);
  setup_wifi(); //memanggil void setup_wifi untuk dieksekusi
  client.setServer(mqtt_server, 1883); //perintah connecting / koneksi awal ke broker
  client.setCallback(callback); //perintah menghubungkan ke mqtt broker untuk subscribe data
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

