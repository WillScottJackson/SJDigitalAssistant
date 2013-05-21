#include <StrobePattern.h>
#include <TM1638.h>


TM1638 module(8, 9, 7);

void setup() {
 Serial.begin(9600); 
}

void loop() {
 for (int i = 0; i < 72; i++) {
  module.setLEDs(strobePattern[i]);
  delay(100);
 } 
}
