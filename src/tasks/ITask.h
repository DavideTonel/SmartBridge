#ifndef __ITASK__
#define __ITASK__

class ITask {
public:
    virtual void init(const int taskPeriod) = 0;
    virtual void tick() = 0;
    virtual bool isToExecute(const int schedulerPeriod) = 0;
    virtual void setPeriod(const int taskPeriod) = 0;
};

#endif