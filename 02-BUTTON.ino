int ledPin = D7;
int buttonPin = D2;	     // Der Button wird an den Anschluss D2 angeschlossen.

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT); // Der Pin, an den der Button angeschlossen ist, soll als Input
			     // verwendet werden.
}

void loop() {
    // Lese den Status des Buttons aus und schreibe den Zustand in eine Variable
    bool buttonIsPressed = digitalRead(buttonPin);

    if(buttonIsPressed){
        digitalWrite(ledPin, HIGH); // LED anschalten
        // Sende eine Nachricht an die Cloud Console, dass der Button gedrückt wurde.
        Particle.publish("awesome-button-pressed");
        delay(1000);  // warte eine sekunde, bevor wir weitermachen
    } else {
        digitalWrite(ledPin, LOW); // LED ausschalten, wenn der Button nicht gedrückt ist.
    }
}
