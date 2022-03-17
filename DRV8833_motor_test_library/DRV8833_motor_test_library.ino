/*
   DRV8833_Test RedRobor DRAKO
   Byala Robots Club
   Author eng.Anton Anchev
   Byala, february 2019
*/

#include <DRV8833.h>
// ------ Create an instance of the DRV8833:
DRV8833 driver = DRV8833();

const int inputA1 = 11, inputA2 = 5;
const int inputB1 = 9, inputB2 = 10;
int speed = 200;                         // from 140 to 255
//===================== SETUP ================
void setup() {
  Serial.begin(9600);
  while (!Serial);
  driver.attachMotorA(inputA1, inputA2);
  driver.attachMotorB(inputB1, inputB2);
  Serial.println("Ready!");
}

// =================== LOOP ==================
void loop() {

  // ------------- FORWARD -------------
  Serial.println("Forward:");
  driver.motorAForward(speed);
  driver.motorBForward(speed);
  delay(2000);

  // ------------ STOP ----------------
  Serial.println("Stop:");
  driver.motorAStop();
  driver.motorBStop();
  delay(100);

  // ------------ BACKWARD --------------
  Serial.println("Reverse:");
  driver.motorAReverse(speed);
  driver.motorBReverse(speed);
  delay(2000);
  // ------------ STOP ----------------
  Serial.println("Stop:");
  driver.motorAStop();
  driver.motorBStop();
  delay(100);

  // ------------ TURN RIGHT ------------
  Serial.println("<<<<<<<< Right:");
  driver.motorAForward(speed);                 // speed 140-255
  driver.motorBReverse(speed);

  delay(2000);
  // ------------ STOP ----------------
  Serial.println("Stop:");
  driver.motorAStop();
  driver.motorBStop();
  delay(50);
  // ----------- TURN LEFT ----------
  Serial.println("Left >>>>>>>>>>:");
  driver.motorAReverse(speed);
  driver.motorBForward(speed);
  delay(2000);
  Serial.println("Stop:");
  // ----------- Stop the motor:
  driver.motorAStop();
  driver.motorBStop();
  delay(100);

}
