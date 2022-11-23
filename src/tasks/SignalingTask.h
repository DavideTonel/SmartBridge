#ifndef __SIGNALINGTASK__
#define __SIGNALINGTASK__

#include "AbstractTask.h"
#include "../hardware/ILight.h"

class SignalingTask : public AbstractTask {
private:
    enum LightState {ON, OFF} state;
    ILight* light;

public:
    SignalingTask(const int pin);
    void init(const int taskPeriod);
    void tick();
};

#endif