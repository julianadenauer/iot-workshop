int ledPin = D7;

void setup() {
    pinMode(ledPin, OUTPUT);
    Particle.subscribe("awesome-button-pressed", eventHandler); // das Event abonnieren
}

void loop() {
    // hier gibt es nichts zu tun
}

// diese Funktion wird aufgerufen, wenn der andere Photon das Event auslöst
void eventHandler(const char *event, const char *data){
    digitalWrite(ledPin, HIGH); // LED anschalten
    delay(1000);                // kurz warten
    digitalWrite(ledPin, LOW);  // LED ausschalten
}
