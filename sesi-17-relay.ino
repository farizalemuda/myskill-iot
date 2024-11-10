#define pinRelay 15

void setup() {
  // put your setup code here, to run once:
  pinMode(pinRelay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinRelay, LOW);
  delay(2000);
  digitalWrite(pinRelay, HIGH);
  delay(2000);
}
