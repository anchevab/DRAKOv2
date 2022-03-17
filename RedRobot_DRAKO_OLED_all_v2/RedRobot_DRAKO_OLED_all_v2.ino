/*
  RedRobot DRAKO OLED 128x64 all v2
  Byala Robots Club
  February, 2019
*/

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL);

extern uint8_t SmallFont[];
extern uint8_t logo[];
extern uint8_t The_End[];
extern uint8_t pacman1[];
extern uint8_t pacman2[];
extern uint8_t pacman3[];
extern uint8_t pill[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

float y;
uint8_t* bm;
int pacy;

#define LED 13
#define PIN 16                  // DIN на пин 16
#define LED_COUNT 1             // брой на светодиодите на шийлда
int redLED, greenLED, blueLED;
// ------------- създаване на обект с име "leds", който е част от класа Adafruit_NeoPixel
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

// ======================== SETUP ==========================
void setup(void) {
  if (!myOLED.begin(SSD1306_128X64))
    while (1);
  myOLED.setFont(SmallFont);
  pinMode(LED, OUTPUT);
  leds.begin();                  // активира светодиодите
  leds.setBrightness(64);        // задава сила на светене на светодиодите в интервала 0-255
  leds.clear();                  // изчиства светодиодите
  leds.show();
}

// ======================== LOOP ==========================
void loop(void) {
  digitalWrite(LED, HIGH);
  redLED = random(0, 255);
  greenLED = random(0, 255);
  blueLED = random(0, 255);
  leds.clear();
  leds.setPixelColor(0, redLED, greenLED, blueLED);
  leds.show();
  runOLED();
  delay(100);
}
// ----------------- OLED functions --------------------------
void runOLED() {
  myOLED.clrScr();
  myOLED.print("DRAKO v2", CENTER, 0);
  myOLED.print("Display DEMO", CENTER, 28);
  myOLED.drawRect(50, 26, 78, 36);
  //------
  for (int i = 0; i < 6; i++)
  {
    myOLED.drawLine(79, 26 + (i * 2), 105 - (i * 3), 26 + (i * 2));
    myOLED.drawLine(22 + (i * 3), 36 - (i * 2), 50, 36 - (i * 2));
  }
  myOLED.print("(C)2018 by", CENTER, 48);
  myOLED.print("Byala Robots Club", CENTER, 56);
  myOLED.update();

  delay(5000);
  // -----
  myOLED.clrScr();
  for (int i = 0; i < 64; i += 2)
  {
    myOLED.drawLine(0, i, 127, 63 - i);
    myOLED.update();
  }
  for (int i = 127; i >= 0; i -= 2)
  {
    myOLED.drawLine(i, 0, 127 - i, 63);
    myOLED.update();
  }

  delay(2000);
  // -----
  myOLED.clrScr();
  myOLED.drawRect(0, 0, 127, 63);
  for (int i = 0; i < 64; i += 4)
  {
    myOLED.drawLine(0, i, i * 2, 63);
    myOLED.update();
  }
  for (int i = 0; i < 64; i += 4)
  {
    myOLED.drawLine(127, 63 - i, 127 - (i * 2), 0);
    myOLED.update();
  }

  delay(2000);
  // ------
  myOLED.clrScr();
  for (int i = 0; i < 10; i++)
  {
    myOLED.drawRoundRect(i * 3, i * 3, 127 - (i * 3), 63 - (i * 3));
    myOLED.update();
  }

  delay(2000);
  // ------
  myOLED.clrScr();
  for (int i = 0; i < 25; i++)
  {
    myOLED.drawCircle(64, 32, i * 3);
    myOLED.update();
  }

  delay(2000);
  // --------
  myOLED.clrScr();
  myOLED.drawRect(0, 0, 127, 63);
  myOLED.drawLine(0, 31, 127, 31);
  myOLED.drawLine(63, 0, 63, 63);
  for (int c = 0; c < 4; c++)
  {
    for (int i = 0; i < 128; i++)
    {
      y = i * 0.04974188368183839294232518690191;
      myOLED.invPixel(i, (sin(y) * 28) + 31);
      myOLED.update();
      delay(10);
    }
  }

  delay(2000);
  // ---------------
  for (int pc = 0; pc < 3; pc++)
  {
    pacy = random(0, 44);

    for (int i = -20; i < 132; i++)
    {
      myOLED.clrScr();
      for (int p = 6; p > ((i + 20) / 20); p--)
        myOLED.drawBitmap(p * 20 - 8, pacy + 7, pill, 5, 5);
      switch (((i + 20) / 3) % 4)
      {
        case 0: bm = pacman1;
          break;
        case 1: bm = pacman2;
          break;
        case 2: bm = pacman3;
          break;
        case 3: bm = pacman2;
          break;
      }
      myOLED.drawBitmap(i, pacy, bm, 20, 20);
      myOLED.update();
      delay(10);
    }
  }

  // ------- numbers
  for (int i = 0; i <= 500; i++)
  {
    myOLED.setFont(MediumNumbers);
    myOLED.printNumF(float(i) / 3, 2, RIGHT, 0);
    myOLED.setFont(BigNumbers);
    myOLED.printNumI(i, RIGHT, 40);
    myOLED.update();
  }

  myOLED.setFont(SmallFont);
  myOLED.print("|", LEFT, 24);
  myOLED.print("|", RIGHT, 24);
  myOLED.update();
  delay(500);
  for (int i = 0; i < 19; i++)
  {
    myOLED.print("\\", 7 + (i * 6), 24);
    myOLED.update();
    delay(250);
  }
  myOLED.clrScr();
  // ----------
  for (int i = 0; i < 41; i++)
  {
    myOLED.clrScr();
    myOLED.drawBitmap(22, i - 24, The_End, 84, 24);
    myOLED.update();
    delay(50);
  }
  myOLED.print("Runtime (ms):", CENTER, 48);
  myOLED.printNumI(millis(), CENTER, 56);
  myOLED.update();
  for (int i = 0; i < 5; i++)
  {
    myOLED.invert(true);
    delay(1000);
    myOLED.invert(false);
    delay(1000);
  }
}

