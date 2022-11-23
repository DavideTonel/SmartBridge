#include <Arduino.h>
#include "Photoresistor.h"

Photoresistor::Photoresistor(const int pin) {
    pinMode(pin, INPUT);
}

void Photoresistor::setThreshold(const int threshold) {
    this->threshold = threshold;
}

bool Photoresistor::isDark() {
    //Serial.println(analogRead(this->pin));
    if (analogRead(this->pin) < this->threshold) {
        return true;
    }
    return false;
}