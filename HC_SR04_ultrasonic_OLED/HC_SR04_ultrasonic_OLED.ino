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
#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL);

#define TRIG 7
#define ECHO 8
Ultrasonic ultrasonic(TRIG, ECHO);

extern uint8_t BigNumbers[];

// ============ SETUP ===================
void setup() {
  Serial.begin(9600);
  if (!myOLED.begin(SSD1306_128X64))
    while (1);
}

// ============ LOOP ===================
void loop() {
  myOLED.clrScr();
  int distance = ultrasonic.distanceRead();
  //  Serial.println(distance);
  myOLED.setFont(BigNumbers);
  myOLED.printNumI(distance, CENTER, 20);
  myOLED.update();
  delay(50);
}
