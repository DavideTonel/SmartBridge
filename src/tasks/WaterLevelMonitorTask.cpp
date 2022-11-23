#include "WaterLevelMonitorTask.h"
#include "../hardware/Sonar.h"
#include "SystemInfo.h"

const float upper_limit_alarm = 0.20;
const float upper_limit_pre_alarm = 0.40;
//const float upper_limit_normal = 0.20;

float WaterLevelMonitorTask::getWaterLevel() {
    return this->sonar->getDistance();
}

// [ ] cambiare periodo
SystemState WaterLevelMonitorTask::calculateSystemState(const float waterLevel) {
    if (waterLevel <= upper_limit_alarm) {
        //this->setPeriod();
        return ALARM;
    } else if (waterLevel <= upper_limit_pre_alarm) {
        //this->setPeriod();
        return PRE_ALARM;
    } else {
        //this->setPeriod();
        return NORMAL;
    }
}

WaterLevelMonitorTask::WaterLevelMonitorTask(const int trigPin, const int echoPin) {
    this->sonar = new Sonar(trigPin, echoPin);
}

void WaterLevelMonitorTask::init(const int taskPeriod) {
    AbstractTask::init(taskPeriod);
}

void WaterLevelMonitorTask::tick() {
    float waterLevel = this->getWaterLevel();
    SystemState newSystemState = this->calculateSystemState(waterLevel);

    SystemInfo* info = info->getInstance();
    info->setWaterLevel(waterLevel);
    info->setSystemState(newSystemState);
}