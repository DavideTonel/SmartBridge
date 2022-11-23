#ifndef __SMARTLAMPTASK__
#define __SMARTLAMPTASK__

#include "AbstractTask.h"
#include "../hardware/ILight.h"

class SmartLampTask : public AbstractTask {
private:
    enum LightState {OFF, ON, WAITING_OFF} state;
    ILight* light;

    // non lo so
    const int waitingOffTime = 10000;
    int lastSwitchOnTime;
    int actualTime;

public:

    SmartLampTask(const int pin);

    // taskPeriod forse dovrebbe essere lo stesso del pir
    void init(const int taskPeriod);

    void tick();

};

#endif