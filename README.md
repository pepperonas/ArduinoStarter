# Arduino Starter - IR & RF Empfänger Projekte

Dieses Repository enthält Arduino-Projekte zum Empfangen und Decodieren von Infrarot- (IR) und Radiofrequenz- (RF) Signalen.

## Projektübersicht

### 1. IR-RX (Infrarot-Empfänger)
Ein IR-Code Scanner für die Teufel Power HiFi Fernbedienung oder andere IR-Fernbedienungen.

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
Ein Empfänger für 433 MHz Funksignale, z.B. von Funksteckdosen oder Garagentoröffnern.

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

## Installation

### Benötigte Bibliotheken
- **IR-RX**: IRremote Library
- **RF-RX**: RCSwitch Library

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

## Fehlersuche

### IR-Empfänger
- **Keine Codes werden angezeigt**: Verkabelung prüfen, VS1838B-Orientierung kontrollieren
- **Falsche/zufällige Codes**: Störquellen entfernen, Abstand verringern, Batterien prüfen

### RF-Empfänger
- **Kein Empfang**: Interrupt-Pin prüfen (Pin 2), Antenne anschließen
- **Schwacher Empfang**: Bessere Antenne verwenden (17,3 cm für 433 MHz)

## Lizenz
Dieses Projekt steht unter der MIT-Lizenz.

## Beiträge
Beiträge sind willkommen! Bitte erstellen Sie einen Pull Request mit Ihren Verbesserungen.