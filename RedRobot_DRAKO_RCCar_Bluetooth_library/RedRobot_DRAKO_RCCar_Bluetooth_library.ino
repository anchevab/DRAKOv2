/*
   EMX robot RC Bluetooth Car
   Byala Robots Club
   Author eng.Anton Anchev
   Byala, january 2018
*/

#include <SoftwareSerial.h>
#include <DRV8833.h>

// ----- motors
DRV8833 driver = DRV8833();
const int inputA1 = 11, inputA2 = 5;
const int inputB1 = 9, inputB2 = 10;

// ---- bluetooth
int bluetoothTx = 3;
int bluetoothRx = 2;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

int speed;
#define LED 13

// ==================== SETUP ===============
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  while (!Serial);
  // -- Attach a motor
  driver.attachMotorA(inputA1, inputA2);           // RIGHT motor
  driver.attachMotorB(inputB1, inputB2);           // LEFT motor
  pinMode(LED, OUTPUT);
  //  Serial.println("Ready!");
}

// =================== LOOP ================
void loop() {

  char inp_char;
  if (bluetooth.available() > 0)
  {
    inp_char = bluetooth.read();
    //  Serial.println(inp_char);
    switch (inp_char)
    {
      case  '0':                                                 // speed 0
        speed = 0;
        delay(30);
        break;
      case  '1':
        speed = 140;
        delay(30);
        break;
      case  '2':
        speed = 160;
        delay(30);
        break;
      case  '3':
        speed = 180;
        delay(30);
        break;
      case  '4':
        speed = 200;
        delay(30);
        break;
      case  '5':
        speed = 210;
        delay(30);
        break;
      case  '6':
        speed = 220;
        delay(30);
        break;
      case  '7':
        speed = 230;
        delay(30);
        break;
      case  '8':
        speed = 240;
        delay(30);
        break;
      case  '9':
        speed = 245;
        delay(30);
        break;
      case  'q':                                                 // max speed
        speed = 250;
        delay(30);
        break;
      case  'W':                                                 // turn LIGHT ON
        digitalWrite(LED, HIGH);
        delay(30);
        break;
      case  'w':                                                 // turn LIGHT OFF
        digitalWrite(LED, LOW);
        delay(30);
        break;
    }
    //--------------------------- FORWARD -----------------------------
    if (inp_char == 'F') {
      //      Serial.println("Forward:");
      driver.motorAForward(speed);
      driver.motorBForward(speed);
    }
    //------------------------ FORWARD-LEFT ---------------------------
    if (inp_char == 'G') {
      //      Serial.println("Forward-Left:");
      driver.motorAForward(speed * 0.70);
      driver.motorBForward(speed);
    }
    //------------------------- FORWARD-RIGHT -------------------------
    if (inp_char == 'I') {
      //      Serial.println("Forward-Right:");
      driver.motorAForward(speed);
      driver.motorBForward(speed * 0.70);
    }
    // -------------------------------------------- BACKWARD ------------------------------------------
    if (inp_char == 'B') {
      //      Serial.println("Reverse:");
      driver.motorAReverse(speed);
      driver.motorBReverse(speed);
    }
    // -------------------------------------------- BACKWARD-LEFT ------------------------------------------
    if (inp_char == 'H') {
      //      Serial.println("Reverse-Left:");
      driver.motorAReverse(speed * 0.70);
      driver.motorBReverse(speed);
    }
    // -------------------------------------------- BACKWARD-RIGHT ------------------------------------------
    if (inp_char == 'J') {
      //      Serial.println("Reverse-Right:");
      driver.motorAReverse(speed);
      driver.motorBReverse(speed * 0.70);
    }
    // ------------------------------------------- TURN RIGHT ------------------------------------------
    if (inp_char == 'R') {
      //      Serial.println("Right:");
      driver.motorAForward(speed);
      driver.motorBForward(speed * 0.40);
    }
    // ------------------------------------------- TURN LEFT --------------------------------------------
    if (inp_char == 'L') {
      //      Serial.println("Left:");
      driver.motorAForward(speed * 0.40);
      driver.motorBForward(speed);
    }
    // ------------------------------------------ STOP ----------------------------------------------------
    if ((inp_char == 'S') ) {
      //      Serial.println("Stop:");
      driver.motorAStop();
      driver.motorBStop();
    }
  }
}
