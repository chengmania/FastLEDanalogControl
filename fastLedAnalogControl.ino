//Freckledscience on a Saturday Morning
//UNO 5v  --->  Ring 5V
//UNO GND  -->  Ring GND
//UNO Pin 3 ->  Ring DI
//POT1
//  1 - GND
//  2 - A0
//  3 - 5V
//POT2
//  1 - GND
//  2 - A1
//  3 - 5V
//POT3
//  1 - GND
//  2 - A2
//  3 - 5V
//POT4
//  1 - GND
//  2 - A4
//  3 - 5V


#include <FastLED.h>

///////////////////////////////////////////////////////////////////////////////////////////
//
// Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
// and then how to turn a single pixel white and then off, moving down the line of pixels.
//
#define DATA_PIN 3

// How many leds are in the strip?
#define NUM_LEDS 8
int BRIGHTNESS = 20;

#define POT1 A0
#define POT2 A1
#define POT3 A2
#define POT4 A3

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// This function sets up the ledsand tells the controller about them
void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);

  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() {
  // Read all the analog inputs for potatometers
    int readBright = analogRead(POT1);
    readBright = map(readBright, 0, 1023, 0, 255);

    int RColor = analogRead(POT2);
    RColor = map(RColor, 0, 1023, 0, 255);

    int RBlue = analogRead(POT3);
    RBlue = map(RBlue, 0, 1023, 0, 255);

    int RGreen = analogRead(POT4);
    RGreen = map(RGreen, 0, 1023, 0, 255);

  //Display potatometer RGB Colors 

  for (int CLeds= 0; CLeds < NUM_LEDS; CLeds++) {
    // Turn our current led on to white, then show the leds
    leds[CLeds] = CRGB(RColor,RGreen,RBlue);
    
  }
  FastLED.setBrightness(readBright);
  FastLED.show();
  
}
