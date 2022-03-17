/*
  AnalogReadSerial
  Byala Robots Club
  january, 2019
*/


void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A6);
  Serial.println(sensorValue);
  delay(10);
}
