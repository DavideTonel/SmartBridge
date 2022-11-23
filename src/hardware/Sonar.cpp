#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar(const int trigPin, const int echoPin) {
    //..
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float Sonar::getDistance() {
    /* sending impulse */
    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);

    /* receiving the eco */
    float tUS = pulseIn(echoPin, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    float distance = t * vs;
    return distance;
}
