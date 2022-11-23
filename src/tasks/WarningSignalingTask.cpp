#include <Arduino.h>
#include "WarningSignalingTask.h"
#include "../hardware/Led.h"
#include "SystemInfo.h"

WarningSignalingTask::WarningSignalingTask(const int pin) {
    this->state = OFF;
    this->light = new Led(pin);

    
    this->lastSwitchTime = 0;
    this->actualTime = 0;
}

void WarningSignalingTask::init(const int taskPeriod) {
    AbstractTask::init(taskPeriod);
}

void WarningSignalingTask::tick() {
    SystemInfo* info = info->getInstance();
    SystemState systemState = info->getSystemState();

    Serial.print(systemState);
    if (systemState == NORMAL) {
        Serial.println("NORMAL");
    } else if (systemState == PRE_ALARM) {
        Serial.println("PRE_ALARM");
    } else if (systemState == ALARM) {
        Serial.println("ALARM");
    }
    Serial.flush();

    switch (systemState) {
    case NORMAL:
        this->state = OFF;
        this->light->switchOff();
        
        // non lo so
        this->lastSwitchTime = millis();
        break;

    case PRE_ALARM:
        this->actualTime = millis();
        bool isTimerExpired = this->actualTime - this->lastSwitchTime >= this->waitingOffTime;
        if (isTimerExpired) {
            if (this->state == OFF) {
                this->state = ON;
                this->light->switchOn();
            } else if (this->state == ON) {
                this->state = OFF;
                this->light->switchOff();
            }
            // non lo so
            this->lastSwitchTime = millis();
        }
        break;

    // va solo se sopra da un altro case
    case ALARM:
        //Serial.println("qui");
        this->state = ON;
        this->light->switchOn();

        // non lo so
        this->lastSwitchTime = millis();
        break;
    
    default:
        break;
    }   
}
