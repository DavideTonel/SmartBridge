#include "SignalingTask.h"
#include "../hardware/Led.h"
#include "SystemInfo.h"

SignalingTask::SignalingTask(const int pin) {
    this->state = OFF;
    this->light = new Led(pin);
}

void SignalingTask::init(const int taskPeriod) {
    AbstractTask::init(taskPeriod);
}

void SignalingTask::tick() {
    SystemInfo* info = info->getInstance();
    SystemState systemState = info->getSystemState();

    switch (systemState) {
    case NORMAL:
        this->state = ON;
        this->light->switchOn();
        break;

    case PRE_ALARM:
        this->state = ON;
        this->light->switchOn();
        break;

    case ALARM:
        this->state = OFF;
        this->light->switchOff();
        break;
    
    default:
        break;
    }   
}
