const int ledPin = 12; 
bool isPatSignal = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  Particle.subscribe("buddyPhotonSignal", signalHandler);
}

void loop() {

}

void signalHandler(const char *event, const char *data) {
  if (strcmp(data, "pat") == 0) {
    isPatSignal = true;
  } else if (strcmp(data, "wave") == 0) {
    isPatSignal = false;
  }
}

void flashLED() {
  if (isPatSignal) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  } else {
 
    digitalWrite(ledPin, HIGH);
    delay(500); 
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}

