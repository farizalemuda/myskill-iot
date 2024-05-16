// RGB and R, G, B LED demo

const int pinR = 3;
const int pinG = 5;
const int pinB = 6;

const int potR = A0;
const int potG = A1;
const int potB = A2;

void setup() {
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(potR, INPUT);
  pinMode(potG, INPUT);
  pinMode(potB, INPUT);
}

int readPot(int pin) {
  return map(analogRead(pin), 0, 1023, 0, 255);
}

void loop() {
  analogWrite(pinR, readPot(potR));
  analogWrite(pinG, readPot(potG));
  analogWrite(pinB, readPot(potB));
}
