#include <StrobeMusic.h>
#include <StrobePattern.h>
#include <TM1638.h>

#define micInput 10
int val = 0;
char buffer[8];

TM1638 module(8, 9, 7);

void setup() {
  Serial.begin(9600);
  pinMode(micInput, INPUT); 
}

void loop() {
  //detectBeat();
  getTime();
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

void getTime() {
  if (Serial.available() > 0) {
    digitalWrite(13, HIGH);
    Serial.readBytes(buffer, 8);
  }
}

void displayTime() {
  /*TODO: Concatenate each of the buffer characters into a 
  single string to be sent to the display strip*/
  
}
