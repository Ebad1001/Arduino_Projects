// include the Neopixel library
#include <Adafruit_NeoPixel.h>

// define constants
const int led_count = 20;      // number of neopixels
const int max_intensity = 100; // max R/G/B value for pixels

// define the component pins
int neopixel_pin = 9; // connect the data pin of neopixels at pin 9
                      // connect the GND pin of neopixels at GND
                      // connect the 5V pin of neopixels at 5V

// create a Neopixel object
Adafruit_NeoPixel strip(led_count, neopixel_pin, NEO_GRB + NEO_KHZ800);

void setup()
{
  // initialize the neopixels with #000
  strip.begin();
  strip.setBrightness(60);
  for (int i = 0; i < led_count; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
  }

  // initialize the serial port
  Serial.begin(9600);
}

void loop()
{
  // generate a random color for a random pixel
  int r_val = random(0, max_intensity);
  int g_val = random(0, max_intensity);
  int b_val = random(0, max_intensity);
  int index = random(0, led_count);

  // display the color on the pixel
  strip.setPixelColor(index, strip.Color(r_val, g_val, b_val));
  strip.show();

  // delay for smooth performance
  delay(10);
}