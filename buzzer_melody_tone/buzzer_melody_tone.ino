/*
  Melody with buzzer
  8-ohm speaker on digital pin 8
*/
#include "pitches.h"                // файл с нотите
#define buzzer_pin 6
// ---------- ноти в мелодията в масив
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
// ---------- дължина на нотите -> 4 = четвъртина нота, 8 = осмина нота, и т.н.
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

// ========================== SETUP ===============================
void setup() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // ------------- изчисляване на нотите -> четвъртина нота = 1000 / 4, осмина нота = 1000/8 , и т.н..
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer_pin, melody[thisNote], noteDuration);
    digitalWrite(8, HIGH);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer_pin);                    // спиране на тоновете
  }
}

void loop() {

}
