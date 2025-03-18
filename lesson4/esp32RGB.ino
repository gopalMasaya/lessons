
#include <stdbool.h>
#define RGB_PIN 48  // Change this to the correct GPIO for your board
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 1  // Number of LEDs in the onboard RGB
Adafruit_NeoPixel pixels(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

int red = 0;
int green = 0;
int blue = 0;

void setup() {
  pixels.begin(); // Initialize NeoPixel library
}

void loop() {
  for(int i = 0;i< 255;i++){
  pixels.setPixelColor(0, pixels.Color(i, 0, 0)); // Red
  pixels.show();
  delay(20);
  }
  delay(1000);
 for(int i = 0;i< 255;i++){
  pixels.setPixelColor(0, pixels.Color(0, i, 0)); // Green
  pixels.show();
  delay(20);
 }
  delay(1000);

 for(int i = 0;i< 255;i++){
  pixels.setPixelColor(0, pixels.Color(0, 0, i)); // Blue
  pixels.show();
  delay(20);
 }
  delay(1000);

  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // Off
  pixels.show();
  delay(1000);
}
