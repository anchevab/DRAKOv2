/*
   RedRobot DRAKO v2 DHT22 on 0.97 128x64 SSD1306 OLED display
   Byala Robots Club
   Author: eng.A.Anchev
   february, 2018
*/

#include <OLED_I2C.h>
#include "DHT.h"
#define DHTPIN 4                                          // DHT22 сензор на цифров пин 4
#define DHTTYPE DHT22                                     // сензор DHT22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);
OLED  myOLED(SDA, SCL);

extern uint8_t SmallFont[];

// =============== SETUP ===================
void setup()
{
  Serial.begin(9600);
  if (!myOLED.begin(SSD1306_128X64))
    while (1);                                           // В случай,че библиотеката не успее да задели достатъчно RAM за буфера на дисплея
  myOLED.setFont(SmallFont);
  dht.begin();
}

// ============== LOOP ===================
void loop()
{
  float h = dht.readHumidity();                          // прочитане на стойността на влажността
  float t = dht.readTemperature();                       //прочитане на стойността на темп в Целзий
  float hic = dht.computeHeatIndex(t, h, false);
  myOLED.clrScr();
  myOLED.print("Temperature = ", LEFT, 0);               // print(Текст, позиция по X, позиция по Y);      - X - позиция на символа в реда , Y - номер на ред
  myOLED.printNumF(t, 2 , 85, 0);                        // printNumF( стойност, брой знаци за дробна част, позиция по X, позиция по Y);
  myOLED.print("Humidity = ", LEFT, 15);
  myOLED.printNumF(h, 2, 70, 15);
  myOLED.print("Hic = ", LEFT, 30);
  myOLED.printNumF(hic, 2 , 40, 30);
  myOLED.update();
  delay(500);
}


