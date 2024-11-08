#include <Adafruit_NeoPixel.h>
 
#define PIN 15
 
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
  pixels.begin(); // This initializes the NeoPixel library.
}
 
void loop()
{
  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        pixels.setPixelColor(0, pixels.Color(i * 255, j * 255, k * 255)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(2000); // Delay for a period of time (in milliseconds).
      }
    }
  }
}
