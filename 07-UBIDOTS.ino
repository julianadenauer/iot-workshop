#include <Ubidots.h> // Die Ubidots Bibliothek einbinden
#include <math.h>    // Standard-Mathematik Bibliothek einbinden

Ubidots ubidots(„UBIDOTS_TOKEN“); // hier muss das Ubidots Access Token eingefügt werden

int temperaturePin = A0; // Der Temperatursensor ist an A0 angeschlossen

void setup() {
    pinMode(temperaturePin, INPUT);
}

void loop() {
    // Temperatursensor analog auslesen
    int a=analogRead(temperaturePin);

    // Ein bisschen magischer Code, der den ausgelesenen Wert in eine Temperatur wandelt
    float widerstand = (4096.0/a-1.0);
    float temperature = 1.0/(log(widerstand)/4275+1/298.15)-273.15;

    // Die berechnete Temperatur nun an Ubidots senden
    ubidots.add(„temperature“, temperature); // zum Paket hinzufügen
    ubidots.sendAll();                       // und wegschicken

    // Anschießend 5 Sekunden warten
    delay(5000);
}
