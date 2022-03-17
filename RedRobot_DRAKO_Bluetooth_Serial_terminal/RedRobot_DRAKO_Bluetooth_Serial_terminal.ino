#include <SoftwareSerial.h>

SoftwareSerial SoftSerial(3, 2);

char serialpr;
char BLT123;

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);

}

void loop() {
  if (SoftSerial.available()) {
    serialpr = (char)(SoftSerial.read());
    Serial.print(serialpr);

  }
  if (Serial.available()) {
    BLT123 = (char)(Serial.read());
    SoftSerial.write(BLT123);

  }

}
