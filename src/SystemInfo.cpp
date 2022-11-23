#include "SystemInfo.h"

// brutto?
SystemInfo* SystemInfo::instance = 0;

SystemInfo::SystemInfo() {
    this->waterLevel = 0;
    this->systemState = NORMAL;
    // ricordare di mettere a false
    this->movementDetected = false;
    this->dark = false;
}

SystemInfo* SystemInfo::getInstance() {
    if (instance == 0) {
        instance = new SystemInfo();
    }
    return instance;
}

float SystemInfo::getWaterLevel() {
    return this->waterLevel;
}

SystemState SystemInfo::getSystemState() {
    return this->systemState;
}

void SystemInfo::setWaterLevel(const float value) {
    this->waterLevel = value;
}

void SystemInfo::setSystemState(const SystemState state) {
    this->systemState = state;
}



// non lo so
void SystemInfo::setMovementDetected(bool value) {
    this->movementDetected = value;
}
void SystemInfo::setDark(bool value) {
    this->dark = value;
}
bool SystemInfo::isMovementDetected() {
    return this->movementDetected;
}
bool SystemInfo::isDark() {
    return this->dark;
}

