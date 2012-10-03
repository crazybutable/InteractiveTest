//=========================================================================
//
// InteractiveTest -- An interactive test of the Adafruit 12mm pixel strip
// by John Wilson (@crazybutable, http://www.crazybutable.com/)
// uses a helper function and a few lines of code from strandTest, the
// default Adafruit pixel strand test code.
//
//=========================================================================

#include "SPI.h"
#include "Adafruit_WS2801.h"

// This code is only going to work with the 12mm pixel strands. If you
// have other pixel strands, look at the Adafruit strandTest code 
// for ideas on what you will need to change.

// Choose which 2 pins you will use for output.
// Can be any valid output pins.
// The colors of the wires may be totally different so
// BE SURE TO CHECK YOUR PIXELS TO SEE WHICH WIRES TO USE!

const int dataPin  = 2;    // Yellow wire on Adafruit Pixels
const int clockPin = 3;    // Green wire on Adafruit Pixels

// Don't forget to connect the ground wire to Arduino ground,
// and the +5V wire to a +5V supply

// Set the first variable to the NUMBER of pixels in your strip.

const int numberOfPixels = 25;
const int inputPin = A0;

Adafruit_WS2801 strip = Adafruit_WS2801(numberOfPixels, dataPin, clockPin);

// These are our background and foreground colors.

uint32_t backgroundColor = Color(0, 255, 255);
uint32_t movingPixelColor = Color(255, 0, 0);

void setup() {

  strip.begin();
  pinMode(inputPin, INPUT);

}

void loop() {

  int input = analogRead(inputPin);

  for(int i = 0; i < numberOfPixels; i++)
  {
    strip.setPixelColor(i, backgroundColor);
  }

  strip.setPixelColor(map(input, 0, 1023, 0, numberOfPixels-1), movingPixelColor);

  strip.show();
}

/* Helper function */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}


