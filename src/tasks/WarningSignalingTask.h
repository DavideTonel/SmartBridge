#ifndef __WARNINGSIGNALINGTASK__
#define __WARNINGSIGNALINGTASK__

#include "AbstractTask.h"
#include "../hardware/ILight.h"

// non mi convince il come si usa il tempo quando in stato di PRE_ALARM
// rischio che passino più di 2 secondi
class WarningSignalingTask : public AbstractTask {
private:
    enum LightState {ON, OFF} state;
    ILight* light;

    // non lo so
    const int waitingOffTime = 2000;
    int lastSwitchTime;
    int actualTime;

public:
    WarningSignalingTask(const int pin);
    void init(const int taskPeriod);
    void tick();
};

#endif