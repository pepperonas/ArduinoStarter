// HC-SR04 Ultraschall Entfernungsmesser
// Pins definieren
const int TRIG_PIN = 9;  // Trigger Pin
const int ECHO_PIN = 10; // Echo Pin

// Variablen
long duration;     // Zeit für Echo-Signal
float distance_cm; // Entfernung in cm
float distance_m;  // Entfernung in m

void setup() {
  // Serielle Kommunikation starten
  Serial.begin(9600);
  
  // Pin Modi setzen
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.println("HC-SR04 Entfernungsmesser gestartet");
  Serial.println("--------------------------------");
}

void loop() {
  // Trigger Pin zurücksetzen
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // 10µs Puls am Trigger Pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Echo-Signal Dauer messen
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Entfernung berechnen
  // Schallgeschwindigkeit: 343 m/s = 0.0343 cm/µs
  // Hin und zurück, daher durch 2
  distance_cm = duration * 0.0343 / 2;
  distance_m = distance_cm / 100;
  
  // Ausgabe nur bei gültigen Werten (2cm - 400cm)
  if (distance_cm >= 2 && distance_cm <= 400) {
    Serial.print("Entfernung: ");
    Serial.print(distance_cm);
    Serial.print(" cm (");
    Serial.print(distance_m, 2);
    Serial.println(" m)");
  } else {
    Serial.println("Außerhalb des Messbereichs!");
  }
  
  // Kurze Pause zwischen Messungen
  delay(500);
}

// Optionale Funktion für präzisere Messungen
float getAverageDistance(int samples = 5) {
  float sum = 0;
  int validReadings = 0;
  
  for (int i = 0; i < samples; i++) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    long dur = pulseIn(ECHO_PIN, HIGH);
    float dist = dur * 0.0343 / 2;
    
    if (dist >= 2 && dist <= 400) {
      sum += dist;
      validReadings++;
    }
    
    delay(50); // Kurze Pause zwischen Messungen
  }
  
  if (validReadings > 0) {
    return sum / validReadings;
  }
  return -1; // Fehler
}