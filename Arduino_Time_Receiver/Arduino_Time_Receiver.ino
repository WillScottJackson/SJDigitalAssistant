byte inputByte0 = 0;
byte inputByte1 = 0;
byte inputByte2 = 0;
byte inputByte3 = 0;
byte inputByte4 = 0;
byte inputByte5 = 0;
byte inputByte6 = 0;
byte inputByte7 = 0;
char buffer[8];

void setup() {
 Serial.begin(9600); 
}

void loop() {
  getTime();
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}

void getTime() {
 if (Serial.available() > 0) {
   digitalWrite(13, HIGH);
    Serial.readBytes(buffer, 8);
    Serial.print(buffer[0]);
  }
}
