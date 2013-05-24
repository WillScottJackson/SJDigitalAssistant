#include <StrobeMusic.h>
#include <StrobePattern.h>
#include <TM1638.h>

#define micInput 10
int val = 0;

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
    Serial.print("Beat Detected: ");
    Serial.println(val, DEC);
    for (int i = 0; i < 9; i++) {
      module.setLEDs(strobeMusic[i]);
      delay(35);
    } 
  } 
}
