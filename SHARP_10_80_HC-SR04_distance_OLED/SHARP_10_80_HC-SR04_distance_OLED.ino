#include <OLED_I2C.h>
#include<SharpDist.h>
#include <Ultrasonic.h>
#include <Adafruit_NeoPixel.h>

#define TRIG 7
#define ECHO 8
#define PIN 16                  // DIN на пин 16
#define LED_COUNT 1
#define LED 13

OLED  myOLED(SDA, SCL);
SharpDist distRIGHT (A3, 10);
SharpDist distLEFT (A7, 10);
Ultrasonic ultrasonic(TRIG, ECHO);
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];



void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  myOLED.begin(SSD1306_128X64);
  myOLED.setFont(MediumNumbers);
  leds.begin();                  // активира светодиодите
  leds.setBrightness(68);        // задава сила на светене на светодиодите в интервала 0-255
  leds.clear();                  // изчиства светодиодите
  leds.setPixelColor(0, 255, 0, 125);
  leds.show();
}
// ============== SETUP ===========
void loop() {
  digitalWrite(LED, HIGH);
  float distanceRIGHT = distRIGHT.distanceCentimeters();             // distance in mm
  float distanceLEFT = distLEFT.distanceCentimeters();               // distance in mm
  int distance = ultrasonic.distanceRead() * 10;                     // distance in mm
  //  Serial.print("Distance RIGHT: ");
  //  Serial.print(distanceRIGHT);
  //  Serial.print("\t");
  //  Serial.print("Distance LEFT: ");
  //  Serial.println(distanceLEFT);
  //  myOLED.setFont(MediumNumbers);
  myOLED.clrScr();
  myOLED.printNumI(distance, CENTER, 10);
  myOLED.printNumI(distanceLEFT, LEFT, 40);
  myOLED.printNumI(distanceRIGHT, RIGHT, 40);
  myOLED.update();
  delay(70);
}
