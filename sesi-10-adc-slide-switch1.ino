const int pinSensor = A0;
int adcValue = 0;

void setup()
{
  // inisiasi Serial comm dengan baud rate 115200
  Serial.begin(115200);
  pinMode(pinSensor, INPUT);
}
 
void loop()
{
  // akuisisi nilai ADC sensor LDR
  adcValue = analogRead(pinSensor);

  // cetak nilai adc ke serial monitor
  Serial.print("nilai adc: ");
  Serial.println(adcValue); 
  // jeda akuisisi data
  delay(1000); 
}
