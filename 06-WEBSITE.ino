#include <TM1637Display.h>    // Bibliothek für die Ansteuerung des Displays einbinden
int vibrationPin = D2;        // Der Vibrationsmotor ist an D2 angeschlossen
int lightSensorPin = A0;      // Lichtsensor an A0
int lightValue = 0;           // Variable für den aktuellen Helligkeitswert

TM1637Display display(D1,D0); // Das Display initialisieren

void setup() {
    pinMode(vibrationPin, OUTPUT);

    // Die Funktion triggerFunction unter dem Namen "trigger" veröffentlichen.
    Particle.function("trigger", triggerFunction);

    // Die Variable für den Helligkeitswert unter dem Namen "light" ebenfalls veröffentlichen.
    Particle.variable("light", lightValue);

    // Helligkeit des Displays auf Maximum setzen (15 bei diesem Modul)
    display.setBrightness(15);
}

void loop() {
    // Den aktuellen Messwert des Lichtsensors auslesen und auf das Display schreiben
    lightValue = analogRead(lightSensorPin);
    display.showNumberDec(lightValue);
}

// Diese Funktion kann über das Internet aufgerufen werden.
int triggerFunction(String command){
    // Den Vibrationsmotor kurz an- und wieder ausschalten.
    digitalWrite(vibrationPin, HIGH);
    delay(100);
    digitalWrite(vibrationPin, LOW);
}
