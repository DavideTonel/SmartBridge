#include <Arduino.h>
#include "AbstractTask.h"
#include "SystemInfo.h"

class PrintInfo : public AbstractTask {
public:
    void init(const int taskPeriod) {
        AbstractTask::init(taskPeriod);
    }
    
    void tick() {
        SystemInfo* info = info->getInstance();
        Serial.print("Dark: ");
        Serial.println(info->isDark());
        Serial.print("Movement: ");
        Serial.println(info->isMovementDetected());
        Serial.print("SystemState: ");
        Serial.println(info->getSystemState());
    }

};