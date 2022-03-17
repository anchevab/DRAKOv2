/*
   RedRobot DRAKO piezo melody and button
   Author eng.A.Anchev
   Byala, 2019
*/
int speakerPin = 6;
const int buttonPin = 12;
int buttonState = 0;

int length = 15;                           // ----- the number of notes
char notes[] = "ccggaagffeeddc ";          // ----- a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

// ---------- Play tone ------------
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

// ----------- Play note -----------
void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // ----- play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

// ============ SETUP ================
void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// ============ LOOP =================
void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    playNote(notes[2], 200);      // play tone
  }
}
