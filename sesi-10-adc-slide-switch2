const int pinSensor = A0;
int adcValue = 0;
double volt = 0;

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
  volt = adcValue * 3.3 / 4095;
  // cetak nilai adc ke serial monitor
  Serial.print("nilai volt: ");
  Serial.println(volt); 
  // jeda akuisisi data
  delay(1000); 
}
