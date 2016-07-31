/**
 * 
 */

#include "Particle.h"

int ledPin = D7; // Instead of writing D7 over and over again, we'll write led2

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
