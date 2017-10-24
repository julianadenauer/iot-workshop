int externalLedPin = D2; // Die externe LED hängt an D2
int potiPin = A0;        // Das Potentiometer ist am analogen Input A0 angeschlossen
int potiValue = 0;       // Variable, die den aktuellen Wert des Potentiometers enthält

void setup() {
    pinMode(externalLedPin, OUTPUT);
    pinMode(potiPin, INPUT);

    Particle.variable("poti", potiValue);  // Veröffentlichung der Variablen unter dem Namen
					// „poti“ in der Cloud
}

void loop() {
    // Lese die Position des Potentiometers analog aus und speichere die Zahl zwischen 0 und 4095
    // in der Variablen. Das Updaten in der cloud wird automatisch erledigt.
    potiValue = analogRead(potiPin);

    // Dimme die LED entsprechend des Poti-Werts. Wir müssen den Wert durch 16 teilen, weil die
    // Funktion eine Zahl zwischen 0 und 255 erwartet.
    analogWrite(externalLedPin, potiValue / 16);
}
