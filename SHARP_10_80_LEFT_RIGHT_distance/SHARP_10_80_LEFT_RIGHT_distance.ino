#include<SharpDist.h>

SharpDist distRIGHT (A3, 10);
SharpDist distLEFT (A7, 10);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float distanceRIGHT = distRIGHT.distanceCentimeters();
  float distanceLEFT = distLEFT.distanceCentimeters();
  Serial.print("Distance RIGHT: ");
  Serial.print(distanceRIGHT);
  Serial.print("\t");
  Serial.print("Distance LEFT: ");
  Serial.println(distanceLEFT);
}
