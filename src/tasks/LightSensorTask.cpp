#include <Arduino.h>
#include "LightSensorTask.h"
#include "../hardware/Photoresistor.h"
#include "SystemInfo.h"

LightSensorTask::LightSensorTask(const int pin) {
    this->state = LIGHT;
    this->sensor = new Photoresistor(pin);
    this->dark = false;
}

// [X] aggiornare singleton
void LightSensorTask::tick() {

    //Serial.println("LIGHTSENSOR STARTS");

    //Serial.print("LightSensorTask start         ");
    bool darkDetection = this->sensor->isDark();

    switch (this->state) {
    case LIGHT:
        if (darkDetection) {
            this->dark = true;
            this->state = DARK;
        }
        break;
    
    case DARK:
        if (!darkDetection) {
            this->dark = false;
            this->state = LIGHT;
        }
        break;

    default:
        break;
    }
    //SystemInfo::getInstance()->setDark(this->dark);
    SystemInfo* info = info->getInstance();
    info->setDark(this->dark);

    //Serial.println(darkDetection);
    //Serial.println(info->isDark());
    //Serial.flush();
    //Serial.println("LIGHTSENSOR STOPS");
}

void LightSensorTask::init(const int taskPeriod) {
    AbstractTask::init(taskPeriod);
}

bool LightSensorTask::isDark() {
    return this->dark;
}