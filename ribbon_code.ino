#define RIBBON_PIN A0
#define FORCE_PIN A1
#define SPEAKER_PIN A2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(analogRead(FORCE_PIN));
  // delay(100);

  if (analogRead(RIBBON_PIN) > 980) {
    tone(SPEAKER_PIN, 131); // C3
  }
  else if (analogRead(RIBBON_PIN) > 938) {
    tone(SPEAKER_PIN, 139); // Csharp3
  }
  else if (analogRead(RIBBON_PIN) > 895) {
    tone(SPEAKER_PIN, 147); // D3
  }
  else if (analogRead(RIBBON_PIN) > 852) {
    tone(SPEAKER_PIN, 156); // D#3
  }
  else if (analogRead(RIBBON_PIN) > 810) {
    tone(SPEAKER_PIN, 165); // E3
  }
  else if (analogRead(RIBBON_PIN) > 767) {
    tone(SPEAKER_PIN, 175); // F3
  }
  else if (analogRead(RIBBON_PIN) > 724) {
    tone(SPEAKER_PIN, 185); // F#3
  }
  else if (analogRead(RIBBON_PIN) > 682) {
    tone(SPEAKER_PIN, 196); // G3
  }
  else if (analogRead(RIBBON_PIN) > 639) {
    tone(SPEAKER_PIN, 208); // G#3
  }
  else if (analogRead(RIBBON_PIN) > 596) {
    tone(SPEAKER_PIN, 220); // A3
  }
  else if (analogRead(RIBBON_PIN) > 554) {
    tone(SPEAKER_PIN, 233); // A#3
  }
  else if (analogRead(RIBBON_PIN) > 511) {
    tone(SPEAKER_PIN, 247); // B3
  }
  else if (analogRead(RIBBON_PIN) > 468) {
    tone(SPEAKER_PIN, 262); // C4
  }
  else if (analogRead(RIBBON_PIN) > 426) {
    tone(SPEAKER_PIN, 277); // C#4
  }
  else if (analogRead(RIBBON_PIN) > 383) {
    tone(SPEAKER_PIN, 294); // D4
  }
  else if (analogRead(RIBBON_PIN) > 340) {
    tone(SPEAKER_PIN, 311); // D#4
  }
  else if (analogRead(RIBBON_PIN) > 298) {
    tone(SPEAKER_PIN, 330); // E4
  }
  else if (analogRead(RIBBON_PIN) > 255) {
    tone(SPEAKER_PIN, 349); // F4
  }
  else if (analogRead(RIBBON_PIN) > 212) {
    tone(SPEAKER_PIN, 370); // F#4
  }
  else if (analogRead(RIBBON_PIN) > 170) {
    tone(SPEAKER_PIN, 392); // G4
  }
  else if (analogRead(RIBBON_PIN) > 127) {
    tone(SPEAKER_PIN, 415); // G#4
  }
  else if (analogRead(RIBBON_PIN) > 84) {
    tone(SPEAKER_PIN, 440); // A4
  }
  else if (analogRead(RIBBON_PIN) > 43) {
    tone(SPEAKER_PIN, 466); // A#4
  }
  else if (analogRead(RIBBON_PIN) > 0) {
    tone(SPEAKER_PIN, 494); // B4
  }    
  else {
    noTone(SPEAKER_PIN);
  }
  
}
