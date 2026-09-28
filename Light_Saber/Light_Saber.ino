// include the Neopixel library
#include <Adafruit_NeoPixel.h>

// define constants & state variables
const int led_count = 40; // number of neopixels
int color = 0;            // 0 = red, 1 = green, 2 = blue

// define the component pins
int neopixel_pin = 9; // connect the data pin of neopixels at pin 9
                      // connect the GND pin of neopixels at GND
                      // connect the 5V pin of neopixels at 5V
int tilt_sensor = 7;  // connect the DO pin of tilt sensor at pin 6
                      // connect the GND pin of tilt sensor at GND
                      // connect the VCC pin of tilt sensor at 5V

// create a Neopixel object
Adafruit_NeoPixel strip(led_count, neopixel_pin, NEO_GRB + NEO_KHZ800);

void setup()
{
  // set the pin modes
  pinMode(tilt_sensor, INPUT);

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
  // take reading from tilt sensor
  int reading = digitalRead(tilt_sensor);
  Serial.println(reading);

  if (reading == HIGH)
  {
    // if a shake is detected

    if (color == 0)
    { // red
      for (int i = 0; i < led_count; i++)
      {
        strip.setPixelColor(i, strip.Color(255, 0, 0));
        strip.show();
        delay(10);
      }
      color = 1;
    }
    else if (color == 1)
    { // green
      for (int i = 0; i < led_count; i++)
      {
        strip.setPixelColor(i, strip.Color(0, 255, 0));
        strip.show();
        delay(10);
      }
      color = 2;
    }
    else if (color == 2)
    { // blue
      for (int i = 0; i < led_count; i++)
      {
        strip.setPixelColor(i, strip.Color(0, 0, 255));
        strip.show();
        delay(10);
      }
      color = 0;
    }
  }
  // delay for smooth performance
  delay(100);
}