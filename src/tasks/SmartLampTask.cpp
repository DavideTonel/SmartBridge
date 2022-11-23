#include <Arduino.h>
#include "SmartLampTask.h"
#include "../hardware/Led.h"
#include "../SystemInfo.h"

SmartLampTask::SmartLampTask(const int pin) {
    this->state = OFF;
    this->light = new Led(pin);
}

void SmartLampTask::init(const int taskPeriod) {
    AbstractTask::init(taskPeriod);
}

// [X] aggiornare singleton
//      --> non dovrebbe averne bisogno
void SmartLampTask::tick() {

    //Serial.println("SMARTLAMP STARTS");

    SystemInfo* info = info->getInstance();

    SystemState systemState = info->getSystemState();
    bool movementDetected = info->isMovementDetected();
    bool dark = info->isDark();

    // aggiungere MANUAL_CONTROL
    if (systemState == ALARM) {
        this->light->switchOff();
        this->state = OFF;
    } else {
        switch (this->state) {
        case OFF:
            if (movementDetected and dark) {
                this->light->switchOn();
                this->state = ON;
            }
            break;

        case ON:
            this->lastSwitchOnTime = millis();
            if (!dark) {
                this->light->switchOff();
                this->state = OFF;
            } else if (dark and !movementDetected) {
                this->state = WAITING_OFF;
            }
            break;

        case WAITING_OFF:
            if (dark and movementDetected) {
                this->state = ON;
            } else {
                this->actualTime = millis();
                bool isTimerExpired = this->actualTime - this->lastSwitchOnTime >= this->waitingOffTime;
                if (!dark or isTimerExpired) {
                    this->state = OFF;
                    this->light->switchOff();
                }
            }
            break;
    
        default:
            break;
        }
    }

    //Serial.println("SMARTLAMP STOPS");
}