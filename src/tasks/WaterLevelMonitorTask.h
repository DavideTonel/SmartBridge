#ifndef __WATERLEVELMONITOR__
#define __WATERLEVELMONITOR__

#include "AbstractTask.h"
#include "SystemInfo.h"
#include "../hardware/ISonar.h"
#include "../hardware/IDisplay.h"

// get, display and use the servo on waterLevel
class WaterLevelMonitorTask : public AbstractTask {
private:
    ISonar* sonar;
    //IDisplay* display;

    float getWaterLevel();
    SystemState calculateSystemState(const float waterLevel);
    
    // metodo della classe LCD
    //void displayNumber(float value);

    // metodo della classe Servo
    //void calculateAngleValve(float value);

public:
    WaterLevelMonitorTask(const int trigPin, const int echoPin);
    void init(const int taskPeriod);
    void tick();
};

#endif