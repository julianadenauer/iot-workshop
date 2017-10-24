#include <TM1637Display.h>     // Bibliothek für die Ansteuerung des Displays einbinden
int vibrationPin = D2;         // Der Vibrationsmotor ist an D2 angeschlossen
int counter = 0;               // In dieser Variablen wird gezählt, wie oft die Funktion schon
                               // aufgerufen wurde.

TM1637Display display(D1,D0);  // Das Display vom Typ TM1637Display wird initialisiert. Es ist mit
                               // den Pins D1 und D0 verbunden.

void setup() {
    pinMode(vibrationPin, OUTPUT);

    // Die Funktion triggerFunction unter dem Namen „trigger“ veröffentlichen
    Particle.function("trigger", triggerFunction);

    // Helligkeit des Displays auf Maximum setzen (15 bei diesem Modul)
    display.setBrightness(15);

    // Den aktuellen Counter Wert aufs Display schreiben. Der ist hier noch Null.
    display.showNumberDec(counter);
}

void loop() {
    // Weil wir alles eventbasiert in der triggerFunction erledigen, ist hier nichts zu tun.
}

// Diese Funktion kann über das Internet aufgerufen werden.
int triggerFunction(String command){
    // Den Vibrationsmotor kurz an- und wieder ausschalten.
    digitalWrite(vibrationPin, HIGH);
    delay(100);
    digitalWrite(vibrationPin, LOW);

    // Das Display aktualisieren
    counter++;                          // Den Counter um eins erhöhen.
    display.showNumberDec(counter);     // Die Anzeige des Displays entsprechend aktualisieren.

    // Wir geben den aktuellen Counter-Wert zurück. Er wird damit auch in der Cloud sichtbar sein.
    return counter;
}
