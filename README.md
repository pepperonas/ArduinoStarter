# Arduino Starter - Sensor Projekte

Dieses Repository enthält verschiedene Arduino-Projekte für Sensoren und Empfänger, einschließlich Infrarot (IR), Radiofrequenz (RF), Lichtsensor (LDR) und Ultraschall-Entfernungsmessung.

## Projektübersicht

### 1. IR-RX (Infrarot-Empfänger)
Ein universeller IR-Code Scanner für beliebige IR-Fernbedienungen.

**Features:**
- Empfängt und decodiert IR-Signale von beliebigen Fernbedienungen
- Zeigt Protokoll, Adresse und Command-Code im Serial Monitor an
- Unterstützt verschiedene IR-Protokolle

**Hardware:**
- Arduino Uno/Nano
- VS1838B IR-Empfänger (an Pin 2)
- Keine zusätzlichen Bauteile erforderlich

**Verwendung:**
1. Schaltung gemäß dem Schaltplan im Code aufbauen
2. Code auf Arduino hochladen
3. Serial Monitor öffnen (9600 Baud)
4. Fernbedienung auf den Empfänger richten und Tasten drücken
5. Codes notieren für spätere Verwendung

### 2. RF-RX (433 MHz Funkempfänger)
Ein universeller Empfänger für 433 MHz Funksignale verschiedener Geräte.

**Features:**
- Empfängt 433 MHz Funksignale
- Zeigt empfangene Werte, Bitlänge und Protokoll an
- Basiert auf der RCSwitch-Bibliothek

**Hardware:**
- Arduino (getestet mit Mega, Pin 2)
- 433 MHz Empfängermodul
- Verkabelung gemäß Standard-Pinout

**Verwendung:**
1. RCSwitch-Bibliothek installieren
2. 433 MHz Empfänger anschließen
3. Code hochladen
4. Serial Monitor öffnen (9600 Baud)
5. Funksender betätigen und Codes ablesen

### 3. Light-RX (Lichtsensor / LDR)
Ein Lichtsensor zur Messung von Umgebungslicht und Helligkeitsänderungen.

**Features:**
- Misst Lichtstärke mit einem LDR (Light Dependent Resistor)
- Erkennt Helligkeitsänderungen und Lichtzustände
- Einstellbarer Schwellenwert für Lichtdetektion
- Analogwerte von 0 (dunkel) bis 1023 (sehr hell)

**Hardware:**
- Arduino Uno/Nano
- LDR (Fotowiderstand)
- 10kΩ Widerstand
- Anschluss an Pin A0

**Verwendung:**
1. Spannungsteiler-Schaltung mit LDR und 10kΩ Widerstand aufbauen
2. Code auf Arduino hochladen
3. Serial Monitor öffnen (9600 Baud)
4. Lichtwerte beobachten und Schwellenwert anpassen

### 4. Ultrasonic (HC-SR04 Entfernungsmesser)
Ein Ultraschall-Entfernungsmesser für präzise Abstandsmessungen.

**Features:**
- Misst Entfernungen von 2cm bis 400cm
- Ausgabe in cm und m
- Optionale Durchschnittsmessung für höhere Genauigkeit
- Basiert auf Schallgeschwindigkeit (343 m/s)

**Hardware:**
- Arduino Uno/Nano
- HC-SR04 Ultraschallsensor
- Trigger Pin: Pin 9
- Echo Pin: Pin 10

**Verwendung:**
1. HC-SR04 gemäß Pinbelegung anschließen
2. Code auf Arduino hochladen
3. Serial Monitor öffnen (9600 Baud)
4. Entfernungsmessungen ablesen

## Installation

### Benötigte Bibliotheken
- **IR-RX**: IRremote Library
- **RF-RX**: RCSwitch Library
- **Light-RX**: Keine zusätzlichen Bibliotheken erforderlich
- **Ultrasonic**: Keine zusätzlichen Bibliotheken erforderlich

Bibliotheken können über den Arduino Library Manager installiert werden:
1. Arduino IDE öffnen
2. Werkzeuge → Bibliotheken verwalten
3. Nach "IRremote" bzw. "RCSwitch" suchen
4. Installieren

## Schaltpläne

### VS1838B IR-Empfänger Anschluss
```
    Arduino             VS1838B
  ╔═════════╗         ╔═══════╗
  ║      5V ╟─────────╢ VCC   ║
  ║     GND ╟─────────╢ GND   ║
  ║   Pin 2 ╟─────────╢ OUT   ║
  ╚═════════╝         ╚═══════╝
```

### VS1838B Pinbelegung (Frontansicht)
```
     ╭─────╮
     │ ╱╲  │  <- Empfänger-Linse
     │╱  ╲ │
     ╰─────╯
      │ │ │
      1 2 3

Pin 1: OUT (Signal)
Pin 2: GND (Minus)
Pin 3: VCC (Plus)
```

### LDR Spannungsteiler-Schaltung
```
    Arduino              Schaltung
  ╔═════════╗          
  ║      5V ╟──────────┬─[LDR]─┐
  ║         ║          │       │
  ║      A0 ╟──────────┼───────┤
  ║         ║          │       │
  ║     GND ╟──────────┴─[10kΩ]┘
  ╚═════════╝
```

### HC-SR04 Ultraschallsensor Anschluss
```
    Arduino            HC-SR04
  ╔═════════╗        ╔════════╗
  ║      5V ╟────────╢ VCC    ║
  ║     GND ╟────────╢ GND    ║
  ║   Pin 9 ╟────────╢ Trig   ║
  ║  Pin 10 ╟────────╢ Echo   ║
  ╚═════════╝        ╚════════╝
```

## Fehlersuche

### IR-Empfänger
- **Keine Codes werden angezeigt**: Verkabelung prüfen, VS1838B-Orientierung kontrollieren
- **Falsche/zufällige Codes**: Störquellen entfernen, Abstand verringern, Batterien prüfen

### RF-Empfänger
- **Kein Empfang**: Interrupt-Pin prüfen (Pin 2), Antenne anschließen
- **Schwacher Empfang**: Bessere Antenne verwenden (17,3 cm für 433 MHz)

### Lichtsensor (LDR)
- **Keine/falsche Werte**: Spannungsteiler-Schaltung prüfen, LDR-Orientierung egal
- **Schwellenwert anpassen**: Je nach Umgebungslicht threshold-Variable im Code ändern

### Ultraschallsensor
- **Keine Messungen**: Verkabelung prüfen, Trig/Echo-Pins vertauscht?
- **Ungenaue Werte**: Sensor senkrecht zum Objekt ausrichten, glatte Oberflächen verwenden
- **"Außerhalb des Messbereichs"**: Objekt zu nah (<2cm) oder zu weit (>400cm)

## Entwickler
Martin Pfeffer, 2025

## Lizenz
Dieses Projekt steht unter der MIT-Lizenz.

## Beiträge
Beiträge sind willkommen! Bitte erstellen Sie einen Pull Request mit Ihren Verbesserungen.