#include <Arduino.h>
#include "Pir.h"

#define CALIBRATION_SEC 10

Pir::Pir(const int pin) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

void Pir::calibrate() {
    Serial.println("Calibrating pin...");
    for (int i = 0; i < CALIBRATION_SEC; i++) {
        Serial.println(".");
        delay(1000);
    }
    Serial.println("Pir sensor ready!");
}

bool Pir::isDetection() {
    int detection = digitalRead(this->pin);
    //Serial.println(detection);
    if (detection == HIGH) {
        return true;
    }
    return false;
}