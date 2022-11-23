#ifndef __LIGHTSENSORTASK__
#define __LIGHTSENSORTASK__

#include "AbstractTask.h"
#include "../hardware/ILightSensor.h"

class LightSensorTask : public AbstractTask {
private:
    enum LightSensorState {DARK,LIGHT} state;
    ILightSensor* sensor;
    bool dark;

public:
    LightSensorTask(const int pin);

    void tick();

    void init(const int taskPeriod);

    bool isDark();
};

#endif