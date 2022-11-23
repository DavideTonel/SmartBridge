#ifndef __MOVEMENTDETECTIONTASK__
#define __MOVEMENTDETECTIONTASK__

#include "AbstractTask.h"
#include "../hardware/IPir.h"

class MovementDetectionTask : public AbstractTask {
private:
    enum DetectionState {NO_MOVEMENT, POSSIBLE_MOVEMENT, DETECTED} state;
    IPir* pir;
    bool movementDetected;

public:
    MovementDetectionTask(const int pin);

    void tick();

    void init(const int taskPeriod);

    bool isMovementDetected();
};

#endif