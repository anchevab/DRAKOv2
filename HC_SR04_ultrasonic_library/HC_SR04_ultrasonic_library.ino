/*
    RedRobot DRAKO with HC-SR04 ultrasonic
    Byala Robots Club
    february 2019

    ---------------------    ---------------------
   | HC-SR04 | Arduino |    | 3 pins  | Arduino |
   ---------------------    ---------------------
   |   Vcc   |   5V    |    |   Vcc   |   5V    |
   |   Trig  |   7     | OR |   SIG   |   13    |
   |   Echo  |   8     |    |   Gnd   |   GND   |
   |   Gnd   |   GND   |    ---------------------
   ---------------------
*/
#include <Ultrasonic.h>
#define TRIG 7
#define ECHO 8
Ultrasonic ultrasonic(TRIG, ECHO);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = ultrasonic.distanceRead();
  Serial.println(distance);
  delay(30);
}
