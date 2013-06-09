/*TODO, Is it possible to have the mic input interrupt driven
as opposed to using a polling loop?*/

#include <StrobeMusic.h>
#include <StrobePattern.h>
#include <TM1638.h>

#define micInput 10
int val = 0;
char buffer[8];
byte lookupTable[11] = {63, 6, 91, 79, 226, 109, 125, 7, 127, 111, 128};
byte outputBuffer[8];
String time;

TM1638 module(8, 9, 7);

void setup() {
  Serial.begin(9600);
  pinMode(micInput, INPUT); 
}

void loop() {
  detectBeat();
}

void detectBeat() {
  if (digitalRead(micInput) == HIGH) {
    val = analogRead(A0);
    if (val < 150) {
      module.setLEDs(veryHighVolume);
    } else if ((val > 200) && (val < 300)) {
      module.setLEDs(highVolume);
    } else if ((val > 300) && (val < 400)) {
      module.setLEDs(midVolume);
    } else if ((val > 400) && (val < 500)) {
      module.setLEDs(lowVolume);
    } else if ((val > 500) && (val < 600)) {
     module.setLEDs(0); 
    }
  } 
}

void displayTime() {
  /*TODO: Need to divide up the time components so that they have each have
  a segment on the screen. I'll use my fouth year project display sorting
  algorithm*/
}

void serialEvent() {
  if (Serial.available()) {
    Serial.readBytes(buffer, 8);
  }
}
