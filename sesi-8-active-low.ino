const int LED = 32;

void setup() {
// put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Studi Independen IoT");
  pinMode(LED, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Logic HIGH");
  digitalWrite(LED, HIGH);
  delay(1000);
  Serial.println("Logic LOW");
  digitalWrite(LED, LOW);
  delay(1000);
}
