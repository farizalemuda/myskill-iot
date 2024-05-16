int led=32;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
  
  int i;
   for(i=0;i<255;++i)
   {
    analogWrite(led,i);
    Serial.println(i);
    delay(50);  // delay 2 milli sec in between reads for stability
   }
}
