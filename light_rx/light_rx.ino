/*
  LDR-Schaltung (Spannungsteiler):

           +5V
            |
           [LDR]
            |
            |----------> A0 (Arduino)
            |
         [10kΩ Widerstand]
            |
           GND

  - Ein Ende des LDR an +5V
  - Das andere Ende des LDR geht an:
      - einen analogen Eingang (z. B. A0)
      - UND an einen 10kΩ-Widerstand
  - Das andere Ende des 10kΩ-Widerstands geht an GND

  Funktion:
  - Der LDR und der Widerstand bilden einen Spannungsteiler.
  - Je nach Lichtstärke fällt an A0 eine andere Spannung an.
  - Diese wird mit analogRead() gemessen (0 = dunkel, 1023 = sehr hell).
*/

// Pin-Definition
const int ldrPin = A0;         // LDR an analogem Pin A0
const int threshold = 50;      // Schwellenwert für Helligkeitserkennung

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // LDR-Wert auslesen

  Serial.print("LDR-Wert: ");
  Serial.println(ldrValue);

  if (ldrValue < threshold) {
    Serial.println("Dunkel erkannt");
  } else {
    Serial.println("Hell erkannt");
  }

  delay(1000);  // 1 Sekunde warten
}
