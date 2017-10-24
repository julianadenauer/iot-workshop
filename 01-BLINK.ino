int ledPin = D7;  // In der Variablen led_pin wird der Name des Pins gespeichert, an dem die
		 // interne LED hängt: D7.

// Die Setup Funktion wird einmal aufgerufen, wenn der Photon startet. Also wenn er wieder mit
// Strom versorgt wird oder der Reset Button gedrückt wurde.
// Wir benutzen die Funktion deshalb hauptsächlich für Initialisierungen.
void setup() {
    pinMode(ledPin, OUTPUT);   // Wir legen fest, dass wir den Pin als Output benutzen wollen.
}

// Die loop Funktion wird ständig in einer Schleife ausgeführt.
// Hier kommt deshalb aller Code hinein, der wiederholt ausgeführt werden soll.
void loop() {
    digitalWrite(ledPin, HIGH); // Wir schalten die LED an, indem wir den Pin auf HIGH setzen.
    delay(1000);                // Warten für 1000 Millisekunden, also eine Sekunde.
    digitalWrite(ledPin, LOW);  // Die LED wird wieder ausgeschaltet.
    delay(1000);                // Bevor der loop wieder von vorne beginnt und die LED wieder
			      // angeschaltet wird, warten wir nochmal 1 Sekunde.
}
