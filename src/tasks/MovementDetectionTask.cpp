#include <Arduino.h>
#include "MovementDetectionTask.h"
#include "../hardware/Pir.h"
#include "SystemInfo.h"

MovementDetectionTask::MovementDetectionTask(const int pin) { 
    this->state = NO_MOVEMENT;
    this->pir = new Pir(pin);
    this->movementDetected = false;
}

// [X] aggiornare singleton
void MovementDetectionTask::tick() {
    bool detection = this->pir->isDetection();

    //Serial.println("DETECTION STARTS");

    //Serial.print("Detection:   ");
    //Serial.println(detection);
    //Serial.flush();

    switch (this->state) {
    case NO_MOVEMENT:
        this->movementDetected = false;
        if (detection == true) {
            this->state = POSSIBLE_MOVEMENT;
        }
        break;

    case POSSIBLE_MOVEMENT:
        if (detection == true) {
            this->state = DETECTED;
        } else {
            this->state = NO_MOVEMENT;
        }
        break;

    case DETECTED:
        this->movementDetected = true;
        if (detection == false) {
            this->state = NO_MOVEMENT;
        }
        break;
    
    default:
        break;
    }

    //SystemInfo::getInstance()->setMovementDetected(this->movementDetected);
    SystemInfo* info = info->getInstance();
    info->setMovementDetected(this->movementDetected);

    //Serial.println(detection);
    //Serial.println(info->isMovementDetected());

    //Serial.println("DETECTION STOPS");
}

void MovementDetectionTask::init(const int taskPeriod) {
    AbstractTask::init(taskPeriod);
    this->pir->calibrate();
}

bool MovementDetectionTask::isMovementDetected() {
    return this->movementDetected;
}