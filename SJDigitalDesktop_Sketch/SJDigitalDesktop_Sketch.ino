/*TODO, Is it possible to have the mic input interrupt driven
as opposed to using a polling loop?*/

#include <StrobeMusic.h>
#include <StrobePattern.h>
#include <TM1638.h>

#define micInput 10
int val = 0;
char buffer[8];
String time = "";

TM1638 module(8, 9, 7);

void setup() {
  Serial.begin(9600);
  pinMode(micInput, INPUT); 
}

void loop() {
  detectBeat();
  displayTime();
  delay(100);
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
  /*TODO: Concatenate each of the buffer characters into a 
  single string to be sent to the display strip*/
  time = buffer[2] + "." + buffer[1] + "." + buffer[0];
  module.setDisplayToString(time);
  
}

void serialEvent() {
  while (Serial.availale()) {
    Serial.readBytes(buffer, 8);
  }
}
