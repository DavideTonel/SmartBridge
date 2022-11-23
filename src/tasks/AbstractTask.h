#ifndef __ABSTRACTTASK__
#define __ABSTRACTTASK__

#include "ITask.h"

class AbstractTask : public ITask {
private:
    int taskPeriod;
    int timeElapsed;
    
public:
    virtual void init(const int taskPeriod) {
        this->taskPeriod = taskPeriod;
        this->timeElapsed = 0;
    }

    virtual void tick() = 0;

    bool isToExecute(const int schedulerPeriod) {
        this->timeElapsed += schedulerPeriod;
        if (this->timeElapsed >= this->taskPeriod) {
            this->timeElapsed = 0;
            return true;
        }
        return false;
    }

    void setPeriod(const int taskPeriod) {
        this->taskPeriod = taskPeriod;
    }
};

#endif