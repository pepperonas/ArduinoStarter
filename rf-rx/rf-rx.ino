#include <RCSwitch.h> // Bibliothek für 433-MHz-Signalverarbeitung

RCSwitch mySwitch = RCSwitch(); // RCSwitch-Objekt erstellen

void setup() {
  Serial.begin(9600); // Seriellen Monitor mit 9600 Baud starten
  mySwitch.enableReceive(0); // Empfänger auf Interrupt 0 aktivieren (Pin 2 auf Arduino Mega)
  Serial.println("Empfänger bereit. Drücke die Tasten der Fernbedienung..."); // Startmeldung
}

void loop() {
  if (mySwitch.available()) { // Prüfen, ob ein Signal empfangen wurde
    // Ausgabe der empfangenen Daten
    Serial.print("Empfangen: ");
    Serial.print(mySwitch.getReceivedValue()); // Dezimalwert des Signals
    Serial.print(" / ");
    Serial.print(mySwitch.getReceivedBitlength()); // Bitlänge des Signals
    Serial.print("bit ");
    Serial.print("Protokoll: ");
    Serial.println(mySwitch.getReceivedProtocol()); // Protokolltyp
    mySwitch.resetAvailable(); // Empfänger für nächstes Signal zurücksetzen
  }
}